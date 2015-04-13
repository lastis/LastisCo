#ifndef __CORN_H_INCLUDED__
#define __CORN_H_INCLUDED__
#include "Item.h"

class Person;
class Corn : public Item{
public:
    Corn();
    void grow();
    void reset();
    void update();
    bool interact(Person& person);
    bool place(Person& person);
    bool canPlace(Person& person);
    bool isFinished();
    int getStage();

    int stage;
    int time;
    static const int STAGE_0 = 2;
    static const int STAGE_1 = 4;
    static const int STAGE_2 = 6;
    static const int STAGE_FINAL = STAGE_2;

};

#endif
