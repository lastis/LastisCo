#include "../identifiers.h"
class ShipMaster {
public:
    ShipMaster();
    ShipMaster(int O, int N, int M);
    void initialize(int O, int N,int M);

    // Item methods.
    bool    placeItem(Item& obj);
    Item*   createItem(int ID);
    Item*   getItemFromUID(int UID);
    Item*   getItemFromIndex(int i);
    Item*   getItemPendingFromID(int ID);
    Item*   getItemPendingFromIndex(int i);
    int     getItemCount();
    int     getItemPendingCount();

    int     getRoomCount();
    int     getCrewCount();

    Path    getPathToRoom(int UID, Location start);

    Person* addCrewMember(int ID, Location loc);

private:
    int O;
    int N;
    int M;
    int cntUID;
    Person* crew[MAX_CREW];
    Room*   rooms[MAX_ROOMS];
};
