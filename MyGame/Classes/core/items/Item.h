#ifndef __OBJECT_H_INCLUDED__
#define __OBJECT_H_INCLUDED__

#include "../Base.h"
#include "../map/Location.h"
#include "../identifiers.h"
// Base class for all objects. Used to be able to make an 
// array of objects.
class Person;
class ShipMaster;
class Item : public Base{
public:
    Item(int slot, int blocking) : placed(false), slot(slot), blocking(blocking)
    {
    }
    virtual ~Item(){};
    void setPlaced(bool val){placed = val;};
    bool isPlaced(){return placed;}
    virtual void update(ShipMaster& ship) = 0;
    virtual bool interact(Person& person) = 0;
    virtual bool place(Person& person) = 0;
    virtual bool canPlace(Person& person) = 0;

    Location loc;
    // Properties of the item.
    int     slot;
    int     blocking;
private:
    bool    placed;
};


struct ItemTest : public Item {
    ItemTest() : Item(0,0){
    }
    bool interact(Person& person){
        // Items that cannot be interacted with should return
        // true, as false means the person is interacting with the
        // object but is not finished yet.
        return true;
    }

    bool place(Person& person){
        // This methods hold the requirements for the person placing
        // it. E.g. remove required items from inventory,
        // subtract from a persons energy. 
        return true;
    }

    bool canPlace(Person& person){
        return true;
    }

    void update(ShipMaster& ship){
    }
};
#endif
