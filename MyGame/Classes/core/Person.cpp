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

int Person::takeFromInventory(int ID, int amount){
    if (ID == 0) return 0;
    // Check if the item is in the inventory and return
    // the amount of items removed.
    for (int slot = 0; slot < INVENTORY_SPACE; slot++) {
        if (inventory[slot] == ID) {
            int amountTot = inventoryAmount[slot];
            if (amount <= amountTot) {
                inventoryAmount[slot] -= amount;
                return amount;
            }
            else {
                amount = inventoryAmount[slot];
                inventoryAmount[slot] -= 0;
                return amount;
            }
        }
    }
}

void Person::setTask(Task* task){
    this->task = task;
}
bool Person::hasTask(){
    if(task != NULL) return true;
    else return false;
}

void Person::update(){
    if (task != NULL) {
        task->doTask(*this);
    }
}
