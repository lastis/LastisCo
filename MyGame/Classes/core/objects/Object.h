#ifndef __OBJECT_H_INCLUDED__
#define __OBJECT_H_INCLUDED__

#include "../Location.h"
#include "../Base.h"
// Base class for all objects. Used to be able to make an 
// array of objects.
class Person;
class Object : public Base{
public:
    Object():placed(false){};
    void setPlaced(bool val){placed = val;};
    bool isPlaced(){return placed;}
    virtual bool interact(Person& person) = 0;

    Location loc;
private:
    bool placed;
};

struct ObjectTest : public Object {
    bool interact(Person& person){
        // Objects that cannot be interacted with should return
        // true, as false has the meaning "work in progress".
        return true;
    }
};

#endif
