#ifndef __TASK_H_INCLUDED__
#define __TASK_H_INCLUDED__
#ifdef TESTING
#include <iostream>
#endif

class Person;
class Path;
class Task {
public:
    Task();
    virtual void doTask(Person& person) = 0;
    // Should be private?
    bool walkOneStep(Person& person);
    void setPath(Path* path);

    Path* path;
};
#endif
