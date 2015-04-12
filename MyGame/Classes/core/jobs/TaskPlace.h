#ifndef __TASK_PLACE_H_INCLUDED__
#define __TASK_PLACE_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../items/Item.h"
class Person;
class TaskPlace : public Task{
public:
    TaskPlace(Item& obj, ShipMap& ship, Location currentPos) 
        :   obj(obj), 
            Task(ship, ship.findPath(currentPos,obj.loc))
    {
    }
    void doTask(Person& person);

    Item& obj;
};
#endif
