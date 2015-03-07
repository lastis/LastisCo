#include "Location.h"
struct Node
{
    Location info;
    int priority;
    struct Node* link;
    /* int info; */
    Node(Location loc){
        info = loc;
    }
};
