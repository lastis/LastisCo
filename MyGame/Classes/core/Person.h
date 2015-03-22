#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include "Location.h"
class Task;

class Person {
public:
    Person();
    void setTask(Task* task);
    void update();

    Location location;
    Task* task;

};
#endif
