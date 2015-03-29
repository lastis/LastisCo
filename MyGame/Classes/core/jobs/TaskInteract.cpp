#include "TaskInteract.h"
#include "../Person.h"


TaskInteract::TaskInteract(Object& obj) : target(obj){

}

void TaskInteract::doTask(Person& person){
    // Interact with object if we are close enough to it. 
    if (util::distanceManhatten(person.loc, target.loc) <= 1) {
        bool finished = target.interact(person);
        if (finished) {
            // Remove the task from the person
            // if it is finished.
            person.task = NULL;
        }

    }
    else {
        bool finished = walkOneStep(person);
        if (finished) person.task = NULL;
    }
}

void TaskInteract::setObject(Object& target){
    this->target = target;
}
