#ifndef __SHIP_MASTER_H_INCLUDED__
#define __SHIP_MASTER_H_INCLUDED__
#include "ShipCrew.h"
#include "ShipItems.h"
#include "ShipJobs.h"
#include "ShipMap.h"
#include "ShipRooms.h"
#include "../identifiers.h"
#include "../map/Path.h"
#include "../map/Location.h"
#include "../items/Item.h"
#include "../items/ItemCreator.h"
class ShipMaster {
public:
    ShipMaster();
    ShipMaster(int O, int N, int M);
    ~ShipMaster();

    // Map methods.
    bool    isVacant(int x, int y, int z);
    bool    isVacant(Location loc);
    Path    findPath(Location start, Location end);

    // Item methods.
    bool    placeItem(Item& obj);
    Item*   createItem(int ID, Location loc);
    Item*   getItemPlacedFromID(int ID);
    Item*   getItemPlacedFromUID(int UID);
    Item*   getItemPlacedFromIndex(int i);
    Item*   getItemPendingFromID(int ID);
    Item*   getItemPendingFromUID(int UID);
    Item*   getItemPendingFromIndex(int i);
    int     getItemPlacedCount();
    int     getItemPendingCount();

    // Room methods.
    Room*   createRoom(Location* locations, int N, int ID);
    void    placeRoom(Location* locations, int N, int UID);
    Path    getPathToRoom(int UID, Location start);
    Room*   getRoom(Location loc);

    // Crew methods.
    Person* addCrewMember(int ID, Location loc);



    ShipCrew*   shipCrew;
    ShipMap*    shipMap;
    ShipItems*  shipItems;
    ShipJobs*   shipJobs;
    ShipRooms*  shipRooms;
private:
    int O;
    int N;
    int M;
    int itemUID;
    int roomUID;
    
};
#endif
