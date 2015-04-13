#include "Job.h"
#include <iostream>
#include "../main/ShipMaster.h"
Job::Job(ShipMaster& ship) : ship(ship)
{
}

void Job::setShipMaster(ShipMaster& ship){
    this->ship = ship;
}
