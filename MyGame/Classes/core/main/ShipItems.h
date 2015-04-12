#include "../items/Item.h"
#include "../items/LinkedList.h"
class ShipItems {
public:
    ShipItems();
    ~ShipItems();

    int     getItemCount();
    int     getItemPendingCount();
    bool    addItemPending(Item& obj);

    Item*   getItemFromUID(int UID);
    Item*   getItemFromIndex(int i);
    Item*   getItemPendingFromID(int ID);
    Item*   getItemPendingFromIndex(int i);

    LinkedList objects;
    LinkedList objectsPending;
};
