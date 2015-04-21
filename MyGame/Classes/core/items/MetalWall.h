#ifndef __METAL_WALL_H_INCLUDED__
#define __METAL_WALL_H_INCLUDED__
#include "Item.h"

class Person;
class ShipMaster;
class MetalWall : public Item{
public:
    MetalWall();
    void update(ShipMaster& ship);
    bool interact(Person& person);
    bool place(Person& person);
    bool canPlace(Person& person);
    int getTextureID();
};

#endif
