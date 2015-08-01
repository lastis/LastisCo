#ifndef __IDENTIFIERS_H_INCLUDED__
#define __IDENTIFIERS_H_INCLUDED__



/** \brief Global values. 
 */         
namespace globals{
    /** \brief Maximum path length return from the pathfinding algorithm. 
     */         
    const int MAX_PATH_LENGTH = 20;
    /** \brief Maximum number of actors in the local world. 
     */         
    const int MAX_CREW = 100;
}

/** \ingroup core
 * \brief Direction identifiers.
 *
 * The values of the directions are used in the pathfinding algorithm and use
 * bit operations. There are variables 
 */         
namespace directions{
    const int DIRECTIONS = 6; //!< @brief Number of directions.
    // These assignments are bit values. 
    // Used to interpret directions.
    const unsigned int NO_DIRECTION = 0;
    const unsigned int EAST       = 1<<0;//1
    const unsigned int NORTH      = 1<<1;//2
    const unsigned int UP         = 1<<2;//4
    const unsigned int WEST       = 1<<3;//8
    const unsigned int SOUTH      = 1<<4;//16
    const unsigned int DOWN       = 1<<5;//32;

    // Used to block a given direction. Basically
    // makes a wall in that direction.
    /** Box with this value does not block the pathfinder.
     */         
    const unsigned int BLOCK_NONE    = 0; 
    /** Blocks the pathfinder in west direction.
     */         
    const unsigned int BLOCK_WEST    = 1<<0;//1;
    /** Blocks the pathfinder in south direction.
     */         
    const unsigned int BLOCK_SOUTH   = 1<<1;//2
    /** Blocks the pathfinder in down direction.
     */         
    const unsigned int BLOCK_DOWN    = 1<<2;//4
    /** Blocks the pathfinder in east direction.
     */         
    const unsigned int BLOCK_EAST    = 1<<3;//8
    /** Blocks the pathfinder in north direction.
     */         
    const unsigned int BLOCK_NORTH   = 1<<4;//16
    /** Blocks the pathfinder in up direction.
     */         
    const unsigned int BLOCK_UP      = 1<<5;//32;
    /** Blocks the pathfinder in all directions.
     */         
    const unsigned int BLOCK_ALL  = EAST + WEST + NORTH 
        + SOUTH + UP + DOWN;
}

/** \brief Texture IDs.
 * \ingroup core
 *
 * Each id represents the UID of a tile in the tilset. This should match the 
 * UID in Tiled.
 */         
namespace textures {
    const unsigned int NO_TEXTURE = 0;
    const unsigned int CORN_TEXTURE_1 = 39;
    const unsigned int CORN_TEXTURE_2 = 38;
    const unsigned int CORN_TEXTURE_3 = 40;
}

/** \brief Room IDs.
 *
 * This can probably be renamed buildnings in future release.
 */         
namespace rooms{
    const int KITCHEN = 1;
    const int BRIDGE = 2;
    const int ENGINE = 3;
    const int WEAPONS = 4;
}

/** \brief Contains item IDs, and property specifiers.
 * \ingroup core
 *
 * Contains all item IDs as well as flags for specifying if
 * * an item blocks movement,
 * * which space the block occupies, 
 * * identifier for what "group classification" the block has.
 */         
namespace blocks{
    // ID == 0 is used for error checking.
    const unsigned int CENTER_SPACE = 1;  
    const unsigned int CENTER_AIR = 2;
    const unsigned int CENTER_METAL = 3;
    const unsigned int WALL_METAL = 4;
    const unsigned int FLOOR_METAL = 5;
    const unsigned int CENTER_CORN = 6;
    const int COUNT = 6;

    const int NON_BLOCKING = 0;
    const int BLOCKING = 1;
    // Slots.
    const int CENTER = 0;
    const int FLOOR = 1;
    const int WALL = 2;

    // Types.
    const int UNSPECIFIED = 1;
    const int WEAPONRY = 2;

    // Damage target types.
    const int ENTETY = 1;
    const int CONSTRUCT = 2;
    const int CONSTRUCT_SOFT = 3;
    const int SHIELD = 3;
    

}
#endif
