#include "TaskInteract.h"

void Task::doTask(Person& person){
    walkOneStep(person);
}

void TaskInteract::setTarget(Location* target){
    this->target = target;
}
