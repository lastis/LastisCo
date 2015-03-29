#include "Corn.h"
#include "../Person.h"
#include "../Identifiers.h"

#ifdef TESTING
#include <iostream>
#endif

Corn::Corn(){
    ID = blocks::CENTER_CORN;
    time = 0;
    stage1 = 2;
    stage2 = 4;
    stage3 = 6;
    stageFinal = stage3;
    planted = false;
}

void Corn::interact(Person& person){
    // Put corn in the persons inventory if fully grown.
    // Objects of corn should only exsist on the map. 
    if (!isFinished()) return;
    // Add multiple corns to his inventory.
    person.addToInventory(ID,2);
}

bool Corn::isFinished(){
    if (stage == stageFinal) return true;
    return false;
}

void Corn::update(){
    if (planted) grow();
}

void Corn::grow(){
    time++;
    if (time < stage1) {
        stage = stage1;
    }
    else if (time < stage2) {
        stage = stage2;
    }
    else if (time < stage3) {
        stage = stage3;
    }
    else if (time == stageFinal) {
        stage = stageFinal;
    }
}


