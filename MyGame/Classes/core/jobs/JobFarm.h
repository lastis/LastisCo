#ifndef __JOB_FARM_H_INCLUDED__
#define __JOB_FARM_H_INCLUDED__
#include "Job.h"
#include "TaskInteract.h"
#include "TaskMove.h"
#include "TaskPlace.h"

class JobFarm : public Job{
public:
    JobFarm(ShipMaster& ship);
    // Methods to deligate tasks, return true if deligiation
    // was successful.
    bool deligateTask(Person& person);
    bool gather(Person& person);
    bool sow(Person& person);

    bool hasSeeds(Person& person);
    bool grownCrops();
};


#endif
