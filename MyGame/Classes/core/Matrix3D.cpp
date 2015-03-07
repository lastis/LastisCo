#ifdef TESTING
#include <iostream>
#endif
#include "Matrix3D.h"

Matrix3D::Matrix3D(){
    Matrix3D(0,0,0);
}

Matrix3D::Matrix3D(const Matrix3D &obj){
    copy(obj);
}

Matrix3D::Matrix3D(int O, int N, int M){
    this->M = M;
    this->N = N;
    this->O = O;
    allocateMapMemory(O,N,M);
    reset();
}


Matrix3D& Matrix3D::operator= (const Matrix3D& obj){
    copy(obj);
}

void Matrix3D::reset(){
    for (int i = 0; i < O; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                matrix[i][j][k] = 0;
            }
        }
    }
}

int*** Matrix3D::getMatrix(){
    return matrix;
}
int*   Matrix3D::getMatrixFlat(){
    return matrixFlat;
}
int Matrix3D::getO(){
    return O;
}

int Matrix3D::getN(){
    return N;
}

int Matrix3D::getM(){
    return M;
}

void Matrix3D::copy(const Matrix3D &obj){
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

void Matrix3D::allocateMapMemory(int O, int N, int M){
	// Allocate memory for pointers
    // This look strange, but think about it writing
    // letter in a book, from bottom and up. 
	int *ptr1	    = new int[M*N*O];
	int **ptr2 	    = new int*[N*O];
	int ***ptr3 	= new int**[O];
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

void Matrix3D::freeMemory(){
    delete[] ref1;
    delete[] ref2;
    delete[] ref3;
}

Matrix3D::~Matrix3D(){
    freeMemory();
}



















