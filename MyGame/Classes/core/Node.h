#include "Location.h"

struct Node{
    int x;
    int y;
    int z;
    int fValue;
    int gValue;
    /* Node* link; */

    Node(){
        x = 0;
        y = 0;
        z = 0;
        fValue = 0;
        gValue = 0;
        /* link = NULL; */
    }

    Node(Location loc){
        x = loc.x;
        y = loc.y;
        z = loc.z;
        fValue = 0;
        gValue = 0;
        /* link = NULL; */
    }
    

    Node(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
        fValue = 0;
        gValue = 0;
        /* link = NULL; */
    }
    Node(const Node &obj){
        copy(obj);
    }


    Node& operator= (const Node& obj){
        copy(obj);
    }

    void copy(const Node &obj){
        x = obj.x;
        y = obj.y;
        z = obj.z;
        fValue = obj.fValue;
        gValue = obj.gValue;
        /* link = obj.link; */
    }
};
