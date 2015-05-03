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

/** \brief Contains item IDs, and property specifiers.
 *
 * Contains all item IDs as well as flags for specifying if
 * * an item blocks movement,
 * * which space the block occupies, 
 * * identifier for what "group classification" the block has.
 */         
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
    // Slots.
    static const int CENTER = 0;
    static const int FLOOR = 1;
    static const int WALL = 2;

    // Types.
    static const int UNSPECIFIED = 1;
    static const int WEAPONRY = 2;

}
#endif
