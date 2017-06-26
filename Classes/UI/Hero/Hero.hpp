//
//  Hero.hpp
//  Minos
//
//  Created by jingjing on 2017/6/23.
//
//

#ifndef Hero_hpp
#define Hero_hpp

#include <string>
#include "editor-support/cocostudio/CocoStudio.h"
#include <cocos2d.h>
USING_NS_CC;

enum class HeroState
{
    state_running,
    state_idle,
};

class Hero : public Node
{
public:
    Hero() = default;
    virtual ~Hero() = default;
    CREATE_FUNC(Hero);
    
    void initHero();
    void run();
    void idle();
    void turnLeft(bool turn = false);
protected:
    bool init() override;
protected:
    int64_t _id;
    HeroState _state;
    Node *_armature = nullptr;
    cocostudio::timeline::ActionTimeline *_anim = nullptr;
    Node *_armatureNode = nullptr;
};

#endif /* Hero_hpp */
