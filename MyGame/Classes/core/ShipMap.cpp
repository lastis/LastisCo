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
    roomCnt = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = NULL;
    }

    pathfinder = Pathfinder(containerMapAccess);
    //TODO: Probably should do this elsewhere.
    blocks::properties::initArrays();
}

unsigned int* ShipMap::findPathToRoom(int roomLabel, Location start){
    Location goal = rooms[roomLabel]->center;
    return pathfinder.findPath(start, goal);
}

void ShipMap::insertBlocksCenter(int blockID, Location start, Location end){
    using namespace blocks;
    using namespace blocks::properties;
    int tmp;
    if (start.x > end.x) {
        tmp = end.x;
        end.x = start.x;
        start.x = tmp;
    }
    if (start.y > end.y) {
        tmp = end.y;
        end.y = start.y;
        start.y = tmp;
    }
    if (start.z > end.z) {
        tmp = end.z;
        end.z = start.z;
        start.z = tmp;
    }
    for (int z = start.z; z < end.z; z++) {
        for (int y = start.y; y < end.y; y++) {
            for (int x = start.x; x < end.x; x++) {
                if (map[z][y][x] != 0) continue;
                if (map[z][y][x] != CENTER_AIR) continue;
                if (slots[blockID] != CENTER) continue;
                map[z][y][x] = blockID;
            }
        }
    }
}

bool ShipMap::createRoom(Location* locations, int N, int roomID){
    if (roomCnt == MAX_ROOMS - 1) return false;
    if (locations == NULL) return false;
    roomCnt++;
    int x, y, z;
    for (int i = 0; i < N; i++) {
        x = locations[i].x;
        y = locations[i].y;
        z = locations[i].z;
        /* std::cout << "x : " << x ; */
        /* std::cout << " : y : " << y; */
        /* std::cout << " : z : " << z << std::endl; */
        // Label each room from 1 and up. 
        mapRooms[z][y][x] = roomCnt;
    }
    // Case switch, create roomobject and allocate it to 
    // the rooms array. Maybe to keymap?
    Room* room = new Room();
    room->center = locations[0];
    room->label = roomCnt;
    rooms[roomCnt-1] = room;
    return true;
}

void ShipMap::clearAllRooms(){
    for (int i = 0; i < roomCnt; i++) {
        delete rooms[roomCnt-1];
    }
    for (int z = 0; z < O; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                mapRooms[z][y][x] = 0;
            }
        }
    }
    roomCnt = 0;
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
    clearAllRooms();
    blocks::properties::clearIDs();
}











