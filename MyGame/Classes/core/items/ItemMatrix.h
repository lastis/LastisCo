#ifndef __ITEM_MATRIX_H_INCLUDED__
#define __ITEM_MATRIX_H_INCLUDED__
#include "LinkedList.h"
class ItemMatrix {
public:
    ItemMatrix();
    ~ItemMatrix();
    ItemMatrix(const ItemMatrix &obj);
    ItemMatrix(int O, int N, int M);
    void copy(const ItemMatrix& obj);
    ItemMatrix& operator= (const ItemMatrix& obj);
    void reset();
    LinkedList*** getMatrix();
    LinkedList*   getMatrixFlat();
    int getO();
    int getN();
    int getM();

private:
    void allocateMapMemory(int O, int N, int M);
    void freeMemory();

private:
    LinkedList* ref1;
    LinkedList** ref2;
    LinkedList*** ref3;
    LinkedList*** matrix;
    LinkedList* matrixFlat;
    int O;
    int N;
    int M;
};
#endif
