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
    void reset();
    unsigned int*** getMatrix();
    unsigned int*   getMatrixFlat();
    int getO();
    int getN();
    int getM();

private:
    void allocateMapMemory(int O, int N, int M);
    void freeMemory();
};
