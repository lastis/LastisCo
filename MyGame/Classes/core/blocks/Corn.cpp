#include "Corn.h"

#ifdef TESTING
#include <iostream>
#endif

Corn::Corn(){
    time = 0;
    stage1 = 2;
    stage2 = 4;
    stage3 = 6;
    stageFinal = stage3;
}

void Corn::update(){
    if (planted) grow();
}

void Corn::grow(){
    time++;
    if (time < stage1) {
        stage = stage1;
    }
    else if (time < stage2) {
        stage = stage2;
    }
    else if (time < stage3) {
        stage = stage3;
    }
    else if (time == stageFinal) {
        stage = stageFinal;
    }
}


