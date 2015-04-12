#include "../rooms/Room.h"
class ShipRooms {
public:
    ShipRooms();

    Room*   createRoom(Location* locations, int N, int roomID);
    Room*   getRoom(int UID);
    Room*   getRoom(Location loc);

    int cntRooms;
    static const int MAX_ROOMS = 20;
    Room*   rooms[MAX_ROOMS];
};
