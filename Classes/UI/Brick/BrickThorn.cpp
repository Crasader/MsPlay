//
//  BrickThorn.cpp
//  Minos
//
//  Created by jingjing on 2017/6/29.
//
//

#include "BrickThorn.hpp"

BrickThorn::BrickThorn(BrickHero *hero, const std::string &filename)
: BrickBase(hero, filename)
{
}

BrickThorn::~BrickThorn()
{
    
}

BrickThorn* BrickThorn::create(BrickHero *hero, const std::string &filename)
{
    BrickThorn *pRet = new(std::nothrow) BrickThorn(hero, filename);
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

bool BrickThorn::init()
{
    if (!BrickBase::init())
    {
        return false;
    }
    
    _content->setAnchorPoint(Vec2(0.5, 0.5));
    _content->setPosition(Vec2(_size.width/2, _size.height/2));
    return true;
}

void BrickThorn::playerOn()
{
    _hero->moveUp(0, _moveY);
    _checkMove = true;
    _hero->hurt(3);
}

float BrickThorn::getPlatformTop()
{
    return BrickBase::getPlatformTop() - 15;
}
