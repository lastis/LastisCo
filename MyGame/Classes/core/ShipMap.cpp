#ifdef TESTING
#include <iostream>
#endif
#include "ShipMap.h"

ShipMap::ShipMap(){
    map = NULL;
}

ShipMap::ShipMap(int N, int M, int O){
    allocateMapMemory(N,M,O);
}

bool ShipMap::allocateMapMemory(int N, int M, int O){
	// Allocate memory for pointers
	int ***ptr1 	= new int**[N];
	int **ptr2 	= new int*[N*M];
	int *ptr3	= new int[N*M*O];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M ; j++) {
			ptr2[j] = ptr3;
			ptr3 += O;
		}
		ptr1[i] = ptr2;
		ptr2 += M;
	}
	map = ptr1;
    return true;
}



















