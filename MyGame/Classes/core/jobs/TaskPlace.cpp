#include "TaskPlace.h"
#include "../Person.h"


TaskPlace::TaskPlace(int ID, Location loc, ShipMap& ship) 
    : ID(ID), target(loc), ship(ship){

}

void TaskPlace::doTask(Person& person){
    // Place the object object if we are close enough to it. 
    if (util::distanceManhatten(person.loc, target) <= 1) {
        Object* obj  = ship.createObject(ID);
        if (obj != NULL) {
            // TODO: Find a better way to handle if the
            // object cannot be placed on the target location.
            ship.placeObject(*obj,target);
        }
        
        finished = true;
    }
    else {
        // Else we walk. 
        finished = walkOneStep(person);
    }
}

