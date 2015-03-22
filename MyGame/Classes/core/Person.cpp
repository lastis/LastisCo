#include "Person.h"
#include "jobs/Task.h"

#ifdef TESTING
#include <iostream>
#endif

Person::Person(){
    location = Location(1,1,1);
    task = NULL;
}

void Person::setTask(Task* task){
    this->task = task;
}

void Person::update(){
    if (task != NULL) {
        task->doTask(*this);
    }
}
