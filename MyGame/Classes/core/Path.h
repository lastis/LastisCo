#ifndef __PATH_H_INCLUDED__
#define __PATH_H_INCLUDED__
#include "Identifiers.h"

class Path {
public:
    unsigned int* path;
    int length;
    int index;
    Path(unsigned int* path, int length);
    unsigned int getNextDirection();
    bool isComplete();
    bool hasPath();
    int getLength();

};

#endif 
