//
//  BrickBase.cpp
//  Minos
//
//  Created by jingjing on 2017/6/24.
//
//

#include "BrickBase.hpp"
#include "../Hero/BrickHero.hpp"

BrickBase::BrickBase(BrickHero *hero, const std::string &filename)
: _hero(hero)
, _filename(filename)
{
}

BrickBase::~BrickBase()
{
}

//BrickBase* BrickBase::create(BrickHero *hero, std::string &filename)
//{
//    BrickBase *pRet = new(std::nothrow) BrickBase(hero, filename);
//    if (pRet && pRet->init())
//    {
//        pRet->autorelease();
//        return pRet;
//    }
//    else
//    {
//        delete pRet;
//        pRet = nullptr;
//        return nullptr;
//    }
//}

bool BrickBase::init()
{
    if (!Node::init())
    {
        return false;
    }
    initBrick();
    return true;
}

void BrickBase::initBrick()
{
    _content = Sprite::create(_filename);
    addChild(_content);
    _size = _content->getContentSize();
    setAnchorPoint(Vec2(0.5, 1));
    
    scheduleUpdate();
}

void BrickBase::update(float dt)
{
    CCLOG("----23---");
//    auto pos = getPosition();
//    pos.y += _moveY;
//    setPosition(pos);
//    
//    if (!_hero->alive()) return;
//    
//    if (_checkOn)
//        checkPlayerOn();
//    if (_checkMove)
//        checkPlayerMove();
}

void BrickBase::checkPlayerOn()
{
    if (checkInXsection())
    {
        //check y
        auto uPlatY = getPositionY();
        auto dPlatY = uPlatY - _size.height;
        auto nextPlatY = uPlatY + _moveY;
        
        auto dHeroY = _hero->getPositionY() - _hero->offsetY;
        auto nextHeroY = _hero->getNextPos().y - _hero->offsetY;
        
        if (dHeroY >= dPlatY && nextHeroY <= nextPlatY)
        {
            _hero->setPositionY(uPlatY-_hero->offsetY);
            _checkOn = false;
            playerOn();
        }
    }
}

void BrickBase::checkPlayerMove()
{
    if (!checkInXsection())
    {
        moveOut();
    }
}

void BrickBase::moveOut()
{
    _checkMove = false;
    _checkOn = false;
}

bool BrickBase::checkInXsection()
{
    auto platPos = getPosition();
    auto lPlatX = platPos.x - _size.width/2;
    auto rPlatX = platPos.x + _size.width/2;
    
    auto heroPos = _hero->getPosition();
    auto lHeroX = heroPos.x - _hero->width/2;
    auto rHeroX = heroPos.x + _hero->width/2;
    if (rHeroX > lPlatX && lHeroX < rPlatX)
        return true;
    return false;
}


