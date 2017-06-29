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
    BrickNormal(BrickHero *hero, const std::string &filename);
    ~BrickNormal();
    virtual bool init() override;
    virtual void playerOn() override;
    static BrickNormal *create(BrickHero *hero, const std::string &filename);
public:
};

#endif /* BrickNormal_hpp */
