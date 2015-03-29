#ifndef __CORN_H_INCLUDED__
#define __CORN_H_INCLUDED__
#include "Object.h"

class Person;
class Corn : public Object{
public:
    Corn();
    void update();
    void grow();
    void interact(Person& person);
    bool isFinished();

    bool planted;
    int stage;
    int stage1;
    int stage2;
    int stage3;
    int stageFinal;
    int time;

};

#endif