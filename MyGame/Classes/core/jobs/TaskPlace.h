#ifndef __TASK_PLACE_H_INCLUDED__
#define __TASK_PLACE_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../items/Item.h"
class Person;
class TaskPlace : public Task{
public:
    TaskPlace(Item& obj, ShipMaster& ship, Location currentPos);
    void doTask(Person& person);

    Item& obj;
};
#endif
