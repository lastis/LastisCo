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
    map = Matrix3D(O,N,M);
    mapFloor = Matrix3D(O,N,M);
    mapWallsEast = Matrix3D(O,N,M);
    mapWallsNorth = Matrix3D(O,N,M);

    mapBlocking = Matrix3D(O,N,M);
    pathfinder = Pathfinder(mapBlocking);
}

ShipMap::~ShipMap(){
}











