#include "TaskInteract.h"
#include "../enteties/Person.h"



void TaskInteract::doTask(Person& person){
    // Interact with object if we are close enough to it. 
    if (util::distanceManhatten(person.loc, target.loc) <= 1) {
        finished = target.interact(person);
    }
    else {
        // Else we walk. 
        finished = walkOneStep(person);
    }
}


void TaskInteract::setItem(Item& target){
    this->target = target;
}
