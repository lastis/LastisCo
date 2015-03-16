#include "Job.h"

#ifdef TESTING
#include <iostream>
#endif

Job::Job(){
    map = NULL;
}

void Job::setShipMap(ShipMap* map){
    this->map = map;
}
