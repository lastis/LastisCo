#include "HelloWorldScene.h"
 
using namespace cocos2d;
 
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    Scene* scene = Scene::create();
 
    // 'layer' is an autorelease object
    HelloWorld* layer = HelloWorld::create(); 
 
    // add layer as a child to scene
    scene->addChild(layer);
 
    // return the scene
    return scene;
}

void HelloWorld::update(float dt){
    time += dt;
    if (time < 0.10) return;
    time = 0;
    ship->update();
    mapVis->update();

}
 
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    time = 0;
    ship = new ShipMaster(3,20,20);

    // The ship has job farm implemented and will run it on all persons
    // added to the object.
    int crewID = 1;
    Location loc1 = Location(1,1,1);
    Person* person = ship->createCrewMember(crewID,loc1);
    person->addToInventory(blocks::CENTER_CORN,1);
    // Make a 10x10 field of corn that we want to be sowed.
    int crops = 100;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ship->createItem(blocks::CENTER_CORN,Location(i+2,j+2,1));
        }
    }
        
    mapTiled = TMXTiledMap::create("res/ship.tmx");
    this->addChild(mapTiled);
    mapVis = new MapVisualizer(ship,mapTiled,this);

    /* tileMap = TMXTiledMap::create("res/TileMap.tmx"); */
 

    /* background = tileMap->getLayer("Background"); */
    /* TMXObjectGroup *objectGroup = tileMap->getObjectGroup("Objects"); */
     
    /* if(objectGroup == NULL){ */
    /*         CCLOG("tile map has no objects object layer"); */
    /*             return false; */
    /* } */
     
    /* ValueMap spawnPoint = objectGroup->getObject("SpawnPoint"); */
     
    /* int x = spawnPoint.at("x").asInt(); */
    /* int y = spawnPoint.at("y").asInt(); */
     
    /* Sprite* player = Sprite::create("res/Player.png"); */
    /* player->setPosition(x,y); */
     
    /* this->addChild(player); */

    /* this->setViewPointCenter(player->getPosition()); */
 
    this->scheduleUpdate();
    return true;
}

/* void HelloWorld::setViewPointCenter(Vec2 pos) { */

/*     Size winSize = Director::getInstance()->getWinSize(); */

/*     int x = MAX(pos.x, winSize.width/2); */
/*     int y = MAX(pos.y, winSize.height/2); */
/*     x = MIN(x, */ 
/*             (tileMap->getMapSize().width * */ 
/*              this->tileMap->getTileSize().width) - winSize.width / 2); */
/*     y = MIN(y, (tileMap->getMapSize().height * */ 
/*                 tileMap->getTileSize().height) - winSize.height/2); */

/*     Vec2 actualPosition = Vec2(x, y); */
/*     Vec2 centerOfView = Vec2(winSize.width/2, winSize.height/2); */
/*     Vec2 viewPoint = centerOfView - actualPosition; */
/*     this->setPosition(viewPoint); */
/* } */

HelloWorld::~HelloWorld(){
    delete ship;
    delete mapVis;
}
