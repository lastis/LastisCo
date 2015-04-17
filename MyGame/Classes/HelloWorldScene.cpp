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

}
 
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    ShipMaster ship = ShipMaster(3,20,20);
    TMXTiledMap* mapTiled = TMXTiledMap::create("res/ship.tmx");
    MapVisualizer mapVis = MapVisualizer(ship,mapTiled);

    /* auto layer1 = mapTiled->getLayer("Layer_1"); */
    /* unsigned int gid = layer1->getTileGIDAt(Vec2(0,0)); */
    /* layer1->setTileGID(30,Vec2(0,1)); */
    /* layer1->setTileGID(30,Vec2(0,2)); */
    /* layer1->setTileGID(30,Vec2(0,3)); */
    /* log("GID : %u",gid); */

    this->addChild(mapTiled);
    
 

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
 
    /* this->scheduleUpdate(); */
    return true;
}

void HelloWorld::setViewPointCenter(Vec2 pos) {

    Size winSize = Director::getInstance()->getWinSize();

    int x = MAX(pos.x, winSize.width/2);
    int y = MAX(pos.y, winSize.height/2);
    x = MIN(x, 
            (tileMap->getMapSize().width * 
             this->tileMap->getTileSize().width) - winSize.width / 2);
    y = MIN(y, (tileMap->getMapSize().height * 
                tileMap->getTileSize().height) - winSize.height/2);

    Vec2 actualPosition = Vec2(x, y);
    Vec2 centerOfView = Vec2(winSize.width/2, winSize.height/2);
    Vec2 viewPoint = centerOfView - actualPosition;
    this->setPosition(viewPoint);
}

