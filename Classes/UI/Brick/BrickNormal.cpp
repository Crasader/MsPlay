//
//  BrickNormal.cpp
//  Minos
//
//  Created by jingjing on 2017/6/26.
//
//

#include "BrickNormal.hpp"

BrickNormal::BrickNormal(BrickHero *hero)
: BrickBase(hero)
{
}

BrickNormal::~BrickNormal()
{
    
}

BrickNormal* BrickNormal::create(BrickHero *hero)
{
    BrickNormal *pRet = new(std::nothrow) BrickNormal(hero);
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool BrickNormal::init()
{
    if (!BrickBase::initBrick("minigame/brick/normalBrick.png"))
    {
        return false;
    }
    
    _content->setAnchorPoint(Vec2(0.5, 0.5));
    _content->setPosition(Vec2(_size.width/2, _size.height/2));
    return true;
}

void BrickNormal::playerOn()
{
    _hero->moveUp(0, _moveY);
    _checkMove = true;
    _hero->hurt(-1);
}
