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
 
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
 
    tileMap = TMXTiledMap::create("res/ship.tmx");
    auto layer1 = tileMap->getLayer("Layer_1");
    unsigned int gid = layer1->getTileGIDAt(Vec2(0,0));
    log("GID : %u",gid);

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
 
    this->addChild(tileMap);
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

