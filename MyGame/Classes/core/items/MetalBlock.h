#ifndef __METAL_BLOCK_H_INCLUDED__
#define __METAL_BLOCK_H_INCLUDED__
#include "Item.h"

class Person;
class ShipMaster;
class MetalBlock : public Item{
public:
    MetalBlock();
    void update(ShipMaster& ship);
    bool interact(Person& person);
    bool place(Person& person);
    bool canPlace(Person& person);
};

#endif
