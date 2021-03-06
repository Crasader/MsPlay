//
//  BrickHero.cpp
//  Minos
//
//  Created by jingjing on 2017/6/23.
//
//

#include "BrickHero.hpp"
#include "Msdef.hpp"
#include "../../Common/UIModuleManager.hpp"
#include "BrickMainLayer.hpp"


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

bool BrickHero::init()
{
    if (!Hero::init())
    {
        return false;
    }
    initBrickHero();
    
    return true;
}

void BrickHero::initBrickHero()
{
    scheduleUpdate();
}

void BrickHero::update(float dt)
{
    if (!_alive) return;
    if (moveState == MoveState::MOVE_DOWN)
    {
        ySpeed += gacceleration;
    }
    
    auto x = getPositionX() + xInput + xSpeed;
    auto y = getPositionY() - ySpeed;
    x = std::min(x, display.width/2+_maxMoveX);
    x = std::max(x, display.width/2-_maxMoveX);
    
    if (y >= _maxHeight)
    {
        hurt(4);
        moveDown();
        return;
    }
    else if (y <= -size.height)
    {
        die();
    }
    
    if (xInput != 0)
    {
        if (xInput > 0)
            walkRight();
        else
            walkLeft();
    }
    else
    {
        idle();
    }
    
    setPosition(Vec2(x, y));
}

Vec2 BrickHero::getNextPos()
{
    auto x = getPositionX() + xSpeed;
    auto y = getPositionY() - ySpeed - gacceleration;
    return Vec2(x, y);
}

void BrickHero::setXinput(float x)
{
    xInput = x;
}

void BrickHero::setXspeed(float x)
{
    xSpeed = x;
}

void BrickHero::walkLeft()
{
    turnLeft(true);
    run();
}

void BrickHero::walkRight()
{
    turnLeft(false);
    run();
}

void BrickHero::setMaxMove(const float &scaleX, const float &scaleY)
{
    _maxMoveX = 370 * scaleX - size.width/2;
    _maxHeight = 660 * scaleY - size.height;
}

void BrickHero::moveUp(const float &x, const float &y)
{
    moveState = MoveState::MOVE_UP;
    ySpeed = -y;
    xSpeed = x;
}

void BrickHero::moveDown()
{
    moveState = MoveState::MOVE_DOWN;
    ySpeed = 0;
}

void BrickHero::hurt(const int &amount)
{
    _blood -= amount;
    if (_blood < 0) {
        _blood = 0;
    }
    else if (_blood > 12)
    {
        _blood = 12;
    }
    
    auto main = (BrickMainLayer*)UIModuleManager::getInstance()->getModule("BrickMainLayer");
    if (main)
    {
        main->updateCurBlood(_blood);
    }
    
    if (_blood ==0) {
        die();
    }
}

void BrickHero::die()
{
    if (moveState != MoveState::MOVE_DIED) {
        moveState = MoveState::MOVE_DIED;
        idle();
        _alive = false;
        unscheduleUpdate();
        
        auto main = (BrickMainLayer*)UIModuleManager::getInstance()->getModule("BrickMainLayer");
        if (main)
        {
            main->gameOver();
        }
    }
}
