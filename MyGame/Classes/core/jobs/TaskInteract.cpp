#include "TaskInteract.h"
#include "../enteties/Person.h"
#include "../main/ShipMaster.h"

TaskInteract::TaskInteract(Item& obj, ShipMaster& ship, Location currentPos) 
    :   target(obj), Task(ship)
{
    // Make a path from the current location to where we want
    // to interact with.
    setPath(ship.findPath(currentPos,obj.loc));
}

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
