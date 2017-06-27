//
//  BrickNormal.cpp
//  Minos
//
//  Created by jingjing on 2017/6/26.
//
//

#include "BrickNormal.hpp"

BrickNormal::BrickNormal(BrickHero *hero, const std::string &filename)
: BrickBase(hero, filename)
{
}

BrickNormal::~BrickNormal()
{
    
}

BrickNormal* BrickNormal::create(BrickHero *hero, const std::string &filename)
{
    BrickNormal *pRet = new(std::nothrow) BrickNormal(hero, filename);
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
    if (!BrickBase::init())
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
}
