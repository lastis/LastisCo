#include "JobFarm.h"

using namespace blocks;

void JobFarm::deligateTask(Person& person){
    if (hasSeeds(person)) sow(person);
    else if (grownCrops()) gather(person);
}

void JobFarm::sow(Person& person){
    // Get a pending object from the ship.
    Object* obj = ship.getObjectPendingFromID(CENTER_CORN);
    if (obj == NULL) return;
    // Make a task of placing the item.
    TaskPlace* task = new TaskPlace(*obj,ship,obj->loc);
    person.setTask(task);
}

void JobFarm::gather(Person& person){
    // Find better way to do this to avoid a lot of searches.
    for (int i = 0; i < ship.getCountObjects(); i++) {
        Object* obj = ship.getObjectFromIndex(i);
        // Go through all the placed objects and check if they are finished.
        // Going to need better ways to do all of this. 
        if (obj == NULL) continue;
        if (obj->ID != CENTER_CORN) continue;
        Corn* corn = (Corn*) obj;
        if (corn->isFinished() == false) continue;
        TaskInteract* task = new TaskInteract(*corn,ship,corn->loc);
        person.setTask(task);
    }
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


