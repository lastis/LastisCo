#ifndef __TASK_INTERACT_H_INCLUDED__
#define __TASK_INTERACT_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../objects/Object.h"
class Person;
class TaskInteract : public Task{
public:
    TaskInteract(Object& obj, ShipMap& ship, Location currentPos) 
        :   target(obj), 
            Task(ship, ship.findPath(currentPos,obj.loc))
    {
    }
    void doTask(Person& person);
    void setObject(Object& object);

    Object& target;
};
#endif
