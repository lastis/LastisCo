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
    static const int LOW = 1;
    static const int HIGH = 2;
    static const int BOTH = 3;
    static const int FULL = 4;

    static const int COUNT = 5;

    static const unsigned int SPACE = 0;  
    static const unsigned int AIR = 1;
    static const unsigned int THICK_WALL = 2;
    static const unsigned int WALL = 3;
    static const unsigned int FLOOR = 4;

    static unsigned int* arrayIDs;

    static void initIDs(){
        arrayIDs = new unsigned int[COUNT];
        arrayIDs[SPACE]  = BOTH;
        arrayIDs[AIR]    = BOTH;
        arrayIDs[THICK_WALL]    = FULL;
        arrayIDs[WALL]   = HIGH;
        arrayIDs[FLOOR]  = LOW;
    }

    static void clearIDs(){
        delete[] arrayIDs;
    }
}
