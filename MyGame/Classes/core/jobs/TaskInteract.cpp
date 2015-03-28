#include "TaskInteract.h"
#include "../Person.h"

void Task::doTask(Person& person){
    /* if (util::distanceManhatten(person.loc, Tasktarget) < 1) { */
        
    /* } */
    walkOneStep(person);
}

void TaskInteract::setTarget(Location* target){
    this->target = target;
}
