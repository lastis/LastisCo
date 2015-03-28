#include "TaskInteract.h"
#include "../Person.h"

void Task::doTask(Person& person){
    // Interact with object if we are close enough to it. 
    if (util::distanceManhatten(person.loc, target) <= 1) {
        // Interact with block here
    }
    else walkOneStep(person);
}

