namespace directions{
    static const int DIRECTIONS = 6;
    // These assignments are bit values. 
    // Used to interpret directions.
    static const unsigned int NO_DIRECTION = 0;
    static const unsigned int EAST       = 1<<0;//1;
    static const unsigned int NORTH      = 1<<1;//4
    static const unsigned int UP         = 1<<2;//16;
    static const unsigned int WEST       = 1<<3;//2
    static const unsigned int SOUTH      = 1<<4;//8
    static const unsigned int DOWN       = 1<<5;//32;

    // Used to block a given direction. Basically
    // makes a wall in that direction. (Only blocks one way.)
    static const unsigned int BLOCK_NONE    = 0;//0;
    static const unsigned int BLOCK_WEST    = 1<<0;//1;
    static const unsigned int BLOCK_SOUTH   = 1<<1;//4
    static const unsigned int BLOCK_DOWN    = 1<<2;//16;
    static const unsigned int BLOCK_EAST    = 1<<3;//2
    static const unsigned int BLOCK_NORTH   = 1<<4;//8
    static const unsigned int BLOCK_UP      = 1<<5;//32;
    static const unsigned int BLOCK_ALL  = EAST + WEST + NORTH 
                                           + SOUTH + UP + DOWN;
}

namespace blocks{
    // Block types
    static const unsigned int FULL_SPACE = 0;  
    static const unsigned int FULL_AIR = 1;
    static const unsigned int FULL_METAL = 2;
    static const unsigned int WALL_METAL = 3;
    static const unsigned int FLOOR_METAL = 4;

    static const int COUNT = 5;

    namespace properties{
        static const int NON_BLOCKING = 0;
        static const int BLOCKING = 1;
        // Is a block floor, ontop of floor, both(eg. rock), or a wall.
        static const int FLOOR = 0;
        static const int CENTER = 1;
        static const int BOTH = 2;
        static const int WALL = 3;

        // TODO: Make this const array.
        static unsigned int* slots;
        static unsigned int* access;

        static void initArrays(){
            slots = new unsigned int[blocks::COUNT];
            slots[FULL_SPACE]  = BOTH;
            slots[FULL_AIR]    = BOTH;
            slots[FULL_METAL]  = BOTH;
            slots[WALL_METAL]   = WALL;
            slots[FLOOR_METAL]  = FLOOR;

            access = new unsigned int[blocks::COUNT];
            access[FULL_SPACE]  = NON_BLOCKING;
            access[FULL_AIR]    = NON_BLOCKING;
            access[FULL_METAL] = BLOCKING;
            access[WALL_METAL]   = BLOCKING;
            access[FLOOR_METAL]  = BLOCKING;
        }

        static void clearIDs(){
            delete[] slots;
            delete[] access;
        }

    }
}
