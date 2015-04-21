#include "MetalWall.h"
using namespace blocks;
MetalWall::MetalWall() : Item(WALL,BLOCKING) {
    ID = blocks::WALL_METAL;
}

int MetalWall::getTextureID(){
    return 0;
}

bool MetalWall::interact(Person& person){
    return true;
}

bool MetalWall::place(Person& person){
    return true;
}

bool MetalWall::canPlace(Person& person){
    return true;
}

void MetalWall::update(ShipMaster& ship){

}
