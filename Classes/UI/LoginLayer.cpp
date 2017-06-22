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
    MAINLAYER->addChild(create());
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
    handleTouch([=](){
        CCLOG("what is the fuck");
        dispose();
    });
    
//    auto fSize = Director::getInstance()->getOpenGLView()->getFrameSize();
//    auto dSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
//    auto vSize = Director::getInstance()->getVisibleSize();
//    auto wSize = Director::getInstance()->getWinSize();
//    auto wPixe = Director::getInstance()->getWinSizeInPixels();
    
    auto campImg = ImageView::create("res/back/logo_camp.png");
    campImg->setOpacity(255);
    addChild(campImg);
    
    
//    local scale = math.max(display.width / nodeSize.width, display.height / nodeSize.height)
//    node:setScale(scale)
    
//    auto btn = Button::create("res/button/1.png");
//    btn->setPosition(Vec2(VCENTER));
//    addChild(btn);
//    btn->addTouchEventListener([](Ref* ref,Widget::TouchEventType eventType)
//    {
//        if (eventType != Widget::TouchEventType::ENDED) return;
//        UIModuleManager::getInstance()->dump();
//        auto logo = (LogoLayer*)UIModuleManager::getInstance()->getModule("LogoLayer");
//        if (logo) {
//            logo->test();
//        }
//    });
}

void LoginLayer::dispose()
{
    removeFromParent();
}
