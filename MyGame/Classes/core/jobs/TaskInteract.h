#ifndef __TASK_INTERACT_H_INCLUDED__
#define __TASK_INTERACT_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../objects/Item.h"
class Person;
class TaskInteract : public Task{
public:
    TaskInteract(Item& obj, ShipMap& ship, Location currentPos) 
        :   target(obj), 
            Task(ship, ship.findPath(currentPos,obj.loc))
    {
    }
    void doTask(Person& person);
    void setItem(Item& object);

    Item& target;
};
#endif
