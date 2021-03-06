#include <iostream>
#include "ShipMap.h"
#include "ShipMaster.h"

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
    containerMapTextures = Matrix3D(O,N,M);
    containerMapTexturesFloor = Matrix3D(O,N,M);
    containerMapTexturesEastWalls = Matrix3D(O,N,M);
    containerMapTexturesNorthWalls = Matrix3D(O,N,M);

    map = containerMap.getMatrix();
    mapFloor = containerMapFloor.getMatrix();
    mapWallsEast = containerMapWallsEast.getMatrix();
    mapWallsNorth = containerMapWallsNorth.getMatrix();
    mapAccess = containerMapAccess.getMatrix();
    mapRooms = containerMapAccess.getMatrix();
    mapTextures = containerMapTextures.getMatrix();
    mapTexturesFloor = containerMapTexturesFloor.getMatrix();
    mapTexturesEastWalls = containerMapTexturesEastWalls.getMatrix();
    mapTexturesNorthWalls = containerMapTexturesNorthWalls.getMatrix();

    pathfinder = Pathfinder(containerMapAccess);
    // Find a better way to do this?
}

void ShipMap::placeTexture(unsigned int ID, Location loc){
    mapTextures[loc.z][loc.y][loc.x] = ID;
}


Path ShipMap::findPath(Location start, Location end){
    return pathfinder.findPath(start, end);
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

void ShipMap::placeItem(int UID, Location loc){
    map[loc.z][loc.y][loc.x] = UID;
}

void ShipMap::placeRoom(Location* locations, int N, int UID){
    int x, y, z;
    for (int i = 0; i < N; i++) {
        x = locations[i].x;
        y = locations[i].y;
        z = locations[i].z;
        // Label each room with it's UID.
        mapRooms[z][y][x] = UID;
    }
}

bool ShipMap::isVacant(int x, int y, int z){
    if (map[z][y][x] == 0) return true;
    else return false;
}

unsigned int*** ShipMap::getMapTextures(){
    return mapTextures;
}

bool ShipMap::isVacant(Location loc){
    return isVacant(loc.x,loc.y,loc.z);
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

int ShipMap::getRoomUidFromLoc(Location loc){
    if (!withinBounds(loc)) return 0;
    return mapRooms[loc.z][loc.y][loc.x];
}

bool ShipMap::withinBounds(Location loc){
    if (loc.x < 0 || loc.x >= M) return false;
    if (loc.y < 0 || loc.y >= N) return false;
    if (loc.z < 0 || loc.z >= O) return false;
    return true;
}

void ShipMap::updateMapAccess(ShipMaster& ship){
    using namespace blocks;
    using namespace directions;
    // We cannot simply remove blocked paths the same way as we make them. 
    // Instead reset the whole map and make it anew.
    containerMapAccess.reset();
    Item* obj;
    // Go through all the items on the ship an block update
    // the blocking map.
    LinkedList& items = ship.getItems();
    items.resetIterator();
    obj = items.next();
    while (obj != NULL) {
        if (obj->getBlocking() != BLOCKING) continue;
        int x = obj->loc.x;
        int y = obj->loc.y;
        int z = obj->loc.z;
        int slot = obj->getSlot();
        if (slot == CENTER) {
            mapAccess[z][y][x] = mapAccess[z][y][x] | directions::BLOCK_ALL;
            mapAccess[z-1][y][x] = mapAccess[z-1][y][x] | directions::BLOCK_UP;
            mapAccess[z][y-1][x] = mapAccess[z][y-1][x] | directions::BLOCK_NORTH;
            mapAccess[z][y][x-1] = mapAccess[z][y][x-1] | directions::BLOCK_EAST;
            mapAccess[z+1][y][x] = mapAccess[z+1][y][x] | directions::BLOCK_DOWN;
            mapAccess[z][y+1][x] = mapAccess[z][y+1][x] | directions::BLOCK_SOUTH;
            mapAccess[z][y][x+1] = mapAccess[z][y][x+1] | directions::BLOCK_WEST;
        }
        else if (slot == FLOOR) {
            mapAccess[z][y][x]= mapAccess[z  ][y][x] | directions::BLOCK_DOWN;
            mapAccess[z-1][y][x] = mapAccess[z-1][y][x] | directions::BLOCK_UP;
        }
        else if (slot == WALL && obj->getDirection() == NORTH){
            mapAccess[z][y][x] = mapAccess[z][y][x] | directions::BLOCK_NORTH;
            mapAccess[z][y+1][x] = mapAccess[z][y+1][x] | directions::BLOCK_SOUTH;
        }
        else if (slot == WALL && obj->getDirection() == EAST) {
            mapAccess[z][y][x] = mapAccess[z][y][x] | directions::BLOCK_EAST;
            mapAccess[z][y][x+1] = mapAccess[z][y][x+1] | directions::BLOCK_WEST;
        }
        // If the object is a wall and it is not facing north or 
        // east, we ignore it. 
        obj = items.next();
    }
}

ShipMap::~ShipMap(){

}











