class ShipMap {
public:
    ShipMap();
    ShipMap(int N, int M);
private:
    int** map;
    bool allocateMapMemory(int row, int col);
};
