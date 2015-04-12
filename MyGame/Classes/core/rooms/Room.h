#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__
#include "../Base.h"
#include "../map/Location.h"
#include "../items/LinkedList.h"

class Room : public Base{
public:
    Room();
    void        addItem(Item& object);
    void        deleteItems();
    Item*       getItemWithUID(int UID, bool remove);
    int         getItemCnt();
    Item*       removeWithUID(int UID);

    Location center;
    LinkedList objects;
};
#endif
