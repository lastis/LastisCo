#ifndef __PATH_H_INCLUDED__
#define __PATH_H_INCLUDED__
#include "../identifiers.h"

/** \brief Contains a path, usually from a pathfinding algorithm.
 * \ingroup map
 */         
class Path {
public:
    Path();

    /** \brief Constructor
     *
     *  The length of path can be longer than length.
     * \param path Unsigned int array of directions.
     * \param length Length of the array.
     */         
    Path(unsigned int* path, int length);

    ~Path();

    Path(const Path& obj);

    Path& operator= (const Path& obj);

    void copy(const Path& obj);

    /** \brief Get the next direction.
     * \sa directions.
     */         
    unsigned int getNextDirection();

    /** Check if the path has given it last direction.
     */         
    bool isComplete();

    /** Check if a path has been assigned to the object.
     */         
    bool hasPath();

    /** Get the length of the path. 
     */         
    int getLength();

    unsigned int* path;
    int length;
    int index;
};

#endif 
