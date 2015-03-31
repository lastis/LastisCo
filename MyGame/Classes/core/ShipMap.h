#include "Pathfinder.h"
#include "Room.h"
#include "objects/Object.h"
#include "objects/ObjectCreator.h"
#include "Person.h"

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

    Room* createRoom(Location* locations, int N, int roomID);
    Path* getPathToRoom(int UID, Location start);
    Room* getRoom(int UID);
    Room* getRoom(Location loc);

    bool    placeObject(Object& obj, Location loc);
    Object* createObject(int ID, Location loc);
    Object* getObjectFromUID(int UID);
    Object* getObjectPendingFromID(int ID);
    // Linked list might need to be replaced by a vector or some other class
    // and this method should probably be replaced by an interator of some sort.
    Object* getObjectFromIndex(int i);
    Object* getObjectPendingFromIndex(int i);
    /* Object* getObjectFromLoc(Location loc); */
    int     getCountObjects();
    int     getCountObjectsLoose();
    int     getCountObjectsPending();
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

public:
    int O;
    int N;
    int M;
private:
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
