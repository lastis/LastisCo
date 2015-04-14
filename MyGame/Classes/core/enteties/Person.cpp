#include "../Base.h"
#include "../jobs/Task.h"
#include "Person.h"
#include <iostream>

Person::Person(){
    for (int i = 0; i < INVENTORY_SPACE; i++) {
        inventory[i] = 0;
        inventoryAmount[i] = 0;
    }
    loc = Location(1,1,1);
    task = NULL;
}

bool Person::addToInventory(int ID, int amount){
    if (ID == 0) return false;
    int slot = 0;
    // Check if already in inventory and icrease the count if it is.
    for (int slot = 0; slot < INVENTORY_SPACE; slot++) {
        if (inventory[slot] == ID) {
            inventoryAmount[slot] += amount;
            return true;
        }
    }
    // Search for an empty inventory slot.
    slot = 0;
    while (slot < INVENTORY_SPACE){
        if (inventory[slot] == 0) {
            // Put the item in there. 
            inventory[slot] = ID;
            inventoryAmount[slot] = amount;
            return true;
        }
        slot++;
    }
    return false;
}
bool Person::hasInInventory(int ID, int amount){
    if (ID == 0) return false;
    if (amount == 0) return false;
    for (int slot = 0; slot < INVENTORY_SPACE; slot++) {
        // Check if the item is in the inventory.
        if (inventory[slot] == ID) {
            int amountTot = inventoryAmount[slot];
            // If the requested amount is present, return true;
            if (amount <= amountTot) {
                return true;
            }
        }
    }
    return false;
}

bool Person::takeFromInventory(int ID, int amount){
    if (ID == 0) return 0;
    // Check if the item is in the inventory and return
    // the amount of items removed.
    for (int slot = 0; slot < INVENTORY_SPACE; slot++) {
        if (inventory[slot] != ID) continue; 
        int amountAvailable = inventoryAmount[slot];
        if (amount <= amountAvailable) {
            inventoryAmount[slot] -= amount;
            return true;
        }
    }
    return false;
}

int Person::amountInInventory(int ID){
    if (ID == 0) return 0;
    // Check if the item is in the inventory and return
    // the amount of items.
    for (int slot = 0; slot < INVENTORY_SPACE; slot++) {
        if (inventory[slot] != ID) continue; 
        return inventoryAmount[slot];
    }
    return 0;
}

void Person::setTask(Task* task){
    this->task = task;
    if (task == NULL) return;
    task->setFinished(false);
}

bool Person::hasTask(){
    return (task != NULL);
}

void Person::update(){
    if (!hasTask()) return;
    task->doTask(*this);
    if (task->isFinished()) {
        delete task;
        task = NULL;
    }
}

#ifdef TESTING
void Person::printInventory(){
    for (int i = 0; i < INVENTORY_SPACE; i++) {
        std::cout  << "Inventory : " << inventory[i] 
            << ". Amount : " << inventoryAmount[i] << "." << std::endl;
    }
}
#endif

Person::~Person(){
    if (hasTask()) delete task;
}
