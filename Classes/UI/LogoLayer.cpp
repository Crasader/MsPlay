//
//  LogoLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#include "LogoLayer.hpp"
#include "LoginLayer.hpp"
//#include "CommonFunction.hpp"


LogoLayer::LogoLayer()
: UIBaseLayer("LogoLayer")
, m_gameLogo(nullptr)
, m_campLogo(nullptr)
, m_defaultLogo(nullptr)
{
}

LogoLayer::~LogoLayer()
{
}

void LogoLayer::show()
{
    
}

bool LogoLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    initUI();
    
    return true;
}

void LogoLayer::initUI()
{
    
    m_gameLogo = ImageView::create("res/icon/logo.png");
    m_gameLogo->setPosition(VCENTER);
//    m_gameLogo->setOpacity(0);
    addChild(m_gameLogo);
    
    auto btn = Button::create("res/button/1.png");
    btn->setPosition(Vec2(VCENTER));
    addChild(btn);
    btn->addTouchEventListener([](Ref* ref,Widget::TouchEventType eventType){
        if (eventType != Widget::TouchEventType::ENDED) return;
        LoginLayer::show();
    });
    
    
//    m_campLogo = ImageView::create("res/back/logo_camp.png");
//    m_campLogo->setPosition(VCENTER);
//    m_campLogo->setOpacity(255);
//    addChild(m_campLogo);
//    
//    auto _camp_size = m_campLogo->getContentSize();
//    auto _scale = MAX(VSIZE.width/_camp_size.width, VSIZE.height/_camp_size.height);
//    _scale = MAX(_scale, 1.0);
//    m_campLogo->setScale(_scale);
//    
//    
//    m_defaultLogo = ImageView::create("res/back/logo_camp.png");
//    m_defaultLogo->setPosition(VCENTER);
//    m_defaultLogo->setOpacity(0);
//    addChild(m_defaultLogo);
//    
//    _camp_size = m_defaultLogo->getContentSize();
//    _scale = MAX(VSIZE.width/_camp_size.width, VSIZE.height/_camp_size.height);
//    _scale = MAX(_scale, 1.0);
//    m_defaultLogo->cocos2d::Node::setScale(_scale);
    
    //runDefaultLogoAction();
}

void LogoLayer::runDefaultLogoAction()
{
    auto action = Sequence::create(FadeIn::create(0.5),
                                   CallFunc::create([=](){m_campLogo->setOpacity(255);}),
                                   DelayTime::create(2.0),
                                   FadeOut::create(0.5),
                                   CallFunc::create([=](){m_defaultLogo->removeFromParent();
        runCampLogoAction();
    }),
                                   NULL
                                   );
    m_defaultLogo->runAction(action);
}

void LogoLayer::runCampLogoAction()
{
    auto action = Sequence::create(FadeIn::create(0.5),
                                   CallFunc::create([=](){m_gameLogo->setOpacity(255);}),
                                   DelayTime::create(2.0),
                                   FadeOut::create(0.5),
                                   CallFunc::create([=](){m_campLogo->removeFromParent();
        runGameLogoAction();
    }),
                                   NULL
                                   );
    m_campLogo->runAction(action);
}

void LogoLayer::runGameLogoAction()
{
    auto action = Sequence::create(FadeIn::create(0.5),
                                   DelayTime::create(1.0),
                                   CallFunc::create([=](){
                                        //NewLoginLayer::show();CCLOG("---fuck---");
                                                }),
                                   FadeOut::create(0.5),
                                   CallFunc::create([=](){
                                    //        this->removeFromParent();
                                    CCLOG("---shit---");}),
                                   NULL
                                   );
    m_gameLogo->runAction(action);
}

void LogoLayer::test()
{
    //CCLOG("fuck succeed");
}
