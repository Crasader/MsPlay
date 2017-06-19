//
//  AppSystem.hpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#ifndef AppSystem_hpp
#define AppSystem_hpp

#include "AppScene.hpp"


class  AppSystem : public Ref
{
private:
    AppSystem() = default;
    ~AppSystem();
public:
    static AppSystem* getInstance();
    void restart();
    void resetGame();
    inline AppScene *getScene() {return _appScene;}
private:
    
    void init();
    void loadAllConfig();
    void unloadAllConfig();
    void unloadConfig();
    void reloadConfig();
    
private:
    static AppSystem* _instance;
    AppScene* _appScene = nullptr;
    //重新连接服务器次数
    int _reconnectCount = 0;
};

#endif /* AppSystem_hpp */
