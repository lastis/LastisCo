#ifndef __TASK_MOVE_H_INCLUDED__
#define __TASK_MOVE_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../objects/Object.h"
class TaskMove : public Task{
public:
    void doTask(Person& person);
};
#endif
