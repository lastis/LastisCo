#include "JobFarm.h"


void JobFarm::deligateTask(Person& person){
    if (hasSeeds(person)) {
        sow(person);
        return;
    }
    /* if (grownCrops()){ */
    /*     gather(person); */
    /*     return; */
    /* } */
}

void JobFarm::sow(Person& person){
    
}

bool JobFarm::hasSeeds(Person& person){
    using namespace blocks;
    return person.hasInInventory(CENTER_CORN,1);
}






