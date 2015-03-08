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
private:
    Matrix3D map;
    Matrix3D mapFloor;
    Matrix3D mapWallsEast;
    Matrix3D mapWallsNorth;
    Matrix3D mapAccess;
    Pathfinder pathfinder;
};
