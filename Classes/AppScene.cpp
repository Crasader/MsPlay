//
//  AppScene.cpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#include "AppScene.hpp"
#include "LogoLayer.hpp"

bool AppScene::init(){
    Scene::init();
    
    _mainLayer = Layer::create();
    addChild(_mainLayer);
    
    auto layer = LogoLayer::create();
    _mainLayer->addChild(layer);
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(AppScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void AppScene::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event)
{
    if (keycode == EventKeyboard::KeyCode::KEY_ESCAPE || keycode == EventKeyboard::KeyCode::KEY_BACKSPACE)
    {
        // gameExit();
    }
}

void AppScene::gameExit()
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    exit(0);  
#endif  
}
