#ifndef __TASK_PLACE_H_INCLUDED__
#define __TASK_PLACE_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../objects/Object.h"
#include "../ShipMap.h"
class Person;
class TaskPlace : public Task{
public:
    TaskPlace(int ID, Location target, ShipMap& ship);
    void doTask(Person& person);

    ShipMap ship;
    Location target;
    int ID;
};
#endif
