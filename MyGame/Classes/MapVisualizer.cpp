#include "MapVisualizer.h"

using namespace cocos2d;

MapVisualizer::MapVisualizer(ShipMaster* ship, TMXTiledMap* mapTiled) 
    : ship(ship),
    mapTiled(mapTiled)
{
    mapTextures = ship->getMapTextures();
    auto layer1 = mapTiled->getLayer("Layer_1");
    auto size = mapTiled->getMapSize();
    height = size.height;
    width = size.width;
    log("height : %u",height);
    log("width : %u",width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            layer1->setTileGID(mapTextures[1][j][i],Vec2(i,j));
        }
    }

    /* unsigned int gid = layer1->getTileGIDAt(Vec2(0,0)); */
    /* layer1->setTileGID(30,Vec2(0,2)); */
    /* layer1->setTileGID(30,Vec2(0,3)); */
    /* log("GID : %u",gid); */

}

void MapVisualizer::update(){
    // Copy the whole map from the ship to the TMX map.
    auto layer1 = mapTiled->getLayer("Layer_1");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            layer1->setTileGID(mapTextures[1][j][i],Vec2(i,j));
        }
    }
}
