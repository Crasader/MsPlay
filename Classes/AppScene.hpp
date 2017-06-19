//
//  AppScene.hpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#ifndef AppScene_hpp
#define AppScene_hpp

#include "cocos2d.h"
USING_NS_CC;

class AppScene : public Scene
{
public:
    AppScene() = default;
    CREATE_FUNC(AppScene);
    virtual bool init();
    inline Layer * getMainLayer() {return _mainLayer;}
    void gameExit();
private:
    void onKeyReleased(EventKeyboard::KeyCode keycode, Event* event);
private:
    Layer* _mainLayer = nullptr;
};

#endif /* AppScene_hpp */
