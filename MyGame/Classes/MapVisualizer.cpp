#include "MapVisualizer.h"

using namespace cocos2d;

MapVisualizer::MapVisualizer(ShipMaster* ship, TMXTiledMap* mapTiled, Layer* scene) 
    : ship(ship), mapTiled(mapTiled), scene(scene), crew(ship->getCrew()),
        itemsToDraw(ship->getTextureList())
{
    crewSprites = new Sprite*[MAX_CREW];
    crewCount = 0;

    layer1 = mapTiled->getLayer("Layer_1");
    /* auto size = mapTiled->getMapSize(); */
    /* height = size.height; */
    /* width = size.width; */
    /* log("height : %u",height); */
    /* log("width : %u",width); */
    itemsToDraw.resetIterator();
    Item* obj = itemsToDraw.next();
    while (obj != NULL) {
        Location& loc = obj->loc;
        layer1->setTileGID(obj->getTextureID(),Vec2(loc.x,loc.y));
        obj = itemsToDraw.next();
    }
    itemsToDraw.clear();
    addCrewTexture(ship->getCrewCount());
}

void MapVisualizer::addCrewTexture(int count){
    int diff = count - crewCount;
    for (int i = 0; i < diff; i++) {
        Sprite* newCrewSprite = Sprite::create("res/Player.png");
        crewSprites[crewCount+i] = newCrewSprite;
        Person* newCrew = crew[crewCount+i];
        int x = newCrew->loc.x;
        int y = newCrew->loc.y;
        Vec2 realPos = layer1->getPositionAt(Vec2(x,y));
        newCrewSprite->setPosition(realPos);
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
        auto moveTo = MoveTo::create(0.1,realPos);
        crewSprites[i]->runAction(moveTo);
        /* crewSprites[i]->setPosition(realPos); */
    }
    itemsToDraw.resetIterator();
    Item* obj = itemsToDraw.next();
    while (obj != NULL) {
        Location& loc = obj->loc;
        layer1->setTileGID(obj->getTextureID(),Vec2(loc.x,loc.y));
        obj = itemsToDraw.next();
        /* log("y : %u",loc.y); */
    }
    itemsToDraw.clear();
}
MapVisualizer::~MapVisualizer(){
    delete[] crewSprites;
}
