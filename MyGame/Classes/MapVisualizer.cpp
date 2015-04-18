#include "MapVisualizer.h"

using namespace cocos2d;

MapVisualizer::MapVisualizer(ShipMaster* ship, TMXTiledMap* mapTiled, Layer* scene) 
    : ship(ship), mapTiled(mapTiled), scene(scene), crew(ship->getCrew())
{
    crewCount = ship->getCrewCount();
    crewSprites = new Sprite*[MAX_CREW];

    mapTextures = ship->getMapTextures();
    layer1 = mapTiled->getLayer("Layer_1");
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
    addCrewTexture(crewCount);
}

void MapVisualizer::addCrewTexture(int count){
    int diff = count - crewCount;
    for (int i = 0; i < diff; i++) {
        Sprite* newCrewSprite = Sprite::create("res/Player.png");
        crewSprites[crewCount+i] = newCrewSprite;
        Person* newCrew = crew[crewCount+i];
        int x = newCrew->loc.x;
        int y = newCrew->loc.y;
        /* Vec2 realPos = layer1->getPositionAt(Vec2(x,y)); */
        /* newCrewSprite->setPosition(realPos); */
        scene->addChild(newCrewSprite);
    }
    crewCount = count;
}

void MapVisualizer::update(){
    // Copy the whole map from the ship to the TMX map.
    int newCrewCount = ship->getCrewCount();
    if (newCrewCount > crewCount) addCrewTexture(newCrewCount);
    for (int i = 0; i < crewCount; i++) {
        Person* crewMember = crew[i];
        int x = crewMember->loc.x;
        int y = crewMember->loc.y;
        Vec2 realPos = layer1->getPositionAt(Vec2(x,y));
        /* crewSprites[i]->setPosition(realPos); */
        /* crewSprites[i]->setPosition(100,100); */
        /* auto moveTo = MoveTo::create(0.1,Vec2(x,y)); */
        /* crewSprites[i]->runAction(moveTo); */
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            layer1->setTileGID(mapTextures[1][j][i],Vec2(i,j));
        }
    }
}
MapVisualizer::~MapVisualizer(){
    delete[] crewSprites;
}
