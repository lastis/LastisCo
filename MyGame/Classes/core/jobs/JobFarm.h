#ifndef __JOB_FARM_H_INCLUDED__
#define __JOB_FARM_H_INCLUDED__
#include "Job.h"
#include "TaskInteract.h"
#include "TaskPlace.h"
#include "../Person.h"
#include "../Identifiers.h"

class JobFarm : public Job{
public:
    JobFarm(ShipMap& ship) 
        : Job(ship)
    {
    }
    void deligateTask(Person& person);
    void gather(Person& person);
    void sow(Person& person);
    bool hasSeeds(Person& person);
    bool grownCrops();
};


#endif
