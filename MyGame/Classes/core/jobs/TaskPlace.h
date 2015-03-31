#ifndef __TASK_PLACE_H_INCLUDED__
#define __TASK_PLACE_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../objects/Object.h"
#include "../ShipMap.h"
class Person;
class TaskPlace : public Task{
public:
    TaskPlace(Object& obj, Location loc, ShipMap& ship)
        : obj(obj), target(loc), ship(ship)
    {
    }
    void doTask(Person& person);

    ShipMap& ship;
    Location target;
    Object& obj;
};
#endif
