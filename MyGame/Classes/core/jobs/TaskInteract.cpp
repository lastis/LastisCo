#include "TaskInteract.h"
#include "../Person.h"

void TaskInteract::doTask(Person& person){
    // Interact with object if we are close enough to it. 
    /* if (util::distanceManhatten(person.loc, target.loc) <= 1) { */
    /*     // Interact with block here */
    /* } */
    /* else walkOneStep(person); */
}

void TaskInteract::setObject(Object& target){
    this->target = target;
}
