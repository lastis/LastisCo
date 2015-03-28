#ifndef __TASK_INTERACT_H_INCLUDED__
#define __TASK_INTERACT_H_INCLUDED__
#include "Task.h"
#include "../util.h"
#include "../objects/Object.h"
class Person;
class TaskInteract : public Task{
public:
    TaskInteract(Object& yo);
    void doTask(Person& person);
    void setObject(Object& object);

    Object& target;
};
#endif
