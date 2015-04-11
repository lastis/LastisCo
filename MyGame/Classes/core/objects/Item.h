#ifndef __OBJECT_H_INCLUDED__
#define __OBJECT_H_INCLUDED__

#include "../Location.h"
#include "../Base.h"
// Base class for all objects. Used to be able to make an 
// array of objects.
class Person;
class Item : public Base{
public:
    Item():placed(false){};
    void setPlaced(bool val){placed = val;};
    bool isPlaced(){return placed;}
    virtual bool interact(Person& person) = 0;
    virtual bool place(Person& person) = 0;
    virtual bool canPlace(Person& person) = 0;

    Location loc;
private:
    bool placed;
};

struct ItemTest : public Item {
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
};

#endif
