
static const int MAX_PATH_LENGTH = 20;

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

namespace rooms{
    static const int KITCHEN = 0;
    static const int BRIDGE = 1;
    static const int ENGINE = 2;
    static const int WEAPONS = 3;
}

namespace objects{
    static const int BEER = 0;
}

namespace blocks{
    // Block types
    
    static const unsigned int CENTER_SPACE = 0;  
    static const unsigned int CENTER_AIR = 1;
    static const unsigned int CENTER_METAL = 2;
    static const unsigned int WALL_METAL = 3;
    static const unsigned int FLOOR_METAL = 4;

    static const int COUNT = 5;

    namespace properties{
        static const int NON_BLOCKING = 0;
        static const int BLOCKING = 1;
        // Is a block floor, ontop of floor, both(eg. rock), or a wall.
        static const int FLOOR = 0;
        static const int CENTER = 1;
        static const int WALL = 2;

        // TODO: Make this const array.
        static unsigned int* slots;
        static unsigned int* access;

        static void initArrays(){
            slots = new unsigned int[blocks::COUNT];
            slots[CENTER_SPACE]  = CENTER;
            slots[CENTER_AIR]    = CENTER;
            slots[CENTER_METAL]  = CENTER;
            slots[WALL_METAL]   = WALL;
            slots[FLOOR_METAL]  = FLOOR;

            access = new unsigned int[blocks::COUNT];
            access[CENTER_SPACE]  = NON_BLOCKING;
            access[CENTER_AIR]    = NON_BLOCKING;
            access[CENTER_METAL] = BLOCKING;
            access[WALL_METAL]   = BLOCKING;
            access[FLOOR_METAL]  = BLOCKING;
        }

        static void clearIDs(){
            delete[] slots;
            delete[] access;
        }

    }
}
