#include "Pathfinder.h"

class ShipMap {
public:
    ShipMap();
    ShipMap(int O, int N, int M);
    ~ShipMap();
private:

public:
private:
    Matrix3D map;
    Matrix3D mapBlocking;
    Pathfinder pathfinder;
};
