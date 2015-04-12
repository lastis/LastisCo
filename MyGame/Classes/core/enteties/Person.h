#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include "../Base.h"
#include "../map/Location.h"
class Task;
class Person : public Base{
public:
    static const int INVENTORY_SPACE = 5;

    Person();
    ~Person();
    void setTask(Task* task);
    bool hasTask();
    void update();
    bool addToInventory(int ID, int amount);
    bool hasInInventory(int ID, int amount);
    bool takeFromInventory(int ID, int amount);
    int amountInInventory(int ID);

    Location loc;
    Task* task;
    unsigned int inventory[INVENTORY_SPACE];
    unsigned int inventoryAmount[INVENTORY_SPACE];

#ifdef TESTING
    void printInventory();
#endif
};
#endif
