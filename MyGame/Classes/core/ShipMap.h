class ShipMap {
public:
    ShipMap();
    ShipMap(int N, int M, int O);
private:
    int*** map;
    bool allocateMapMemory(int N, int M, int O);
};
