#ifndef __OBJECT_CREATOR_H_INCLUDED__
#define __OBJECT_CREATOR_H_INCLUDED__
#include "../Identifiers.h"
#include "Item.h"
#include "Corn.h"

namespace object_creator{
    // Method to create objects from a given ID.
    static Item* createItem(int ID){
        using namespace blocks;
        switch (ID) {
            case CENTER_CORN : 
                return new Corn();
            default :
                return NULL;
        }
    }

}
#endif
