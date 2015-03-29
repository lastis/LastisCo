#include "TaskInteract.h"
#include "../Person.h"


TaskInteract::TaskInteract(Object& obj) : target(obj){

}

void TaskInteract::doTask(Person& person){
    // Interact with object if we are close enough to it. 
    bool finished;
    if (util::distanceManhatten(person.loc, target.loc) <= 1) {
        finished = target.interact(person);
    }
    else {
        // Else we walk. 
        finished = walkOneStep(person);
    }
    if (finished) finish(person);
}


void TaskInteract::setObject(Object& target){
    this->target = target;
}
