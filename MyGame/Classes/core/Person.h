#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include "Location.h"
class Task;
class Base;
class Person {
public:
    static const int INVENTORY_SPACE = 5;

    Person();
    void setTask(Task* task);
    void update();
    bool addToInventory(Base& base, int amount);

    Location loc;
    Task* task;
    unsigned int inventory[INVENTORY_SPACE];
    unsigned int inventoryAmount[INVENTORY_SPACE];

};
#endif
