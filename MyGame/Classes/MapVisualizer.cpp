#include "MapVisualizer.h"

using namespace cocos2d;

MapVisualizer::MapVisualizer(ShipMaster& ship, TMXTiledMap* mapTiled) 
    : ship(ship),
    mapTiled(mapTiled)
{
    auto layer1 = mapTiled->getLayer("Layer_1");
    unsigned int gid = layer1->getTileGIDAt(Vec2(0,0));
    layer1->setTileGID(30,Vec2(0,1));
    layer1->setTileGID(30,Vec2(0,2));
    layer1->setTileGID(30,Vec2(0,3));
    log("GID : %u",gid);

}

void MapVisualizer::update(){
    // Copy the whole map from the ship to the TMX map.
    

}
