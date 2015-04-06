#include "JobFarm.h"

using namespace blocks;

bool JobFarm::deligateTask(Person& person){
    if (person.hasTask()) return false;
    if (hasSeeds(person)) return sow(person);
    else if (grownCrops()) return gather(person);
    return false;
}

bool JobFarm::sow(Person& person){
    // Get a pending object from the ship.
    Object* obj = ship.getObjectPendingFromID(CENTER_CORN);
    if (obj == NULL) return false;
    // Make a task of placing the item.
    TaskPlace* task = new TaskPlace(*obj,ship,person.loc);
    person.setTask(task);
    return true;
}

bool JobFarm::gather(Person& person){
    // Find better way to do this to avoid a lot of searches.
    for (int i = 0; i < ship.getCountObjects(); i++) {
        Object* obj = ship.getObjectFromIndex(i);
        // Go through all the placed objects and check if they are finished.
        // Going to need better ways to do all of this. 
        if (obj == NULL) continue;
        if (obj->ID != CENTER_CORN) continue;
        Corn* corn = (Corn*) obj;
        if (corn->isFinished() == false) continue;
        TaskInteract* task = new TaskInteract(*corn,ship,person.loc);
        person.setTask(task);
        return true;
    }
    // Didn't find any finished crops.
    return false;
}

bool JobFarm::hasSeeds(Person& person){
    return person.hasInInventory(CENTER_CORN,1);
}

bool JobFarm::grownCrops(){
    for (int i = 0; i < ship.getCountObjects(); i++) {
        Object* obj = ship.getObjectFromIndex(i);
        // Go through all the placed objects and check if they are finished.
        // Going to need better ways to do all of this. 
        if (obj == NULL) continue;
        if (obj->ID != CENTER_CORN) continue;
        Corn* corn = (Corn*) obj;
        if (corn->isFinished()) return true;
    }
    return false;
}


