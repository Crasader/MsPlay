//
//  BrickMainLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/21.
//
//

#include "BrickMainLayer.hpp"
#include "../Hero/BrickHero.hpp"

void BrickMainLayer::show()
{
    MAINLAYER->addChild(create());
}

BrickMainLayer::BrickMainLayer()
:UIBaseLayer("BrickMainLayer")
{
}

bool BrickMainLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    initUI();
    
    return true;
}

void BrickMainLayer::initUI()
{
    handleTouch();
    
    auto bg = ImageView::create("res/minigame/brick/bg.png");
    auto bgSize = bg->getContentSize();
    bg->setPosition(display.center);
    addChild(bg);
    
    _scaleX = display.width / bgSize.width;
    _scaleY = display.height / bgSize.height;
    bg->setScaleX(_scaleX);
    bg->setScaleY(_scaleY);
    
    auto btnClose = Button::create("res/minigame/brick/close1.png");
    auto btnSize = btnClose->getContentSize();
    btnClose->setPosition(Vec2(display.width - btnSize.width/2, display.height - btnSize.height/2));
    addChild(btnClose);
    btnClose->addTouchEventListener([=](Ref* ref,Widget::TouchEventType eventType){
        if (eventType != Widget::TouchEventType::ENDED) return;
        dispose();
    });
    
    auto btnL = Button::create("minigame/brick/button.png");
    auto btnLSzie = btnL->getContentSize();
    btnL->setPosition(Vec2(btnLSzie.width/2, btnLSzie.height/2));
    addChild(btnL);
    btnL->addTouchEventListener([=](Ref* ref,Widget::TouchEventType eventType){
    });
    
    auto btnR = Button::create("minigame/brick/button.png");
    btnR->setFlippedX(true);
    btnR->setPosition(Vec2(display.width - btnLSzie.width/2, btnLSzie.height/2));
    addChild(btnR);
    btnR->addTouchEventListener([=](Ref* ref,Widget::TouchEventType eventType){
    });
    
    auto btnLight = Button::create("minigame/brick/light1.png");
    auto btnLightSize = btnLight->getContentSize();
    btnLight->setPosition(Vec2(display.width - btnLightSize.width/2, display.height/2));
    addChild(btnLight);
    btnLight->addTouchEventListener([=](Ref* ref,Widget::TouchEventType eventType){
        if (eventType != Widget::TouchEventType::ENDED) return;
        if (_lightOn)
        {
            btnLight->loadTextureNormal("minigame/brick/light2.png");
            _lightOn = false;
        }
        else
        {
            btnLight->loadTextureNormal("minigame/brick/light1.png");
            _lightOn = true;
        }
    });
    
    _score = Text::create("地下1层", "fonts/mnjcy.ttf", 40);
    _score->setPosition(Vec2(111, 650));
    bg->addChild(_score);
    
    float offsetX = 20.0;
    float offsetY = 540.0;
    for (int i = 0; i < 12; ++i)
    {
        auto bloodBg = ImageView::create("minigame/brick/blood1.png");
        bloodBg->setPosition(Vec2(offsetX + i * 16, offsetY));
        bg->addChild(bloodBg);
        
        auto bloodImg = ImageView::create("minigame/brick/blood2.png");
        bloodImg->setPosition(Vec2(7.5, 19.5));
        bloodBg->addChild(bloodImg);
        _bloodVec.push_back(bloodImg);
    }
    
    loadMoveGround();
    startHero();
}

void BrickMainLayer::loadMoveGround()
{
    
    auto bgLayer = Layer::create();
    addChild(bgLayer, -1);
    
    float spaceY = 2.0;
    for (int i = 0; i < 3; ++i)
    {
        auto moveBg = ImageView::create("minigame/brick/wall.png");
        moveBg->setScaleX(_scaleX);
        moveBg->setScaleY(_scaleY);
        
        moveBg->setPosition(Vec2(display.width/2, display.height/2 - i*(display.height - spaceY)));
        bgLayer->addChild(moveBg);
        _movebgVec.push_back(moveBg);
    }
    
    auto scheduler = Director::getInstance()->getScheduler();
    auto moveFun = [=](float delta){
        auto pos = bgLayer->getPosition();
        pos.y += 3.0;
        bgLayer->setPosition(pos);
        
        static int bgIndex = 0;
        static float moveY = 0.0;
        
        moveY += 3.0;
        if (moveY >= display.height)
        {
            moveY = 0.0;
            
            //reset bg position
            auto frontBg = _movebgVec[bgIndex];
            frontBg->setPositionY(frontBg->getPositionY() - 3*(display.height - spaceY));
            
            bgIndex += 1;
            if (bgIndex > 2)
            {
                bgIndex = 1;
            }
        }
    };
    
    scheduler->schedule(moveFun, this, 0.05, CC_REPEAT_FOREVER, 0, false, "bgmove");
    //scheduler->resumeTarget(this);
}

void BrickMainLayer::startHero()
{
    auto hero = BrickHero::create(12);
    hero->idle();
    hero->setPosition(Vec2(display.width/2, display.height/2));
    addChild(hero);
}
