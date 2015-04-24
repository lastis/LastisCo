#include "JobFarm.h"
#include "../main/ShipMaster.h"

using namespace blocks;

JobFarm::JobFarm(ShipMaster& ship) : Job(ship)
{

}

bool JobFarm::deligateTask(Person& person){
    if (person.hasTask()) return false;
    if (hasSeeds(person)) return sow(person);
    else if (grownCrops()) return gather(person);
    return false;
}

bool JobFarm::sow(Person& person){
    // Get a pending object from the ship.
    Item* obj = ship.getItemPendingFromID(CENTER_CORN);
    if (obj == NULL) return false;
    // Make a task of placing the item.
    TaskPlace* task = new TaskPlace(obj,ship,person.loc);
    person.setTask(task);
    return true;
}

bool JobFarm::gather(Person& person){
    // Find better way to do this to avoid a lot of searches.
    // Go through all the placed objects and check if they are finished.
    LinkedList& items = ship.getItems();
    items.resetIterator();
    Item* obj = items.next();
    while (obj != NULL) {
        if (obj->ID == CENTER_CORN){
            Corn* corn = (Corn*) obj;
            if (!corn->isFinished()){
                TaskInteract* task = new TaskInteract(corn,ship,person.loc);
                person.setTask(task);
                return true;
            }
        }
        obj = items.next();
    }
    // Didn't find corn.
    return false;
}

bool JobFarm::hasSeeds(Person& person){
    return person.hasInInventory(CENTER_CORN,1);
}

bool JobFarm::grownCrops(){
    LinkedList& items = ship.getItems();
    items.resetIterator();
    Item* obj = items.next();
    while (obj != NULL) {
        // Go through all the placed objects and check if they are finished.
        if (obj->ID == CENTER_CORN) {
            Corn* corn = (Corn*) obj;
            if (!corn->isFinished()) return true;
        }
        obj = items.next();
    }
    return false;
}


