#ifndef __TASK_INTERACT_H_INCLUDED__
#define __TASK_INTERACT_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../items/Item.h"
class Person;
class TaskInteract : public Task{
public:
    TaskInteract(Item* obj, ShipMaster& ship, Location currentPos);
    void doTask(Person& person);
    void setItem(Item* object);

    Item* target;
};
#endif
