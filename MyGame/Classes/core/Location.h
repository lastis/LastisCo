#ifndef __ROOM__HINCLUDED__
#define __ROOM__HINCLUDED__
struct Location
{
    int x;
    int y;
    int z;

    Location(){
        x = 0;
        y = 0;
        z = 0;
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
    }

    void copy(const Location &obj){
        this->x = obj.x;
        this->y = obj.y;
        this->z = obj.z;
    }
};
#endif
