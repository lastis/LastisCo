#ifndef __LOCATION_H_INCLUDED__
#define __LOCATION_H_INCLUDED__
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

    static int distanceManhatten(Location& loc1, Location& loc2){
        int dx = loc2.x - loc1.x;
        int dy = loc2.y - loc1.y;
        int dz = loc2.z - loc1.z;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        if (dz < 0) dz = -dz;
        return dx + dy + dz;
    }
};
#endif
