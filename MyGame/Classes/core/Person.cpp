#include "Person.h"
#include "jobs/Task.h"
#include "Base.h"

#ifdef TESTING
#include <iostream>
#endif

Person::Person(){
    for (int i = 0; i < INVENTORY_SPACE; i++) {
        inventory[i] = 0;
        inventoryAmount[i] = 0;
    }
    location = Location(1,1,1);
    task = NULL;
}

bool Person::addToInventory(Base& base, int amount){
    if (base.ID == 0) return false;
    int slot = 0;
    // Check if already in inventory and icrease the count if it is.
    for (int slot = 0; slot < INVENTORY_SPACE; slot++) {
        if (inventory[slot] == base.ID) {
            inventoryAmount[slot] += amount;
            return true;
        }
    }
    // Search for an empty inventory slot.
    slot = 0;
    while (slot < INVENTORY_SPACE){
        if (inventory[slot] == 0) {
            // Put the item in there. 
            inventory[slot] = base.ID;
            inventoryAmount[slot] = amount;
            return true;
        }
        slot++;
    }
    return false;
}

void Person::setTask(Task* task){
    this->task = task;
}

void Person::update(){
    if (task != NULL) {
        task->doTask(*this);
    }
}
