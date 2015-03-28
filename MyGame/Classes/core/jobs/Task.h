#ifndef __TASK_H_INCLUDED__
#define __TASK_H_INCLUDED__
#include "Location.h"

class Person;
class Path;
class Task {
public:
    Task();
    virtual void doTask(Person& person);
    // Should be private?
    void walkOneStep(Person& person);
    void setPath(Path* path);
    void setTarget(Location target);

    Location target;
    Path* path;
};
#endif
