#ifndef __LOCATION_H_INCLUDED__
#define __LOCATION_H_INCLUDED__

/** \brief Custom, simple location class.
 * \ingroup map
 */         
struct Location
{
    int x;
    int y;
    int z;

    Location(){
        x = -1;
        y = -1;
        z = -1;
    }

    Location(const Location &obj){
        copy(obj);
    }

    Location(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Location& operator= (const Location& obj){
        copy(obj);
        return *this;
    }

    void copy(const Location &obj){
        this->x = obj.x;
        this->y = obj.y;
        this->z = obj.z;
    }

};
#endif
