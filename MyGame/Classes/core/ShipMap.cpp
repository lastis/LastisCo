#ifdef TESTING
#include <iostream>
#endif
#include "ShipMap.h"

ShipMap::ShipMap(){
    ShipMap(0,0,0);
}

ShipMap::ShipMap(const ShipMap &obj){
    copy(obj);
}

ShipMap::ShipMap(int O, int N, int M){
    this->M = M;
    this->N = N;
    this->O = O;
    allocateMapMemory(O,N,M);
}

ShipMap& ShipMap::operator= (const ShipMap& obj){
    copy(obj);
}

void ShipMap::copy(const ShipMap &obj){
    freeMemory();
    O = obj.O;
    N = obj.N;
    M = obj.M;
    allocateMapMemory(O,N,M);

    for (int i = 0; i < O; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                map[i][j][k] = obj.map[i][j][k];
            }
        }
    }
}

void ShipMap::allocateMapMemory(int O, int N, int M){
	// Allocate memory for pointers
    // This look strange, but think about it writing
    // letter in a book, from bottom and up. 
	unsigned int *ptr1	    = new unsigned int[M*N*O];
	unsigned int **ptr2 	= new unsigned int*[N*O];
	unsigned int ***ptr3 	= new unsigned int**[O];
    ref1 = ptr1;
    ref2 = ptr2;
    ref3 = ptr3;

	map = ptr3;
    for (int i = 0; i < O; i++) {
        for (int j = 0; j < N; j++) {
            ptr2[j] = ptr1;
            ptr1 += M;
        }
        ptr3[i] = ptr2;
        ptr2 += N;
    }
}

void ShipMap::freeMemory(){
    delete[] ref1;
    delete[] ref2;
    delete[] ref3;
}

ShipMap::~ShipMap(){
    freeMemory();
}



















