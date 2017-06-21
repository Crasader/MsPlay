//
//  UIBaseLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#include "UIBaseLayer.hpp"
#include "UIModuleManager.hpp"

UIBaseLayer::UIBaseLayer(const std::string& name)
: _uiLayerName(name)
{
}

void UIBaseLayer::onEnter()
{
    CCLOG("-------[Layer onEnter: %s]-------", _uiLayerName.c_str());
    Layer::onEnter();
    UIModuleManager::getInstance()->pushModule(this, _uiLayerName);
}

void UIBaseLayer::onExit()
{
    CCLOG("-------[Layer onExit: %s]--------", _uiLayerName.c_str());
    Layer::onExit();
    UIModuleManager::getInstance()->popModule(_uiLayerName);
}

void UIBaseLayer::handleTouch(const endCallback callback)
{
    auto touchListen = EventListenerTouchOneByOne::create();
    touchListen->setSwallowTouches(true);
    touchListen->onTouchBegan = [](Touch *touch, Event *event)->bool {return true;};
    touchListen->onTouchEnded = [=](Touch *touch, Event *event) -> void
    {
        if (callback)
            callback();
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListen, this);
}
