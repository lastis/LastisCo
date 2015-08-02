#ifndef __SERVE_H__
#define __SERVE_H__

using namespace network;
using namespace cocos2d;

#include "cocos2d.h"
#include "network/SocketIO.h"
class ServEventHandler : public SocketIO::SIODelegate{
public:
    ServEventHandler(){

    }

    void onConnect(SIOClient* client) {
        log("Something connected");
    }

    void onMessage(SIOClient* client, const std::string& data){
        log("Some message");
    }

    void onClose(SIOClient* client){
        log("Something closed");
    }
    
    void onError(SIOClient* client, const std::string& data){
         log("Some error");
    }

};

#endif
