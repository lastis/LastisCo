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

/** \mainpage A simple manual
 *
 * Some general info.
 *
 * This manual is divided in the following sections:
 * - \subpage intro
 * - \subpage advanced "Advanced usage"
 */

/** \page intro Introduction
 * This page introduces the user to the topic.
 * Now you can proceed to the \ref advanced "advanced section".
 * */


/** Brief description of master.
 * \defgroup main Main
 * \ingroup main
 */

/** Here is ShipMaster
 * \ingroup main
 */
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
    void    placeTexture(unsigned int ID, Location loc);
    unsigned int*** getMapRooms();

    // Item methods.
    bool    placeItem(Item* obj);
    Item*   createItem(int ID, Location loc);
    Item*   createItem(int ID, Location loc, unsigned int direction);
    void    drawItem(Item* obj);
    LinkedList& getItems();
    LinkedList& getItemsPending();
    LinkedList& getTextureList();
    Item*   getItemPlacedFromID(int ID);
    Item*   getItemPlacedFromUID(int UID);
    Item*   getItemPendingFromID(int ID);
    Item*   getItemPendingFromUID(int UID);
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
