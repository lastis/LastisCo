#ifndef __OBJECT_H_INCLUDED__
#define __OBJECT_H_INCLUDED__

#include "../Location.h"
#include "../Base.h"
// Base class for all objects. Used to be able to make an 
// array of objects.
class Person;
class Object : public Base{
public:
    Object();
    virtual void interact(Person& person) = 0;

    Location loc;

};

struct ObjectTest : public Object {
    void interact(Person& person){
        return;
    }
};

#endif
