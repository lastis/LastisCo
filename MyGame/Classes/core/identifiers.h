#ifndef __IDENTIFIERS_H_INCLUDED__
#define __IDENTIFIERS_H_INCLUDED__

static const int MAX_PATH_LENGTH = 20;
static const int MAX_CREW = 100;

namespace directions{
    static const int DIRECTIONS = 6;
    // These assignments are bit values. 
    // Used to interpret directions.
    static const unsigned int NO_DIRECTION = 0;
    static const unsigned int EAST       = 1<<0;//1
    static const unsigned int NORTH      = 1<<1;//2
    static const unsigned int UP         = 1<<2;//4
    static const unsigned int WEST       = 1<<3;//8
    static const unsigned int SOUTH      = 1<<4;//16
    static const unsigned int DOWN       = 1<<5;//32;

    // Used to block a given direction. Basically
    // makes a wall in that direction.
    static const unsigned int BLOCK_NONE    = 0;//0;
    static const unsigned int BLOCK_WEST    = 1<<0;//1;
    static const unsigned int BLOCK_SOUTH   = 1<<1;//2
    static const unsigned int BLOCK_DOWN    = 1<<2;//4
    static const unsigned int BLOCK_EAST    = 1<<3;//8
    static const unsigned int BLOCK_NORTH   = 1<<4;//16
    static const unsigned int BLOCK_UP      = 1<<5;//32;
    static const unsigned int BLOCK_ALL  = EAST + WEST + NORTH 
                                           + SOUTH + UP + DOWN;
}

namespace textures {
    static const unsigned int NO_TEXTURE = 0;
    static const unsigned int CORN_TEXTURE_1 = 39;
    static const unsigned int CORN_TEXTURE_2 = 38;
    static const unsigned int CORN_TEXTURE_3 = 40;
}

namespace rooms{
    static const int KITCHEN = 1;
    static const int BRIDGE = 2;
    static const int ENGINE = 3;
    static const int WEAPONS = 4;
}

namespace blocks{
    // ID == 0 is used for error checking.
    static const unsigned int CENTER_SPACE = 1;  
    static const unsigned int CENTER_AIR = 2;
    static const unsigned int CENTER_METAL = 3;
    static const unsigned int WALL_METAL = 4;
    static const unsigned int FLOOR_METAL = 5;
    static const unsigned int CENTER_CORN = 6;
    static const int COUNT = 6;

    static const int NON_BLOCKING = 0;
    static const int BLOCKING = 1;
    // Slot types.
    static const int CENTER = 0;
    static const int FLOOR = 1;
    static const int WALL = 2;

    /* static bool initialized = false; */
    /* namespace properties{ */
    /*     static const int NON_BLOCKING = 0; */
    /*     static const int BLOCKING = 1; */
    /*     // Is a block floor, ontop of floor, both(eg. rock), or a wall. */
    /*     static const int CENTER = 0; */
    /*     static const int FLOOR = 1; */
    /*     static const int WALL = 2; */

    /*     // TODO: Make this const array. */
    /*     static unsigned int slots[COUNT+1]; */
    /*     static unsigned int access[COUNT+1]; */
    /*     /1* static unsigned int textureID[COUNT+1]; *1/ */

    /*     static void initialize(){ */
    /*         slots[CENTER_SPACE]     = CENTER; */
    /*         slots[CENTER_AIR]       = CENTER; */
    /*         slots[CENTER_METAL]     = CENTER; */
    /*         slots[WALL_METAL]       = WALL; */
    /*         slots[FLOOR_METAL]      = FLOOR; */
    /*         slots[CENTER_CORN]      = CENTER; */

    /*         access[CENTER_SPACE]    = NON_BLOCKING; */
    /*         access[CENTER_AIR]      = NON_BLOCKING; */
    /*         access[CENTER_METAL]    = BLOCKING; */
    /*         access[WALL_METAL]      = BLOCKING; */
    /*         access[FLOOR_METAL]     = BLOCKING; */
    /*         access[CENTER_CORN]     = BLOCKING; */

    /*         /1* textureID[CENTER_SPACE]    = 0; *1/ */
    /*         /1* textureID[CENTER_AIR]      = 0; *1/ */
    /*         /1* textureID[CENTER_METAL]    = 0; *1/ */
    /*         /1* textureID[WALL_METAL]      = 0; *1/ */
    /*         /1* textureID[FLOOR_METAL]     = 0; *1/ */
    /*         /1* textureID[CENTER_CORN]     = CORN_TEXTURE_1; *1/ */
    /*         initialized = true; */
    /*     } */
    /* } */
}
#endif
