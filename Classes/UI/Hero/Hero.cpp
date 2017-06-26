//
//  Hero.cpp
//  Minos
//
//  Created by jingjing on 2017/6/23.
//
//

#include "Hero.hpp"

bool Hero::init()
{
    if (!Node::init())
    {
        return false;
    }
    initHero();
    
    return true;
}

void Hero::initHero()
{
    std::string csb = "hero/cityHero.csb";
    _armature = CSLoader::createNode(csb);
    _anim = CSLoader::createTimeline(csb);
    
    _armatureNode = Node::create();
    addChild(_armatureNode);
    _armature->runAction(_anim);
    
    _armatureNode->addChild(_armature);
    _armatureNode->setCascadeColorEnabled(true);
    setCascadeColorEnabled(true);
}

void Hero::run()
{
    if (_state == HeroState::state_running) return;
    _state = HeroState::state_running;
    
    _anim->play("run", true);
}

void Hero::idle()
{
    if (_state == HeroState::state_idle) return;
    _anim->play("idle", true);
    _state = HeroState::state_idle;
}

void Hero::turnLeft(bool turn)
{
    if (turn)
        _armatureNode->setScaleX(-1);
    else
        _armatureNode->setScaleX(1);
}
