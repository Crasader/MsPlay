//
//  BrickFactory.cpp
//  Minos
//
//  Created by jingjing on 2017/6/26.
//
//

#include "BrickFactory.hpp"
#include "BrickNormal.hpp"

BrickFactory::BrickFactory()
:UIBaseLayer("BrickFactory")
{
    
}

BrickFactory::~BrickFactory()
{
    
}

bool BrickFactory::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    return true;
}

void BrickFactory::createBrick(BrickHero *hero)
{
    auto brick = BrickNormal::create(hero, "minigame/brick/normalBrick.png");
    auto pos = Vec2(display.width/2, display.height/2);
    _brickCount = 1;
    brick->setAnchorPoint(Vec2(0.5, 0.5));
    addBrick(brick, pos);
}

void BrickFactory::resetData()
{
    
}

void BrickFactory::addBrick(BrickBase *brick, const cocos2d::Vec2 &pos)
{
    brick->setPosition(pos);
    addChild(brick);
    brickVec.push_back(brick);
}
