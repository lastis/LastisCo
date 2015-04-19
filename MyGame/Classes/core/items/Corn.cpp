#include "Corn.h"
#include "../enteties/Person.h"
#include "../identifiers.h"
#include "../main/ShipMaster.h"
#include <iostream>

using namespace blocks::properties;

// The first argument in the parent class is what
// slot the items occupies, center for corn and
// the second paramter is if it blocks movement.
Corn::Corn() : Item(CENTER,NON_BLOCKING){
    ID = blocks::CENTER_CORN;
    time = 0;
    stage = STAGE_0;
    changed = true;
}

bool Corn::interact(Person& person){
    // Put corn in the persons inventory if fully grown.
    if (!isFinished()) return false;
    // Add multiple corns to his inventory.
    person.addToInventory(ID,2);
    time = 0;
    stage = STAGE_0;
    return true;
}

bool Corn::place(Person& person){
    // Remove corn (seeds) from the persons inventory.
    bool enoughSeeds = person.takeFromInventory(ID, 1);
    if (!enoughSeeds) return false;
    // Put the object in placed state.
    setPlaced(true);
    return true;
}

bool Corn::canPlace(Person& person){
    return person.hasInInventory(ID,1);
}

bool Corn::isFinished(){
    if (stage == STAGE_FINAL) return true;
    return false;
}

void Corn::update(ShipMaster& ship){
    using namespace textures;
    if (isPlaced() == false) return;
    grow();
    if (changed == false) return;
    switch (stage){
        case STAGE_0:
        ship.placeTexture(CORN_TEXTURE_1,loc);
        break;
        case STAGE_1:
        ship.placeTexture(CORN_TEXTURE_2,loc);
        break;
        case STAGE_2:
        ship.placeTexture(CORN_TEXTURE_3,loc);
        break;
    }
}

void Corn::update(){
    if (isPlaced() == false) return;
    grow();
}

void Corn::grow(){
    time++;
    if (time == STAGE_0) {
        stage = STAGE_0;
        changed = true;
    }
    else if (time == STAGE_1) {
        stage = STAGE_1;
        changed = true;
    }
    else if (time == STAGE_2) {
        stage = STAGE_2;
        changed = true;
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


