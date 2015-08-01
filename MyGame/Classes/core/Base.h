#ifndef __BASE_H_INCLUDED__
#define __BASE_H_INCLUDED__

/** \brief All objects which have an ID and UID inherit from Base. 
 * \ingroup core
 */         
class Base {
public:
    Base();
    /// Unique ID. Often used to find a spesific object.
    int UID;
    /// ID spesifies the type of the object, useful for casting.
    int ID;
};
#endif
