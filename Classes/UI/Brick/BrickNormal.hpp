//
//  BrickNormal.hpp
//  Minos
//
//  Created by jingjing on 2017/6/26.
//
//

#ifndef BrickNormal_hpp
#define BrickNormal_hpp

#include <string>
#include "BrickBase.hpp"

class BrickNormal : public BrickBase
{
public:
    BrickNormal(BrickHero *hero);
    ~BrickNormal();
    virtual bool init() override;
    virtual void playerOn() override;
    static BrickNormal *create(BrickHero *hero);
public:
};

#endif /* BrickNormal_hpp */
