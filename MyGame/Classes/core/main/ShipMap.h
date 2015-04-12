#ifndef __SHIP_MAP_H_INCLUDED__
#define __SHIP_MAP_H_INCLUDED__
#include "../rooms/Room.h"
#include "../map/Pathfinder.h"
#include "../items/Item.h"
#include "../items/ItemCreator.h"
#include "../enteties/Person.h"

class ShipMap {
public:
    ShipMap();
    ShipMap(int O, int N, int M);
    ~ShipMap();
    void updateMapAccess();
    void insertBlocksCenter(int blockID, Location start, Location end);
    void insertBlocksFloor(int blockID, Location start, Location end);
    void insertWallHorizontal(int blockID, Location start, Location end);
    void insertWallVertical(int blockID, Location start, Location end);
    inline void simplifyLocations(Location& loc1, Location& loc2);
    Path findPath(Location start, Location end);

    Room* createRoom(Location* locations, int N, int roomID);
    Path getPathToRoom(int UID, Location start);
    Room* getRoom(int UID);
    Room* getRoom(Location loc);

    bool    placeItem(Item& obj);
    bool    isVacant(int x, int y, int z);
    bool    isVacant(Location loc);
    Item* createItem(int ID);
    Item* getItemFromUID(int UID);
    Item* getItemPendingFromID(int ID);
    // Linked list might need to be replaced by a vector or some other class
    // and this method should probably be replaced by an interator of some sort.
    Item* getItemFromIndex(int i);
    Item* getItemPendingFromIndex(int i);
    /* Item* getItemFromLoc(Location loc); */
    int     getCountItems();
    int     getCountItemsLoose();
    int     getCountItemsPending();
    int     getCountRooms();
    int     getCountCrew();

    Person* addCrewMember(int ID, Location loc);

    unsigned int*** getMap();
    unsigned int*** getMapFloor();
    unsigned int*** getMapEastWalls();
    unsigned int*** getMapNorthWalls();
    unsigned int*** getMapAccess();
    unsigned int*** getMapRooms();
private:
    void initialize(int O, int N, int M);

private:
    int O;
    int N;
    int M;
    int cntCrew;
    int cntRooms;
    int cntUID;
    static const int MAX_ROOMS = 20;
    static const int MAX_CREW = 100;
    Person* crew[MAX_CREW];
    Room* rooms[MAX_ROOMS];
    LinkedList objects;
    LinkedList objectsLoose;
    LinkedList objectsPending;
    // mapAccess uses blocked movement IDs. The others
    // only use block ID to identify what is there. 
    Matrix3D containerMap;
    Matrix3D containerMapFloor;
    Matrix3D containerMapWallsEast;
    Matrix3D containerMapWallsNorth;
    Matrix3D containerMapAccess;
    Matrix3D containerMapRooms;
    unsigned int*** map;
    unsigned int*** mapFloor;
    unsigned int*** mapWallsEast;
    unsigned int*** mapWallsNorth;
    unsigned int*** mapAccess;
    unsigned int*** mapRooms;
    Pathfinder pathfinder;
};
#endif
