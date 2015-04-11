#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__
#include "Location.h"
#include "Base.h"
#include "LinkedList.h"

class Room : public Base{
public:
    Room();
    void        addItem(Item& object);
    void        deleteItems();
    Location    findItemLocation(int objectID);
    Item*       findWithUID(int UID);
    Item*       removeWithUID(int UID);
    int         getItemCnt();

    Location center;
    LinkedList objects;
};
#endif
