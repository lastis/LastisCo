#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__
#include "Location.h"
#include "Base.h"

class Room : public Base{
public:
    Room();
    Location findObjectLocation(int objectID);

    Location center;
    /* char name[10]; */

};
#endif
