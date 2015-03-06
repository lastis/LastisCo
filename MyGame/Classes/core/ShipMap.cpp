#ifdef TESTING
#include <iostream>
#endif
#include "ShipMap.h"

ShipMap::ShipMap(){
    map = NULL;
}

ShipMap::ShipMap(const ShipMap &obj){
    copy(obj);
}

ShipMap::ShipMap(int M, int N, int O){
    this->M = M;
    this->N = N;
    this->O = O;
    allocateMapMemory(N,M,O);
}

ShipMap& ShipMap::operator= (const ShipMap& obj){
    copy(obj);
}

void ShipMap::copy(const ShipMap &obj){
    freeMemory();
    M = obj.M;
    N = obj.N;
    O = obj.O;
    allocateMapMemory(M,N,O);
}

void ShipMap::allocateMapMemory(int M, int N, int O){
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



















