#ifdef TESTING
#include <iostream>
#endif
#include "ShipMap.h"

ShipMap::ShipMap(){
    ShipMap(1,1,1);
}

ShipMap::ShipMap(int O, int N, int M){
    map = Matrix3D(O,N,M);
    mapBlocking = Matrix3D(O,N,M);
    pathfinder = Pathfinder(mapBlocking);
}

ShipMap::~ShipMap(){
}











