#include "TaskPlace.h"
#include "../Person.h"


void TaskPlace::doTask(Person& person){
    // Place the object object if we are close enough to it. 
    if (util::distanceManhatten(person.loc, target) <= 1) {
        // TODO: Find a better way to handle if the
        // object cannot be placed on the target location.
        ship.placeObject(obj,target);
        
        finished = true;
    }
    else {
        // Else we walk. 
        finished = walkOneStep(person);
    }
}

