#include "ShipMap.h"
#include <iostream>

ShipMap::ShipMap(){
    map = NULL;
}

ShipMap::ShipMap(int N, int M){
    allocateMapMemory(N,M);
}

bool ShipMap::allocateMapMemory(int row, int col){
    // Allocate memory for pointers
    int **arr = new int* [row];
    if(!arr) { 
        map = NULL;
        return false;
    }
    // Allocate memory for the whole array
    int *ptr  = new int[row*col];
    if(!ptr) {    
        map = NULL;
        return false;
    }
    // Assign pointers to the correct rows
    for (int i = 0; i < row; i++) {
        arr[i] = ptr; 
        ptr   += col;
    }
    map = arr;
    return true;
}

