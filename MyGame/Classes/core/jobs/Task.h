#ifndef __TASK_H_INCLUDED__
#define __TASK_H_INCLUDED__
#ifdef TESTING
#include <iostream>
#endif

#include "../ShipMap.h"

class Person;
class Path;
class Task {
public:
    Task(ShipMap& ship, Path path) 
        : ship(ship), path(path), finished(true)
    {
    }
    virtual void doTask(Person& person) = 0;
    // Should be private?
    bool walkOneStep(Person& person);
    void setPath(Path& path);
    void setFinished(bool val);
    bool isFinished();
    bool hasPath();
    
    bool finished;
    Path path;
    ShipMap& ship;
};
#endif
