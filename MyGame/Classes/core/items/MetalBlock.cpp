#include "MetalBlock.h"
using namespace blocks;
MetalBlock::MetalBlock() : Item(CENTER,BLOCKING) {
}

bool MetalBlock::interact(Person& person){
    return true;
}

bool MetalBlock::place(Person& person){
    return true;
}

bool MetalBlock::canPlace(Person& person){
    return true;
}

void MetalBlock::update(ShipMaster& ship){

}
