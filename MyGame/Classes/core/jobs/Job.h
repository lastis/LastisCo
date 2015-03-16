#ifndef __JOB_H_INCLUDED__
#define __JOB_H_INCLUDED__
// Forward declare.
class ShipMap;

class Job {
public:
    ShipMap* map;
    Job();
    void setShipMap(ShipMap* map);

};

#endif
