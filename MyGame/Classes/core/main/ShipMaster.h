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

    void update();

    // Map methods.
    bool    isVacant(int x, int y, int z);
    bool    isVacant(Location loc);
    Path    findPath(Location start, Location end);
    unsigned int*** getMapAccess();
    void    updateMapAccess();
    // Depracated?
    void    placeTexture(unsigned int ID, Location loc);
    unsigned int*** getMap();
    unsigned int*** getMapFloor();
    unsigned int*** getMapEastWalls();
    unsigned int*** getMapNorthWalls();
    unsigned int*** getMapRooms();
    unsigned int*** getMapTextures();

    // Item methods.
    bool    placeItem(Item* obj);
    Item*   createItem(int ID, Location loc);
    Item*   createItem(int ID, Location loc, unsigned int direction);
    void    drawItem(Item* obj);
    LinkedList& getItems();
    LinkedList& getItemsFloor();
    LinkedList& getItemsNorthWalls();
    LinkedList& getItemsEastWalls();
    LinkedList& getItemsPending();
    LinkedList& getItemsPendingFloor();
    LinkedList& getItemsPendingNorthWalls();
    LinkedList& getItemsPendingEastWalls();

    LinkedList& getTextureList();
    // Depractaed?
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
    Person* createCrewMember(int ID, Location loc);
    int     getCrewCount();
    Person* getCrewFromIndex(int i);
    Person** getCrew();


    ShipCrew*   shipCrew;
    ShipMap*    shipMap;
    ShipItems*  shipItems;
    ShipJobs*   shipJobs;
    ShipRooms*  shipRooms;
private:
    int O;
    int M;
    int N;
    int itemUID;
    int roomUID;
    
};
#endif
