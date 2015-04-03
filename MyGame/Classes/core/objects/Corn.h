#ifndef __CORN_H_INCLUDED__
#define __CORN_H_INCLUDED__
#include "Object.h"

class Person;
class Corn : public Object{
public:
    Corn();
    void update();
    void grow();
    void reset();
    bool interact(Person& person);
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
