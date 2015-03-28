#ifndef __JOB_FARM_H_INCLUDED__
#define __JOB_FARM_H_INCLUDED__
#include "Job.h"
#include "TaskInteract.h"

class JobFarm : public Job{
public:
    JobFarm();
    void deligateTask(Person& person);
    void gather(Person& person);
    void sow(Person& person);
};


#endif
