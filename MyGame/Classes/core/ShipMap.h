class ShipMap {
private:
    int N;
    int M;
    int O;
    unsigned int*** map;
    // These are used for freeing memeory. 
    unsigned int* ref1;
    unsigned int** ref2;
    unsigned int*** ref3;

public:
    ShipMap();
    ~ShipMap();
    ShipMap(const ShipMap &obj);
    ShipMap(int M, int N, int O);
    void copy(const ShipMap& obj);
    ShipMap& operator= (const ShipMap& obj);

private:
    void allocateMapMemory(int M, int N, int O);
    void freeMemory();
};
