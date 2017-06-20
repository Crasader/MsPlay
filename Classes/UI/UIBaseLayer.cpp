//
//  UIBaseLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#include "UIBaseLayer.hpp"
#include "UIModuleManager.hpp"

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
