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

    /** \brief Creates a new game and local world. 
     *
     * Initializes instances of the other main classes, ShipCrew, ShipItems,
     * ShipJobs, ShipMap, ShipRooms, ShipWeapons. 
     */         
    ShipMaster(int O, int N, int M);

    ~ShipMaster();

    void update();

    /** \name LocalWorld methods.
     * \sa ShipMap
     */         
    //@{

    /** \brief Check if the main map is occupied by an ID.
     */         
    bool    isVacant(int x, int y, int z);

    /** \brief Check if the main map is occupied by an ID. 
     */
    bool    isVacant(Location loc);

    /** \brief Find a path using the pathfinding algorithm.
     *
     * Max length of the path is set in the globals namespace. 
     * \param start Start location.
     * \param end End location.
     * \return Path object with the path. 
     * \sa globals
     */         
    Path    findPath(Location start, Location end);

    /** \brief See ShipMap
     */         
    unsigned int*** getMapAccess();

    /** \brief Updates the map representing blocked movement.
     *
     * The access map has to be completely rebuilt to be updated.
     * \sa ShipMap
     */         
    void    updateMapAccess();

    /** \brief Not being used.
     *
     * Places an id in the texture matrix, is not used and might not be needed.
     */         
    void    placeTexture(unsigned int ID, Location loc);

    /** \brief Not being used.
     *
     * Get the map of the different buildnings
     */         
    unsigned int*** getMapRooms();
    //@}

    /** \name Item methods.
     * \sa ShipItems
     */         
    //@{

    /** \brief Place an item. 
     *
     * When the items become placed, they are removed from the pending
     * items list and added to a spesific room's object list and
     * the placed item list.
     *
     * \param obj Item to be placed. 
     * \return Was the item placed properly.
     */         
    bool    placeItem(Item* obj);

    /** \brief Main method to create items.
     * 
     * Creates a new item object with the ShipItems#createItem and assigns 
     * it an UID. Direction is north. 
     * \param ID ID of the item from blocks namespace.
     * \param loc Inital Location of the item. 
     * \return Finished item object.
     * \sa blocks
     */         
    Item*   createItem(int ID, Location loc);

    /** \brief Main method to create items.
     * 
     * Creates a new item object with the ShipItems#createItem and assigns 
     * it an UID. 
     * \param ID ID of the item from blocks namespace.
     * \param loc Inital Location of the item. 
     * \param direction Inital direction of the item.
     * \return Finished item object.
     * \sa blocks
     */         
    Item*   createItem(int ID, Location loc, unsigned int direction);

    /** \brief Adds item to the texture list in ShipItems.
     *
     * This list is used for drawing and emptied when drawing is finished. 
     * The drawing algorithm will call Item#getTextureID.
     * \param obj Item to draw.
     */         
    void    drawItem(Item* obj);

    /** \brief Get LinkedList of placed items from ShipItems.
     *
     * As of now all items are contained in this list.
     */         
    LinkedList& getItems();

    /** \brief Get LinkedList of pending items. 
     *
     * Pending items are not placed yet, and can for instance be under 
     * construction.
     */         
    LinkedList& getItemsPending();

    /** \brief Get the texture list.
     *
     * Used to draw the textures. Usually resets the list after it is finished.
     */         
    LinkedList& getTextureList();

    /** \brief Get placed Item from it's ID.
     *
     * \return First item with the matching ID.
     */         
    Item*   getItemPlacedFromID(int ID);

    /** \brief Get placed Item from it's UID.
     *
     * \return First item with the matching UID.
     */         
    Item*   getItemPlacedFromUID(int UID);

    /** \brief Get pending to be placed Item from it's ID.
     *
     * \return First item with the matching ID.
     */         
    Item*   getItemPendingFromID(int ID);

    /** \brief Get pending to be placed Item from it's UID.
     *
     * \return First item with the matching UID.
     */         
    Item*   getItemPendingFromUID(int UID);

    /** \brief Number of placed items.
     */         
    int     getItemPlacedCount();

    /** \brief Number of pending to be placed items.
     */         
    int     getItemPendingCount();
    //@}

    /** \name Room methods.
     * Should probably be buildning methods.
     * \sa ShipRooms
     */         
    //@{

    /** \brief Creates a building at the given locations. 
     *
     * Calls ShipRooms#createRoom and ShipMap#placeRoom. Also assigns the room
     * an UID unique to the room.
     * \param locations Array of locations.
     * \param N Length of array.
     * \param ID ID of the buildning.
     * \return Room object.
     * \sa ShipRooms, ShipMap
     */         
    Room*   createRoom(Location* locations, int N, int ID);

    /** \brief Probably not needed because of createRoom 
     *
     * Places a room in ShipMap
     */         
    void    placeRoom(Location* locations, int N, int UID);

    /** \brief Find a path from start to a buildning.
     *
     * Uses Room#center as goal.
     * \param UID UID of the room.
     * \param start Start location.
     * \return Path object with the path.
     */         
    Path    getPathToRoom(int UID, Location start);

    /** \brief Get a buildning object from a location.
     * \param loc Location
     * \return Room object. Null of not found.
     */         
    Room*   getRoom(Location loc);
    //@}

    /** \name Actor (person) methods.
     * \sa ShipCrew
     */         
    //@{

    /** \brief Create a new Actor.
     *
     * \param ID ID of the race. 
     * \param loc Inital location.
     * \return Created Actor.
     */         
    Person* createCrewMember(int ID, Location loc);

    /** \brief Number of actors.
     */         
    int     getCrewCount();

    /** \brief Get crew from the list of actors in ShipCrew.
     * \return Null if not found.
     */         
    Person* getCrewFromIndex(int i);

    /** \brief Get crew list from ShipCrew.
     */         
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
