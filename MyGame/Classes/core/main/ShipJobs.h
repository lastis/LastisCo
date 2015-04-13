#ifndef __SHIP_JOBS_H_INCLUDED__
#define __SHIP_JOBS_H_INCLUDED__
#include "../jobs/JobFarm.h"
class ShipJobs {
public:
    ShipJobs(ShipMaster& ship);
    ~ShipJobs();
    void update();

    ShipMaster& ship;
    JobFarm* jobFarm;
};
#endif
