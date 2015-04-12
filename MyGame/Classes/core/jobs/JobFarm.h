#ifndef __JOB_FARM_H_INCLUDED__
#define __JOB_FARM_H_INCLUDED__
#include "Job.h"
#include "TaskInteract.h"
#include "TaskPlace.h"
#include "../enteties/Person.h"
#include "../identifiers.h"

class JobFarm : public Job{
public:
    JobFarm(ShipMap& ship) 
        : Job(ship)
    {
    }
    // Methods to deligate tasks, return true if deligiation
    // was successful.
    bool deligateTask(Person& person);
    bool gather(Person& person);
    bool sow(Person& person);

    bool hasSeeds(Person& person);
    bool grownCrops();
};


#endif
