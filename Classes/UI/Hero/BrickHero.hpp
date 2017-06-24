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

class BrickHero : public Hero
{
public:
    BrickHero(const int &blood);
    ~BrickHero();
    static BrickHero* create(const int &blood);
    inline bool alive(){return _alive;};
    Vec2 getNextPos();
public:
    float width = 10;
    float offsetY = 8;
    float xSpeed = 0;
    float ySpeed = 0;
    float gacceleration = 0.8;
private:
    int _blood = 0;
    bool _alive = true;
};

#endif /* BrickHero_hpp */
