#ifndef __TASK_MOVE_H_INCLUDED__
#define __TASK_MOVE_H_INCLUDED__
#include "Task.h"
#include "../util.h"
class TaskMove : public Task{
public:
    TaskMove(ShipMaster& ship, Location currentPos, Location end);
    void doTask(Person& person);
};
#endif
