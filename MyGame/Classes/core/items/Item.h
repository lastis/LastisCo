#ifndef __OBJECT_H_INCLUDED__
#define __OBJECT_H_INCLUDED__

#include "../Base.h"
#include "../map/Location.h"
#include "../identifiers.h"
// Base class for all objects. Used to be able to make an 
// array of objects.
class Person;
class ShipMaster;
/**
 * \defgroup items Items
 */
class Item : public Base{
    friend class ShipItems;
public:
    Item(int ID, int slot, int blocking, int type) : 
        type(type),
        slot(slot),
        blocking(blocking), 
        placed(false), 
        direction(directions::NORTH)
    {
        this->ID = ID;
    }
    // Virtual destructor ensures that the destructor is called
    // on child classes.
    virtual ~Item(){};
    
    virtual void    update(ShipMaster& ship) = 0;
    virtual bool    interact(Person& person) = 0;
    virtual bool    place(Person& person) = 0;
    virtual bool    canPlace(Person& person) = 0;
    virtual int     getTextureID() = 0;

    bool isPlaced(){
        return placed;
    }

    Location getLoc(){
        return loc;
    }

    int getDirection(){
        return direction;
    }

    int getBlocking(){
        return blocking;
    }

    int getSlot(){
        return slot;
    }

    Location loc;
protected: 
    // Properties of the item.
    int     type;
    int     slot;
    int     blocking;
    bool    placed;
    int     direction;
};


struct ItemTest : public Item {
    ItemTest() : Item(0,0,0,blocks::UNSPECIFIED){
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

    int getTextureID(){
        return 0;
    }
};
#endif
