#ifndef __TASK_H_INCLUDED__
#define __TASK_H_INCLUDED__
class Person;
class Path;

class Task {
public:
    Task();
    virtual void doTask(Person& person);
    // Should be private?
    void walkOneStep(Person& person);
    void setPath(Path* path);
    Path* path;
};
#endif
