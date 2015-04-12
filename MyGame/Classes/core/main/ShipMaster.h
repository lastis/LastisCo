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
    Item*   getItemFromUID(int UID);
    Item*   getItemFromIndex(int i);
    Item*   getItemPendingFromID(int ID);
    Item*   getItemPendingFromIndex(int i);
    int     getItemCount();
    int     getItemPendingCount();

    int     getRoomCount();
    int     getCrewCount();

    Path    getPathToRoom(int UID, Location start);

    Person* addCrewMember(int ID, Location loc);

private:
    int O;
    int N;
    int M;
    int cntUID;
    
    ShipCrew    crew;
    ShipMap     map;
    ShipItems   items;
    ShipJobs    jobs;
    ShipRooms   rooms;
};
