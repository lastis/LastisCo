#ifndef __PATH_H_INCLUDED__
#define __PATH_H_INCLUDED__
#include "../identifiers.h"

class Path {
public:
    Path();
    Path(unsigned int* path, int length);
    ~Path();
    Path(const Path& obj);
    Path& operator= (const Path& obj);
    void copy(const Path& obj);

    unsigned int getNextDirection();
    bool isComplete();
    bool hasPath();
    int getLength();

    unsigned int* path;
    int length;
    int index;
};

#endif 
