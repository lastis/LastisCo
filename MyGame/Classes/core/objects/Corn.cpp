#include "Corn.h"
#include "../Person.h"
#include "../Identifiers.h"

#ifdef TESTING
#include <iostream>
#endif

Corn::Corn(){
    ID = blocks::CENTER_CORN;
    time = 0;
    stage = STAGE_0;
}

bool Corn::interact(Person& person){
    // Put corn in the persons inventory if fully grown.
    // Objects of corn should only exsist on the map. 
    if (!isFinished()) return false;
    // Add multiple corns to his inventory.
    person.addToInventory(ID,2);
    return true;
}

bool Corn::isFinished(){
    if (stage == STAGE_FINAL) return true;
    return false;
}

void Corn::update(){
    grow();
}

void Corn::grow(){
    time++;
    if (time < STAGE_0) {
        stage = STAGE_0;
    }
    else if (time < STAGE_1) {
        stage = STAGE_1;
    }
    else if (time < STAGE_2) {
        stage = STAGE_2;
    }
    else if (time == STAGE_FINAL) {
        stage = STAGE_FINAL;
    }
}

int Corn::getStage(){
    return stage;
}

void Corn::reset(){
    time = 0;
    stage = STAGE_0;
}


