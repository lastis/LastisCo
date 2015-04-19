#ifndef __ITEM_MATRIX_H_INCLUDED__
#define __ITEM_MATRIX_H_INCLUDED__
#include "Item.h"
class ItemMatrix {
public:
    ItemMatrix();
    ~ItemMatrix();
    ItemMatrix(const ItemMatrix &obj);
    ItemMatrix(int O, int N, int M);
    void copy(const ItemMatrix& obj);
    ItemMatrix& operator= (const ItemMatrix& obj);
    void reset();
    Item**** getMatrix();
    Item**   getMatrixFlat();
    int getO();
    int getN();
    int getM();

private:
    void allocateMapMemory(int O, int N, int M);
    void freeMemory();

private:
    // These are used for freeing memeory. A 3D
    // matrix of pointer is a quadrouple pointer.
    Item** ref1;
    Item*** ref2;
    Item**** ref3;
    Item**** matrix;
    Item** matrixFlat;
    int O;
    int N;
    int M;
};
#endif
