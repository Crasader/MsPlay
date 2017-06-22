//
//  BrickMainLayer.cpp
//  Minos
//
//  Created by jingjing on 2017/6/21.
//
//

#include "BrickMainLayer.hpp"

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
}

