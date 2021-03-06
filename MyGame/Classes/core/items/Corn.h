#ifndef __CORN_H_INCLUDED__
#define __CORN_H_INCLUDED__
#include "Item.h"

class Person;
class ShipMaster;
class Corn : public Item{
public:
    Corn();
    void grow();
    void reset();
    void update(ShipMaster& ship);
    int getTextureID();
    void update();
    bool interact(Person& person);
    bool place(Person& person);
    bool canPlace(Person& person);
    bool isFinished();
    int getStage();

    bool changed;
    int stage;
    int time;
    static const int STAGE_0 = 5;
    static const int STAGE_1 = 10;
    static const int STAGE_2 = 15;
    static const int STAGE_FINAL = STAGE_2;

};

#endif
