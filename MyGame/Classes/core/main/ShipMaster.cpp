#include "ShipMaster.h"

ShipMaster::ShipMaster(){
    ShipMaster(1,1,1);
}

ShipMaster::ShipMaster(int O, int N, int M){
    initialize(O,N,M);
}

void ShipMaster::initialize(int O, int N, int M){
    this->O = O;
    this->N = N;
    this->M = M;
    cntUID      = 0;
    cntCrew     = 0;
    cntRooms    = 0;
    blocks::properties::initArrays();
}
