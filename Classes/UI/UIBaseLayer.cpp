//
//  UIBaseLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#include "UIBaseLayer.hpp"
#include "UIModuleManager.hpp"

UIBaseLayer::~UIBaseLayer()
{
}


void UIBaseLayer::onEnter()
{
    CCLOG("-------[Layer onEnter: %s]-------", _uiLayerName.c_str());
    Layer::onEnter();
//    UIModuleManagerInstance->pushModule(m_uiName, m_curUI);
}

void UIBaseLayer::onExit()
{
    CCLOG("-------[Layer onExit: %s]--------", _uiLayerName.c_str());
    Layer::onExit();
//    UIModuleManagerInstance->popModule(m_uiName);
}
