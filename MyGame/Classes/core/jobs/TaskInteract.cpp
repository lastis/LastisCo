#include "TaskInteract.h"
#include "../Person.h"
TaskInteract::TaskInteract(Object& yo) : target(yo){

}

void TaskInteract::doTask(Person& person){
    // Interact with object if we are close enough to it. 
    if (util::distanceManhatten(person.loc, target.loc) <= 1) {
        /* target.interact(person); */
    }
    else walkOneStep(person);
}

void TaskInteract::setObject(Object& target){
    this->target = target;
}
