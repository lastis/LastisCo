#include "Location.h"
struct Node
{
    int x;
    int y;
    int z;
    int fValue;
    int gValue;
    struct Node* link;
    /* int info; */
    Node(){
    }
    Node(Location loc){
        x = loc.x;
        y = loc.y;
        z = loc.z;
    }
    Node(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
