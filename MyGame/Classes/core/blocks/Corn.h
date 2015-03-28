#ifndef __CORN_H_INCLUDED__
#define __CORN_H_INCLUDED__
#include "../Base.h"

class Corn : public Base{
public:
    Corn();
    void update();
    void grow();

    bool planted;
    int stage;
    int stage1;
    int stage2;
    int stage3;
    int stageFinal;
    int time;

};

#endif
