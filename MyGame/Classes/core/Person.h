#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include "Location.h"
#include "Base.h"
class Task;
class Person : public Base{
public:
    static const int INVENTORY_SPACE = 5;

    Person();
    void setTaskFinished(bool val);
    void setTask(Task* task);
    bool hasTask();
    void update();
    bool addToInventory(int ID, int amount);
    bool hasInInventory(int ID, int amount);
    int takeFromInventory(int ID, int amount);

    Location loc;
    Task* task;
    unsigned int inventory[INVENTORY_SPACE];
    unsigned int inventoryAmount[INVENTORY_SPACE];

};
#endif
