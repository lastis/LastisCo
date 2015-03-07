class ShipMap {
public:
    int O;
    int N;
    int M;
    unsigned int*** map;
private:
    // These are used for freeing memeory. 
    unsigned int* ref1;
    unsigned int** ref2;
    unsigned int*** ref3;

public:
    ShipMap();
    ~ShipMap();
    ShipMap(const ShipMap &obj);
    ShipMap(int O, int N, int M);
    void copy(const ShipMap& obj);
    ShipMap& operator= (const ShipMap& obj);

private:
    void allocateMapMemory(int O, int N, int M);
    void freeMemory();
};
