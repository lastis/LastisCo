#ifndef __MAP_VISUALIZER_H__
#define __MAP_VISUALIZER_H__

#include "cocos2d.h"
#include "core/main/ShipMaster.h"
#include "core/identifiers.h"
#include "core/enteties/Person.h"
using namespace cocos2d;

class MapVisualizer {
public:
    MapVisualizer(ShipMaster* ship, TMXTiledMap* mapTiled, Layer* scene);
    ~MapVisualizer();
    void update();
    void addCrewTexture(int amount);

    unsigned int*** mapTextures;
    int width;
    int height;
    ShipMaster* ship;
    TMXTiledMap* mapTiled;
    Layer* scene;
    TMXLayer* layer1;
    int crewCount;
    Person** crew;
    Sprite** crewSprites;


};
#endif
