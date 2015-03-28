#include "TaskInteract.h"
#include "../Person.h"

void TaskInteract::doTask(Person& person){
    // Interact with object if we are close enough to it. 
    if (util::distanceManhatten(person.loc, target) <= 1) {
        // Interact with block here
    }
    else walkOneStep(person);
}

void TaskInteract::setTarget(Location target){
    this->target = target;
}
