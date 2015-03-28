#ifndef __TASK_INTERACT_H_INCLUDED__
#define __TASK_INTERACT_H_INCLUDED__
#include "Task.h"
#include "../Location.h"
class TaskInteract : public Task{
public:
    /* TaskFarm(); */

    void setTarget(Location* target);
    
    Location* target;
};
#endif
