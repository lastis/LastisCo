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

    pathfinder = Pathfinder(containerMapAccess);
    //TODO: Probably should do this elsewhere.
    blocks::properties::initArrays();
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
    blocks::properties::clearIDs();
}











