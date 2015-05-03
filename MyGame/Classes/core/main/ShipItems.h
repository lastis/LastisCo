#ifndef __SHIP_ITEMS_H_INCLUDED__
#define __SHIP_ITEMS_H_INCLUDED__
#include "../items/Item.h"
#include "../items/LinkedList.h"
#include "../items/ItemMatrix.h"
#include "../items/ItemCreator.h"
class ShipMaster;
class ShipItems {
public:
    ShipItems();
    ShipItems(int O, int N, int M);
    ~ShipItems();

    void update(ShipMaster& ship);

    Item*   createItem(int ID, int UID, Location loc);
    Item*   createItem(int ID, int UID, Location loc, unsigned int direction);
    bool    placeItem(Item* obj);

    LinkedList& getItems();
    LinkedList& getItemsPending();
    LinkedList& getItemsWeaponry();
    LinkedList& getTextureList();

    Item*   getItemPlacedFromID(int ID);
    Item*   getItemPlacedFromUID(int UID);
    Item*   getItemPlacedFromIndex(int i);
    Item*   getItemPendingFromID(int ID);
    Item*   getItemPendingFromUID(int UID);
    Item*   getItemPendingFromIndex(int i);
    int     getItemPlacedCount();
    int     getItemPendingCount();

    ItemMatrix itemsMapContainer;
    LinkedList itemsPlaced; 
    LinkedList itemsPending;
    LinkedList itemsWeaponry;
    LinkedList textureList;
    LinkedList listUpdate;
    LinkedList*** itemsMap;

};
#endif
