#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__
#include "Location.h"
#include "Base.h"
#include "LinkedList.h"

class Room : public Base{
public:
    Room();
    LinkedList objects;
    void addObject(Object& object);
    Location findObjectLocation(int objectID);
    Object* findWithUID(int UID);
    bool removeWithUID(int UID);

    Location center;
    /* char name[10]; */

};
#endif
