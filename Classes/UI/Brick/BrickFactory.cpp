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
    if (_first)
    {
        _first = false;
        
        auto brick = BrickNormal::create(hero, "minigame/brick/normalBrick.png");
        auto pos = Vec2(display.width/2, display.height/2);
        brick->setAnchorPoint(Vec2(0.5, 0.5));
        addBrick(brick, pos);
        
        _brickCount = 1;
        return;
    }
    
    auto brick = BrickNormal::create(hero, "minigame/brick/normalBrick.png");
    auto factor = random(1, 100) > 50 ? 1 : -1;
    auto randomX = display.width/2 - factor * random(1.0, 240.0);
    auto pos = Vec2(randomX, _offsetY);
    brick->setAnchorPoint(Vec2(0.5, 0.5));
    addBrick(brick, pos);
    _brickCount += 1;
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

bool BrickFactory::canCreateNexBrick()
{
    auto lastBrick = brickVec.back();
    if(lastBrick->getPositionY() > -100)
    {
        _offsetY = lastBrick->getPositionY() - _brickSpace;
        return true;
    }
    return false;
}

void BrickFactory::removeUnUsedBrick()
{
    auto frontBrick = brickVec.front();
    if (frontBrick->getPositionY() > display.height+10)
    {
        brickVec.pop_front();
        frontBrick->removeFromParent();
    }
}
