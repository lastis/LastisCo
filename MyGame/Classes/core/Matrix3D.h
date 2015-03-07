class Matrix3D {
public:
private:
    // These are used for freeing memeory. 
    int* ref1;
    int** ref2;
    int*** ref3;
    int*** matrix;
    int* matrixFlat;
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
    void reset();
    int*** getMatrix();
    int*   getMatrixFlat();
    int getO();
    int getN();
    int getM();

private:
    void allocateMapMemory(int O, int N, int M);
    void freeMemory();
};
