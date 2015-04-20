#ifndef __SHIP_ITEMS_H_INCLUDED__
#define __SHIP_ITEMS_H_INCLUDED__
#include "../items/Item.h"
#include "../items/LinkedList.h"
#include "../items/ItemCreator.h"
class ShipMaster;
class ShipItems {
public:
    ShipItems();
    ~ShipItems();

    void update(ShipMaster& ship);

    Item*   createItem(int ID, int UID, Location loc);
    Item*   createItem(int ID, int UID, Location loc, unsigned int direction);
    bool    placeItem(Item* obj);

    LinkedList& getItems();
    LinkedList& getItemsFloor();
    LinkedList& getItemsNorthWalls();
    LinkedList& getItemsEastWalls();
    LinkedList& getItemsPending();
    LinkedList& getItemsPendingFloor();
    LinkedList& getItemsPendingNorthWalls();
    LinkedList& getItemsPendingEastWalls();

    LinkedList& getTextureList();

    // Depracated?
    Item*   getItemPlacedFromID(int ID);
    Item*   getItemPlacedFromUID(int UID);
    Item*   getItemPlacedFromIndex(int i);
    Item*   getItemPendingFromID(int ID);
    Item*   getItemPendingFromUID(int uID);
    Item*   getItemPendingFromIndex(int i);

    int     getItemPlacedCount();
    int     getItemPendingCount();

    LinkedList itemsPlaced;
    LinkedList itemsFloor;
    LinkedList itemsEastWalls;
    LinkedList itemsNorthWalls;
    LinkedList itemsPending;
    LinkedList itemsPendingFloor;
    LinkedList itemsPendingNorthWalls;
    LinkedList itemsPendingEastWalls;

    LinkedList textureList;
};
#endif
