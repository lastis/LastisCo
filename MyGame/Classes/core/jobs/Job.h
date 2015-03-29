#ifndef __JOB_H_INCLUDED__
#define __JOB_H_INCLUDED__
// Forward declare.
class ShipMap;
class Person;
class Job {
public:
    ShipMap* map;
    Job();
    void setShipMap(ShipMap* map);
    virtual void deligateTask(Person& person) = 0;
};

#endif
