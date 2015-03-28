#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include "Location.h"
class Task;

class Person {
public:
    static const int INVENTORY_SPACE = 5;

    Person();
    void setTask(Task* task);
    void update();

    Location location;
    Task* task;
    unsigned int inventory[INVENTORY_SPACE];

};
#endif
