#ifndef __JOB_H_INCLUDED__
#define __JOB_H_INCLUDED__
// Forward declare.
class ShipMap;
class Person;
class Job {
public:
    Job(ShipMap& ship) : ship(ship);
    void setShipMap(ShipMap& ship);
    virtual void deligateTask(Person& person) = 0;

    ShipMap ship;
};

#endif
