//
//  BrickBase.hpp
//  Minos
//
//  Created by jingjing on 2017/6/24.
//
//

#ifndef BrickBase_hpp
#define BrickBase_hpp

#include <string>
#include "cocos2d.h"
USING_NS_CC;

class BrickHero;

class BrickBase : public Sprite
{
public:
    BrickBase(BrickHero *hero, const std::string &filename);
    virtual ~BrickBase();
//    static BrickBase *create(BrickHero *hero, std::string &filename);
    
    virtual bool init() override;
    virtual void playerOn() = 0;
    virtual void moveOut();
private:
    void initBrick();
    void update(float dt) override;
    void checkPlayerOn();
    void checkPlayerMove();
    bool checkInXsection();
protected:
    float _moveX = 3;
    float _moveY = 2;
    
    bool _checkMove = false;
    bool _checkOn = true;
    
    Size _size;
    BrickHero *_hero;
    std::string _filename;
    Sprite *_content;
};


#endif /* BrickBase_hpp */
