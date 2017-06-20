//
//  LoginLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/20.
//
//

#include "LoginLayer.hpp"
#include "LogoLayer.hpp"
#include "UIModuleManager.hpp"

LoginLayer::LoginLayer()
: UIBaseLayer("LoginLayer")
{
}

LoginLayer::~LoginLayer()
{
}

void LoginLayer::show()
{
    MainLayer->addChild(create());
}

bool LoginLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    initUI();
    
    return true;
}

void LoginLayer::initUI()
{
    auto campImg = ImageView::create("res/back/logo_camp.png");
    campImg->setPosition(VCENTER);
    campImg->setOpacity(255);
    addChild(campImg);
    
    auto btn = Button::create("res/button/1.png");
    btn->setPosition(Vec2(VCENTER));
    addChild(btn);
    btn->addTouchEventListener([](Ref* ref,Widget::TouchEventType eventType)
    {
        if (eventType != Widget::TouchEventType::ENDED) return;
        UIModuleManager::getInstance()->dump();
        auto logo = (LogoLayer*)UIModuleManager::getInstance()->getModule("LogoLayer");
        if (logo) {
            logo->test();
        }
    });
}
