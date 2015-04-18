#ifndef __MAP_VISUALIZER_H__
#define __MAP_VISUALIZER_H__

#include "cocos2d.h"
#include "core/main/ShipMaster.h"
#include "../cocos2d/cocos/2d/CCTMXTiledMap.h"
using namespace cocos2d;

class MapVisualizer {
public:
    MapVisualizer(ShipMaster* ship, TMXTiledMap* mapTiled, Layer* scene);
    void update();

    unsigned int*** mapTextures;
    int width;
    int height;
    ShipMaster* ship;
    TMXTiledMap* mapTiled;
    Layer* scene;

};
#endif
