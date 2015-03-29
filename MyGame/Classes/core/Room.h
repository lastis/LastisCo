#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__
#include "Location.h"
#include "Base.h"
#include "LinkedList.h"

class Room : public Base{
public:
    Room();
    void        addObject(Object& object);
    void        deleteObjects();
    Location    findObjectLocation(int objectID);
    Object*     findWithUID(int UID);
    bool        removeWithUID(int UID);
    int         getObjectCnt();

    Location center;
    LinkedList objects;
    /* char name[10]; */

};
#endif
