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
    MainLayer->addChild(create());
}

BrickMainLayer::BrickMainLayer()
:UIBaseLayer("BrickMainLayer")
{
}

BrickMainLayer::~BrickMainLayer()
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
    
//    test
//    auto _size = Director::getInstance()->getOpenGLView()->getVisibleSize();
//    CCLOG("---_s%f%f---",_size.width, _size.height);
//    
//    auto __size = Director::getInstance()->getWinSize();
//    
//    auto bg = ImageView::create("res/minigame/brick/bg.png");
//    auto bgSize = bg->getContentSize();
//    auto scaleX = VSIZE.width/DSIZE.width;
//    auto scaleY = VSIZE.height/DSIZE.height;
//    bg->setScaleX(scaleX);
//    bg->setScaleY(scaleY);
//    bg->setPosition(VCENTER);
//    addChild(bg);
//    
//    auto btnClose = Button::create("res/minigame/brick/close1.png");
//    btnClose->setPosition(Vec2(VSIZE.width - 108, VSIZE.height - 86));
//    addChild(btnClose);
//    btnClose->addTouchEventListener([=](Ref* ref,Widget::TouchEventType eventType){
//        if (eventType != Widget::TouchEventType::ENDED) return;
//        dispose();
//    });
    
    
    
//    local buttonClose = ccui.Button:create("minigame/brick/close1.png", "minigame/brick/close1.png")
//buttonClose:setPosition(display.width - 108*scaleX, display.height - 86*scaleY)
//buttonClose:setTouchEnabled(true)
//buttonClose:onTouch(handler(self, self.close))
//self:addChild(buttonClose)
    
//    
//bg:setScaleX(scaleX)
//bg:setScaleY(scaleY)
//bg:setPosition(display.center)
//self:addChild(bg)
//    
//self:loadBackground()
//self:startHero()
//self:startBrick()
//    
//    self.backgroundMoveFuncID = scheduleGlobal(handler(self, self.backgroundMove), 0)
//    self.brickMoveFuncID = scheduleGlobal(handler(self, self.brickMove), 0)
}

