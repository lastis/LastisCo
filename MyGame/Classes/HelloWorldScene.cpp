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
 
    tileMap = TMXTiledMap::create("res/TileMap.tmx");
    background = tileMap->getLayer("Background");
 
    this->addChild(tileMap);

    TMXObjectGroup *objectGroup = tileMap->getObjectGroup("Objects");
     
    if(objectGroup == NULL){
            CCLOG("tile map has no objects object layer");
                return false;
    }
     
    /* CCDictionary *spawnPoint = objectGroup->getObject("SpawnPoint"); */
     
    /* int x = ((CCString)*spawnPoint->valueForKey("x")).intValue(); */
    /* int y = ((CCString)*spawnPoint->valueForKey("y")).intValue(); */
     
    /* player = new CCSprite(); */
    /* player->initWithFile("Player.png"); */
    /* player->setPosition(ccp(x,y)); */
     
    /* this->addChild(player); */

    /* this->setViewPointCenter(player->getPosition()); */
 
    return true;
}

/* void HelloWorld::setViewPointCenter(CCPoint position) { */

/*     CCSize winSize = CCDirector::sharedDirector()->getWinSize(); */

/*     int x = MAX(position.x, winSize.width/2); */
/*     int y = MAX(position.y, winSize.height/2); */
/*     x = MIN(x, (tileMap->getMapSize().width * this->tileMap->getTileSize().width) - winSize.width / 2); */
/*     y = MIN(y, (tileMap->getMapSize().height * tileMap->getTileSize().height) - winSize.height/2); */
/*     CCPoint actualPosition = ccp(x, y); */

/*     CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2); */
/*     CCPoint viewPoint = ccpSub(centerOfView, actualPosition); */
/*     this->setPosition(viewPoint); */
/* } */

