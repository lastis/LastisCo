#include "ShipJobs.h"
#include "ShipMaster.h"

ShipJobs::ShipJobs(ShipMaster& ship) : 
    ship(ship), 
    jobFarm(new JobFarm(ship))
{

}

void ShipJobs::update(ShipMaster& ship){
    int N = ship.getCrewCount();
    for (int i = 0; i < N; i++) {
        Person* person = ship.getCrewFromIndex(i);
        if (person == NULL) continue;
        jobFarm->deligateTask(*person);
    }
}

ShipJobs::~ShipJobs(){
    delete jobFarm;
}
