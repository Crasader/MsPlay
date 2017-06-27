//
//  BrickHero.hpp
//  Minos
//
//  Created by jingjing on 2017/6/23.
//
//

#ifndef BrickHero_hpp
#define BrickHero_hpp

#include "Hero.hpp"

enum class MoveState
{
    MOVE_UP,
    MOVE_DOWN,
    MOVE_SPRING,
    MOVE_DIED,
    MOVE_ON_WATER,
};

class BrickHero : public Hero
{
public:
    BrickHero(const int &blood);
    ~BrickHero();
    static BrickHero* create(const int &blood);
    bool init() override;
    inline bool alive(){return _alive;};
    Vec2 getNextPos();
    void setXinput(float x);
    void setXspeed(float x);
    void setMaxMove(const float &scaleX, const float &scaleY);
    void moveUp(const float& x, const float& y);
    void moveDown();
    void hurt(const int& amount);
    void die();
private:
    void initBrickHero();
    void update(float dt) override;
    void walkLeft();
    void walkRight();
public:
    float width = 10;
    float offsetY = 8;
    float xSpeed = 0;
    float ySpeed = 0;
    float xInput = 0.0;
    float gacceleration = 0.8;
    Size size = Size(50, 68);
    MoveState moveState;
private:
    int _blood = 0;
    bool _alive = true;
    float _maxMoveX;
    float _maxMoveY;
};

#endif /* BrickHero_hpp */
