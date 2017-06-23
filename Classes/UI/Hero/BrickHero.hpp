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
private:
    int _blood = 0;
    bool _alive = true;
};

#endif /* BrickHero_hpp */
