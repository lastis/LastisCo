#ifndef __JOB_H_INCLUDED__
#define __JOB_H_INCLUDED__
#include "../identifiers.h"
#include "../enteties/Person.h"
class ShipMaster;
class Job {
public:
    Job(ShipMaster& ship);
    virtual ~Job(){};
    void setShipMaster(ShipMaster& ship);
    virtual bool deligateTask(Person& person) = 0;

    ShipMaster& ship;
};

#endif
