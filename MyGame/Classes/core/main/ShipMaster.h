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

/** \brief Main access point for interacting with the game system. 
 * \ingroup main
 *
 *
 * Everything that is contained in the local world should call methods through 
 * this class. Here one can search for a path or create new items for instance. 
 */
class ShipMaster {
public:
    ShipMaster();
    ShipMaster(int O, int N, int M);
    ~ShipMaster();

    void update();

    /** \name LocalWorld methods.
     * \sa ShipMap
     */         
    //@{
    bool    isVacant(int x, int y, int z);
    bool    isVacant(Location loc);
    Path    findPath(Location start, Location end);
    unsigned int*** getMapAccess();
    void    updateMapAccess();
    void    placeTexture(unsigned int ID, Location loc);
    unsigned int*** getMapRooms();
    //@}

    /** \name Item methods.
     * \sa ShipItems
     */         
    //@{
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
    //@}

    /** \name Room methods.
     * Should probably be buildning methods.
     * \sa ShipRooms
     */         
    //@{
    Room*   createRoom(Location* locations, int N, int ID);
    void    placeRoom(Location* locations, int N, int UID);
    Path    getPathToRoom(int UID, Location start);
    Room*   getRoom(Location loc);
    //@}

    /** \name Actor (person) methods.
     * \sa ShipCrew
     */         
    //@{
    Person* createCrewMember(int ID, Location loc);
    int     getCrewCount();
    Person* getCrewFromIndex(int i);
    Person** getCrew();
    //@}


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
