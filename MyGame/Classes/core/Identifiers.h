namespace ID{

    static const int DIRECTIONS = 6;
    // These assignments are bit values. 
    static const unsigned int NO_DIRECTION = 0;
    static const unsigned int EAST       = 1<<0;//1;
    static const unsigned int NORTH      = 1<<1;//4
    static const unsigned int UP         = 1<<2;//16;
    static const unsigned int WEST       = 1<<3;//2
    static const unsigned int SOUTH      = 1<<4;//8
    static const unsigned int DOWN       = 1<<5;//32;

    static const unsigned int BLOCK_WEST    = 1<<0;//1;
    static const unsigned int BLOCK_SOUTH   = 1<<1;//4
    static const unsigned int BLOCK_DOWN    = 1<<2;//16;
    static const unsigned int BLOCK_EAST    = 1<<3;//2
    static const unsigned int BLOCK_NORTH   = 1<<4;//8
    static const unsigned int BLOCK_UP      = 1<<5;//32;
    static const unsigned int BLOCK_ALL  = EAST + WEST + NORTH 
                                           + SOUTH + UP + DOWN;
    static const int FLOOR = 1;
    static const int NORMAL = 2;
    static const int BOTH = 3;
    static const int WALLS = 4;

    namespace blocks{
        static const int COUNT = 5;
        static const unsigned int SPACE = 0;  
        static const unsigned int AIR = 1;
        static const unsigned int WALL_METAL_THICK = 2;
        static const unsigned int WALL_METAL = 3;
        static const unsigned int FLOOR_METAL = 4;
    }

    static unsigned int* arrayIDs;

    static void initIDs(){
        using namespace blocks;
        arrayIDs = new unsigned int[blocks::COUNT];
        arrayIDs[SPACE]  = BOTH;
        arrayIDs[AIR]    = BOTH;
        arrayIDs[WALL_METAL_THICK] = BOTH;
        arrayIDs[WALL_METAL]   = WALLS;
        arrayIDs[FLOOR_METAL]  = FLOOR;
    }

    static void clearIDs(){
        delete[] arrayIDs;
    }
}
