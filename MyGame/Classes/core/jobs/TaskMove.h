#ifndef __TASK_MOVE_H_INCLUDED__
#define __TASK_MOVE_H_INCLUDED__
#include "Task.h"
#include "../util.h"
class TaskMove : public Task{
public:
    TaskMove(ShipMap& ship, Location currentPos, Location end) 
        :   Task(ship,ship.findPath(currentPos,end))
    {
    }
    void doTask(Person& person);
};
#endif
