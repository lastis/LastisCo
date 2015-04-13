#ifndef __SHIP_ROOMS_H_INCLUDED__
#define __SHIP_ROOMS_H_INCLUDED__
#include "../rooms/Room.h"
class ShipRooms {
public:
    ShipRooms();
    ~ShipRooms();

    Room*   createRoom(Location locations, int ID, int UID);
    Room*   getRoom(int UID);
    int     getRoomCount();
    bool    isFull();

    static const int MAX_ROOMS = 20;
    int     cntRooms;
    Room*   rooms[MAX_ROOMS];
};
#endif
