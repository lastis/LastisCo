#include "ShipJobs.h"

ShipJobs::ShipJobs(ShipMaster& ship) : 
    ship(ship), 
    jobFarm(JobFarm(ship))
{

}

void ShipJobs::update(){
    
}
