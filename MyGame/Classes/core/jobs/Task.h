#ifndef __TASK_H_INCLUDED__
#define __TASK_H_INCLUDED__
class Person;

class Task {
public:
    Task();
    virtual void doTask(Person* person);
};
#endif
