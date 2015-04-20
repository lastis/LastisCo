#ifndef __ITEM_CREATOR_H_INCLUDED__
#define __ITEM_CREATOR_H_INCLUDED__
#include "../identifiers.h"
#include "Item.h"
#include "Corn.h"
#include "MetalBlock.h"
#include <iostream>

namespace item_creator{
    // Method to create objects from a given ID.
    static Item* createItem(int ID){
        using namespace blocks;
        switch (ID) {
            case CENTER_METAL : 
                return new MetalBlock();
            case CENTER_CORN : 
                return new Corn();
            default :
                return NULL;
        }
    }

}
#endif
