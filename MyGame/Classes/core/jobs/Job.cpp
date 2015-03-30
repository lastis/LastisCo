#include "Job.h"

#ifdef TESTING
#include <iostream>
#endif


void Job::setShipMap(ShipMap& ship){
    this->ship = ship;
}
