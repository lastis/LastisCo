#include "ItemMatrix.h"
#include <iostream>

ItemMatrix::ItemMatrix(){
    O = 1;
    N = 1;
    M = 1;
    allocateMapMemory(O,N,M);
    reset();
}

ItemMatrix::ItemMatrix(const ItemMatrix &obj){
    copy(obj);
}

ItemMatrix::ItemMatrix(int O, int N, int M){
    this->M = M;
    this->N = N;
    this->O = O;
    allocateMapMemory(O,N,M);
    reset();
}


ItemMatrix& ItemMatrix::operator= (const ItemMatrix& obj){
    copy(obj);
}

void ItemMatrix::reset(){
    for (int i = 0; i < O; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                matrix[i][j][k].clear();
            }
        }
    }
}

LinkedList*** ItemMatrix::getMatrix(){
    return matrix;
}

LinkedList*   ItemMatrix::getMatrixFlat(){
    return matrixFlat;
}
int ItemMatrix::getO(){
    return O;
}

int ItemMatrix::getN(){
    return N;
}

int ItemMatrix::getM(){
    return M;
}

void ItemMatrix::copy(const ItemMatrix &obj){
    freeMemory();
    O = obj.O;
    N = obj.N;
    M = obj.M;
    allocateMapMemory(O,N,M);

    for (int i = 0; i < O; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                matrix[i][j][k] = obj.matrix[i][j][k];
            }
        }
    }
}

void ItemMatrix::allocateMapMemory(int O, int N, int M){
	// Allocate memory for pointers
	LinkedList*   ptr1   = new LinkedList[M*N*O];
	LinkedList**  ptr2   = new LinkedList*[N*O];
	LinkedList*** ptr3   = new LinkedList**[O];
    ref1 = ptr1;
    ref2 = ptr2;
    ref3 = ptr3;

    matrixFlat = ptr1;
	matrix = ptr3;
    for (int i = 0; i < O; i++) {
        for (int j = 0; j < N; j++) {
            ptr2[j] = ptr1;
            ptr1 += M;
        }
        ptr3[i] = ptr2;
        ptr2 += N;
    }
}

void ItemMatrix::freeMemory(){
    delete[] ref1;
    delete[] ref2;
    delete[] ref3;
}

ItemMatrix::~ItemMatrix(){
    freeMemory();
}



















