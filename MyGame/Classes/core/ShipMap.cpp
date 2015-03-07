#ifdef TESTING
#include <iostream>
#endif
#include "ShipMap.h"

ShipMap::ShipMap(){
    ShipMap(1,1,1);
}

ShipMap::ShipMap(int O, int N, int M){
    map = new Matrix3D(O,N,M);
    mapBlocking = new Matrix3D(O,N,M);
}

ShipMap::~ShipMap(){
    delete map;
    delete mapBlocking;
}











