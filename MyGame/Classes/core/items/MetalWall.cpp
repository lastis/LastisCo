#include "MetalWall.h"
using namespace blocks;
MetalWall::MetalWall() : Item(blocks::WALL_METAL,WALL,BLOCKING) {
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
