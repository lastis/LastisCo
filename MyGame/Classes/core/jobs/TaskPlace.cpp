#include "TaskPlace.h"
#include "../Person.h"


void TaskPlace::doTask(Person& person){
    // Place the object object if we are close enough.
    if (util::distanceManhatten(person.loc, obj.loc) <= 1) {
        // TODO: Find a better way to handle if the
        // object cannot be placed on the target location.
        ship.placeObject(obj,obj.loc);
        finished = true;
    }
    else {
        // Else we walk. 
        finished = walkOneStep(person);
    }
}

