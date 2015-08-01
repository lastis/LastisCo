#ifndef __MATRIX3D_H_INCLUDED__
#define __MATRIX3D_H_INCLUDED__
/** \brief Custom 3D matrix class.
 * \ingroup map
 */         
class Matrix3D {
public:
private:
    // These are used for freeing memeory. 
    unsigned int* ref1;
    unsigned int** ref2;
    unsigned int*** ref3;
    unsigned int*** matrix;
    unsigned int* matrixFlat;
    int O;
    int N;
    int M;

public:
    Matrix3D();
    ~Matrix3D();
    Matrix3D(const Matrix3D &obj);
    Matrix3D(int O, int N, int M);
    void copy(const Matrix3D& obj);
    Matrix3D& operator= (const Matrix3D& obj);
    /** \brief Sett all values to 0.
     */         
    void reset();
    /** \brief Get the underlying 3d pointer array.
     */         
    unsigned int*** getMatrix();
    /** \brief Get the underlying 1d pointer array.
     */         
    unsigned int*   getMatrixFlat();
    /** \brief Get dim O.
     */         
    int getO();
    /** \brief Get dim N.
     */         
    int getN();
    /** \brief Get dim M.
     */         
    int getM();

private:
    void allocateMapMemory(int O, int N, int M);
    void freeMemory();
};
#endif
