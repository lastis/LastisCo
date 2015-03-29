#include "Pathfinder.h"
#include "Room.h"
#include "objects/Object.h"

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

    bool createRoom(Location* locations, int N, int roomID);
    void clearAllRooms();
    Path* getPathToRoom(int UID, Location start);
    Room* getRoom(int UID);
    Room* getRoom(Location loc);

    bool addObject(int ID, Location loc);

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
    int roomCnt;
    static const int MAX_ROOMS = 10;
    Room* rooms[MAX_ROOMS];
    LinkedList objectsLoose;
    // Rename these? Not obvious what the internal system is.
    // mapAccess uses blocked movement IDs (each bit is important). The others
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
