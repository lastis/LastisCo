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
    ID::initIDs();
}

void ShipMap::updateMapAccess(){
    using namespace ID;
    for (int i = 0; i < O; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                unsigned int ID = map[i][j][k];
                /* if(arrayIDs[ID] == BOTH) */ 
            }
        }
    }
    

}

ShipMap::~ShipMap(){
    // TODO: Dont do this here.
    ID::clearIDs();
}











