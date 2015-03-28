#ifndef __OBJECT_H_INCLUDED__
#define __OBJECT_H_INCLUDED__

#include "../Location.h"
#include "../Base.h"
// Base class for all objects. Used to be able to make an 
// array of objects.
class Object : public Base{
public:
    Object();
    Location loc;

};
#endif
