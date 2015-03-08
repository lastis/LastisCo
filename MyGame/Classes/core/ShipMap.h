#include "Pathfinder.h"

class ShipMap {
public:
    ShipMap();
    ShipMap(int O, int N, int M);
    ~ShipMap();
    void updateMapAccess();
private:
    void initialize(int O, int N, int M);

public:
    int O;
    int N;
    int M;
private:
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
