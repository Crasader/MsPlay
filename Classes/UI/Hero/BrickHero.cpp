//
//  BrickHero.cpp
//  Minos
//
//  Created by jingjing on 2017/6/23.
//
//

#include "BrickHero.hpp"

BrickHero::BrickHero(const int &blood)
: Hero()
, _blood(blood)
{
}

BrickHero::~BrickHero()
{
    
}

BrickHero* BrickHero::create(const int &blood)
{
    BrickHero *pRet = new(std::nothrow) BrickHero(blood);
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

Vec2 BrickHero::getNextPos()
{
    auto x = getPositionX() + xSpeed;
    auto y = getPositionY() - ySpeed - gacceleration;
    return Vec2(x, y);
}
