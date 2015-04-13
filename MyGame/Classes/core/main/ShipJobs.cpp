#include "ShipJobs.h"
#include "ShipMaster.h"

ShipJobs::ShipJobs(ShipMaster& ship) : 
    ship(ship), 
    jobFarm(new JobFarm(ship))
{

}

void ShipJobs::update(){
    /* int N = ship.shipCrew->cntCrew; */
    /* for (int i = 0; i < N; i++) { */
    /*     Person* person = ship.shipCrew->crew[i]; */
    /* } */
}

ShipJobs::~ShipJobs(){
    delete jobFarm;
}
