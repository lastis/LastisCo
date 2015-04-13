#ifndef __TASK_H_INCLUDED__
#define __TASK_H_INCLUDED__
#include <iostream>
#include "../map/Path.h"

class Person;
class ShipMaster;
class Task {
public:
    Task(ShipMaster& ship) 
        : ship(ship), finished(true)
    {
    }
    virtual void doTask(Person& person) = 0;
    // Should be private?
    bool walkOneStep(Person& person);
    void setPath(Path path);
    void setFinished(bool val);
    bool isFinished();
    bool hasPath();
    
    bool finished;
    Path path;
    ShipMaster& ship;
};
#endif
