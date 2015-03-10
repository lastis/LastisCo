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
    containerMap = Matrix3D(O,N,M);
    containerMapFloor = Matrix3D(O,N,M);
    containerMapWallsEast = Matrix3D(O,N,M);
    containerMapWallsNorth = Matrix3D(O,N,M);
    containerMapAccess = Matrix3D(O,N,M);

    map = containerMap.getMatrix();
    mapFloor = containerMapFloor.getMatrix();
    mapWallsEast = containerMapWallsEast.getMatrix();
    mapWallsNorth = containerMapWallsNorth.getMatrix();
    mapAccess = containerMapAccess.getMatrix();

    pathfinder = Pathfinder(containerMapAccess);
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

void ShipMap::updateMapAccess(){
    using namespace blocks::properties;
    unsigned int ID;
    for (int z = 0; z < O; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                // Start with floor.
                ID = mapFloor[z][y][x];
                if (access[ID] == true){
                    mapAccess[z  ][y][x] | directions::BLOCK_DOWN;
                    mapAccess[z-1][y][x] | directions::BLOCK_UP;
                }
                // Center piece
                ID = map[z][y][x];
                if (access[ID] == true){
                    mapAccess[z][y][x] | directions::BLOCK_ALL;
                    mapAccess[z-1][y][x] | directions::BLOCK_UP;
                    mapAccess[z][y-1][x] | directions::BLOCK_NORTH;
                    mapAccess[z][y][x-1] | directions::BLOCK_EAST;
                    mapAccess[z+1][y][x] | directions::BLOCK_DOWN;
                    mapAccess[z][y+1][x] | directions::BLOCK_SOUTH;
                    mapAccess[z][y][x+1] | directions::BLOCK_WEST;
                }
                // Walls
                ID = mapWallsEast[z][y][x];
                if (access[ID] == true){
                    mapAccess[z][y][x] | directions::BLOCK_EAST;
                    mapAccess[z][y][x+1] | directions::BLOCK_WEST;
                }
                ID = mapWallsNorth[z][y][x];
                if (access[ID] == true){
                    mapAccess[z][y][x] | directions::BLOCK_NORTH;
                    mapAccess[z][y+1][x] | directions::BLOCK_SOUTH;
                }
            }
        }
    }
}

ShipMap::~ShipMap(){
    // TODO: Dont do this here.
    blocks::properties::clearIDs();
}











