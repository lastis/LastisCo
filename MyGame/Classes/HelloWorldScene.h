#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "MapVisualizer.h"
#include "core/main/ShipMaster.h"
#include "cocos2d.h"
#include "network/SocketIO.h"
#include "ServEventHandler.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
private:
    ~HelloWorld();
    TMXTiledMap* mapTiled;
    /* TMXLayer* background; */
    ShipMaster* ship;
    MapVisualizer* mapVis;
    float time;
public:
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, 
    // instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    void update(float) override;
    
    // Costum method.
    // Set the view on the given position.
    /* void setViewPointCenter(Vec2 pos); */

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
