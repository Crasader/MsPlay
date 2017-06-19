//
//  UIBaseLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#include "UIBaseLayer.hpp"
UIBaseLayer::UIBaseLayer()
: m_uiName("")
, m_curUI(nullptr)
{
}

UIBaseLayer::~UIBaseLayer()
{
}

void UIBaseLayer::setCurUI(cocos2d::Layer *ui, std::string name)
{
    m_curUI = ui;
    m_uiName = name;
}


void UIBaseLayer::onEnter()
{
    CCLOG("-------[Layer onEnter: %s]-------", m_uiName.c_str());
    Layer::onEnter();
//    UIModuleManagerInstance->pushModule(m_uiName, m_curUI);
}

void UIBaseLayer::onExit()
{
    CCLOG("-------[Layer onExit: %s]--------", m_uiName.c_str());
    Layer::onExit();
//    UIModuleManagerInstance->popModule(m_uiName);
}
