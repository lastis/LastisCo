#include "Pathfinder.h"

class ShipMap {
public:
    ShipMap();
    ShipMap(int O, int N, int M);
    ~ShipMap();
    void updateMapAccess();
    unsigned int*** getMap();
    unsigned int*** getMapFloor();
    unsigned int*** getMapEastWalls();
    unsigned int*** getMapNorthWalls();
    unsigned int*** getMapAccess();
private:
    void initialize(int O, int N, int M);

public:
    int O;
    int N;
    int M;
private:
    // Rename these? Not obvious what the internal system is.
    // mapAccess uses blocked movement IDs (each bit is important). The others
    // only use block ID to identify what is there. 
    Matrix3D containerMap;
    Matrix3D containerMapFloor;
    Matrix3D containerMapWallsEast;
    Matrix3D containerMapWallsNorth;
    Matrix3D containerMapAccess;
    unsigned int*** map;
    unsigned int*** mapFloor;
    unsigned int*** mapWallsEast;
    unsigned int*** mapWallsNorth;
    unsigned int*** mapAccess;
    Pathfinder pathfinder;
};
