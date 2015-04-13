#include "TaskPlace.h"
#include "../enteties/Person.h"
#include "../main/ShipMaster.h"

TaskPlace::TaskPlace(Item& obj, ShipMaster& ship, Location currentPos) 
        :   obj(obj), Task(ship)
{
    setPath(ship.findPath(currentPos,obj.loc));
}


void TaskPlace::doTask(Person& person){
    // Place the object object if we are close enough.
    if (util::distanceManhatten(person.loc, obj.loc) <= 1) {
        finished = true;
        bool vacantPosition = ship.isVacant(obj.loc);
        bool canPlace = obj.canPlace(person);
        // Check if the object is placed, if there is room for the object
        // and if the person has enough resources to place the item. 
        if (obj.isPlaced()) return;
        if (!vacantPosition) return;
        if (!canPlace) return;
        // Start placing the object. Some objects require longer
        // "construction-times".
        bool finishedPlacing = obj.place(person);
        // If this is the case, the task is not finished and will call
        // obj.place() on the next update to do another attempt.
        if (!finishedPlacing) finished = false;
        // Else we simply place the object. 
        else ship.placeItem(obj);
    }
    else {
        // Else we walk. 
        finished = walkOneStep(person);
    }
}

