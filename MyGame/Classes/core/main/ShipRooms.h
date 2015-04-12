#include "../rooms/Room.h"
class ShipRooms {
public:
    ShipRooms();

    Room*   createRoom(Location locations, int ID, int UID);
    Room*   getRoom(int UID);
    int     getRoomCount();
    bool    isFull();

    static const int MAX_ROOMS = 20;
    int cntRooms;
    Room*   rooms[MAX_ROOMS];
};
