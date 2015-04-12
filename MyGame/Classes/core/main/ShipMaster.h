#include "ShipCrew.h"
#include "ShipItems.h"
#include "ShipJobs.h"
#include "ShipMap.h"
#include "ShipRooms.h"
#include "../identifiers.h"
#include "../map/Path.h"
#include "../map/Location.h"
#include "../items/Item.h"
class ShipMaster {
public:
    ShipMaster();
    ShipMaster(int O, int N, int M);

    // Item methods.
    bool    placeItem(Item& obj);
    Item*   createItem(int ID);

    // Room methods.
    Room*   createRoom(Location* locations, int N, int roomID);
    Path    getPathToRoom(int UID, Location start);
    Room*   getRoom(Location loc);

    // Crew methods.
    Person* addCrewMember(int ID, Location loc);



private:
    int O;
    int N;
    int M;
    int itemUID;
    int roomUID;
    
    ShipCrew    crew;
    ShipMap     map;
    ShipItems   items;
    ShipJobs    jobs;
    ShipRooms   rooms;
};
