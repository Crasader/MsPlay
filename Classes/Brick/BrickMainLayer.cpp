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
    
    auto bg = ImageView::create("res/minigame/brick/bg.png");
    auto bgSize = bg->getContentSize();
    
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

