//
//  BrickThorn.hpp
//  Minos
//
//  Created by jingjing on 2017/6/29.
//
//

#ifndef BrickThorn_hpp
#define BrickThorn_hpp

#include <string>
#include "BrickBase.hpp"

class BrickThorn : public BrickBase
{
public:
    BrickThorn(BrickHero *hero, const std::string &filename);
    ~BrickThorn();
    virtual bool init() override;
    virtual void playerOn() override;
    float getPlatformTop() override;
    static BrickThorn *create(BrickHero *hero, const std::string &filename);
public:
};

#endif /* BrickThorn_hpp */
