#ifdef TESTING
#include <iostream>
#endif
#include "ShipMap.h"

ShipMap::ShipMap(){
    ShipMap(1,1,1);
}

ShipMap::ShipMap(int O, int N, int M){
    initialize(O,N,M);
}

void ShipMap::initialize(int O, int N, int M){
    this->O = O;
    this->N = N;
    this->M = M;
    containerMap = Matrix3D(O,N,M);
    containerMapFloor = Matrix3D(O,N,M);
    containerMapWallsEast = Matrix3D(O,N,M);
    containerMapWallsNorth = Matrix3D(O,N,M);
    containerMapAccess = Matrix3D(O,N,M);
    containerMapRooms = Matrix3D(O,N,M);

    map = containerMap.getMatrix();
    mapFloor = containerMapFloor.getMatrix();
    mapWallsEast = containerMapWallsEast.getMatrix();
    mapWallsNorth = containerMapWallsNorth.getMatrix();
    mapAccess = containerMapAccess.getMatrix();
    mapRooms = containerMapAccess.getMatrix();
    cntRooms = 0;
    cntObjects = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = NULL;
    }

    pathfinder = Pathfinder(containerMapAccess);
    //TODO: Probably should do this elsewhere.
    blocks::properties::initArrays();
}

Path* ShipMap::getPathToRoom(int UID, Location start){
    Location goal = rooms[UID]->center;
    return pathfinder.findPath(start, goal);
}

inline void ShipMap::simplifyLocations(Location& loc1, Location& loc2){
    // Make all coordinates of loc1 less than loc2.
    int tmp;
    if (loc1.x > loc2.x) {
        tmp = loc2.x;
        loc2.x = loc1.x;
        loc1.x = tmp;
    }
    if (loc1.y > loc2.y) {
        tmp = loc2.y;
        loc2.y = loc1.y;
        loc1.y = tmp;
    }
    if (loc1.z > loc2.z) {
        tmp = loc2.z;
        loc2.z = loc1.z;
        loc1.z = tmp;
    }
}

void ShipMap::insertWallVertical(int blockID, Location start, Location end){
    using namespace blocks;
    using namespace blocks::properties;
    if (slots[blockID] != WALL) return;
    int z = start.z;
    int x = start.x;
    simplifyLocations(start,end);
    for (int y = start.y; y < end.y; y++) {
        if (mapWallsEast[z][y][x] != 0) continue;
        mapWallsEast[z][y][x] = blockID;
    }
}

void ShipMap::insertWallHorizontal(int blockID, Location start, Location end){
    using namespace blocks;
    using namespace blocks::properties;
    if (slots[blockID] != WALL) return;
    int z = start.z;
    int y = start.y;
    simplifyLocations(start,end);
    for (int x = start.x; x < end.x; x++) {
        if (mapWallsNorth[z][y][x] != 0) continue;
        mapWallsNorth[z][y][x] = blockID;
    }
}

void ShipMap::insertBlocksFloor(int blockID, Location start, Location end){
    using namespace blocks;
    using namespace blocks::properties;
    if (slots[blockID] != FLOOR) return;
    simplifyLocations(start,end);
    for (int z = start.z; z < end.z; z++) {
        for (int y = start.y; y < end.y; y++) {
            for (int x = start.x; x < end.x; x++) {
                if (map[z][y][x] != 0) continue;
                map[z][y][x] = blockID;
            }
        }
    }
}

void ShipMap::insertBlocksCenter(int blockID, Location start, Location end){
    using namespace blocks;
    using namespace blocks::properties;
    if (slots[blockID] != CENTER) return;
    simplifyLocations(start,end);
    for (int z = start.z; z < end.z; z++) {
        for (int y = start.y; y < end.y; y++) {
            for (int x = start.x; x < end.x; x++) {
                if (map[z][y][x] != 0) continue;
                if (map[z][y][x] != CENTER_AIR) continue;
                map[z][y][x] = blockID;
            }
        }
    }
}

Room* ShipMap::createRoom(Location* locations, int N, int roomID){
    if (cntRooms == MAX_ROOMS) return NULL;
    if (locations == NULL) return NULL;
    cntRooms++;
    int x, y, z;
    for (int i = 0; i < N; i++) {
        x = locations[i].x;
        y = locations[i].y;
        z = locations[i].z;
        /* std::cout << "x : " << x ; */
        /* std::cout << " : y : " << y; */
        /* std::cout << " : z : " << z << std::endl; */
        // Label each room from 1 and up. 
        mapRooms[z][y][x] = cntRooms;
    }
    // Case switch, create roomobject and allocate it to 
    // the rooms array. Maybe to keymap? This uses roomID
    Room* room = new Room();
    // Find a way to mark the center of the room? Using the first
    // position now.
    room->center = locations[0];
    room->UID = cntRooms;
    rooms[cntRooms-1] = room;
    return room;
}

void ShipMap::clearAllRoomsAndObjects(){
    // Delete objects
    for (int i = 1; i <= cntRooms; i++) {
        // Delete objects in all the rooms.
        Room* room = rooms[i-1];
        int cnt = room->objects.getLength();
        for (int j = 0; j < cnt; j++) {
            // Get objects from all lists and delete them. 
            delete room->objects.pop();
        }
        delete room;
    }
    // Delete all objects in shipmap.
    for (int i = 0; i < objectsLoose.getLength(); i++) {
        delete objectsLoose.pop();
    }
    for (int z = 0; z < O; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                mapRooms[z][y][x] = 0;
            }
        }
    }
    cntRooms = 0;
}

Room* ShipMap::getRoom(int UID){
    if (UID == 0) return NULL;
    return rooms[UID-1];
}

Room* ShipMap::getRoom(Location loc){
    int UID = mapRooms[loc.z][loc.y][loc.x];
    return getRoom(UID);
}

int ShipMap::getObjectCntLoose(){
    return objectsLoose.getLength();
}

Object* ShipMap::getObjectFromUID(int UID){
    return objectsLoose.findWithUID(UID);
}

Object* ShipMap::addObject(int ID, Location loc){
    if (ID == 0) return NULL;
    // Check if the location is occupied.
    int x = loc.x;
    int y = loc.y;
    int z = loc.z;
    if (map[z][y][x] != 0) return NULL;
    // Create the object. Object ID is set in its constructor.
    Object* obj = object_creator::createObject(ID);
    if (obj == NULL) return NULL;
    cntObjects++;
    obj->loc = loc;
    obj->UID = cntObjects;
    map[loc.z][loc.y][loc.x] = ID;
    // Either add the object to the room it is in
    // or add it to the loose objects list in shipmap.
    Room* room = getRoom(loc);
    if (room != NULL) {
        room->addObject(*obj);
    }
    else {
        objectsLoose.add(*obj);
    }
    // Return the object because many times the creator wants it.
    return obj;

}

unsigned int*** ShipMap::getMap(){
    return map;
}

unsigned int*** ShipMap::getMapFloor(){
    return mapFloor;
} 
unsigned int*** ShipMap::getMapEastWalls(){
    return mapWallsEast;
}

unsigned int*** ShipMap::getMapNorthWalls(){
    return mapWallsNorth;
}

unsigned int*** ShipMap::getMapAccess(){
    return mapAccess;
}
unsigned int*** ShipMap::getMapRooms(){
    return mapAccess;
}

void ShipMap::updateMapAccess(){
    using namespace blocks::properties;
    // We cannot simply remove blocked paths the same way as we make them. 
    // Instead reset the whole map and make it anew.
    containerMapAccess.reset();
    unsigned int ID;
    // Ignore to surface of the cube to avoid out of bounds errors.
    for (int z = 1; z < O-1; z++) {
        for (int y = 1; y < N-1; y++) {
            for (int x = 1; x < M-1; x++) {
                // Start with floor.
                ID = mapFloor[z][y][x];
                if (access[ID] == true){
                    mapAccess[z][y][x] = mapAccess[z  ][y][x] | directions::BLOCK_DOWN;
                    mapAccess[z-1][y][x] = mapAccess[z-1][y][x] | directions::BLOCK_UP;
                }
                // Center piece
                ID = map[z][y][x];
                if (access[ID] == true){
                    mapAccess[z][y][x] = mapAccess[z][y][x] | directions::BLOCK_ALL;
                    mapAccess[z-1][y][x] = mapAccess[z-1][y][x] | directions::BLOCK_UP;
                    mapAccess[z][y-1][x] = mapAccess[z][y-1][x] | directions::BLOCK_NORTH;
                    mapAccess[z][y][x-1] = mapAccess[z][y][x-1] | directions::BLOCK_EAST;
                    mapAccess[z+1][y][x] = mapAccess[z+1][y][x] | directions::BLOCK_DOWN;
                    mapAccess[z][y+1][x] = mapAccess[z][y+1][x] | directions::BLOCK_SOUTH;
                    mapAccess[z][y][x+1] = mapAccess[z][y][x+1] | directions::BLOCK_WEST;
                }
                // Walls
                ID = mapWallsEast[z][y][x];
                if (access[ID] == true){
                    mapAccess[z][y][x] = mapAccess[z][y][x] | directions::BLOCK_EAST;
                    mapAccess[z][y][x+1] = mapAccess[z][y][x+1] | directions::BLOCK_WEST;
                    /* std::cout << mapAccess[z][y][x+1] << std::endl; */
                    /* std::cout << "yoman" << std::endl; */
                }
                ID = mapWallsNorth[z][y][x];
                if (access[ID] == true){
                    mapAccess[z][y][x] = mapAccess[z][y][x] | directions::BLOCK_NORTH;
                    mapAccess[z][y+1][x] = mapAccess[z][y+1][x] | directions::BLOCK_SOUTH;
                }
            }
        }
    }
}

ShipMap::~ShipMap(){
    // TODO: Dont do this here.
    clearAllRoomsAndObjects();
}











