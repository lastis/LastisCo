#ifndef __TASK_INTERACT_H_INCLUDED__
#define __TASK_INTERACT_H_INCLUDED__
#include "Task.h"
#include "../Location.h"
#include "../util.h"
class TaskInteract : public Task{
public:
    void doTask(Person& person);
    void setTarget(Location target);

    Location target;
};
#endif
