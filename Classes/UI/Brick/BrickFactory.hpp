//
//  BrickFactory.hpp
//  Minos
//
//  Created by jingjing on 2017/6/26.
//
//

#ifndef BrickFactory_hpp
#define BrickFactory_hpp

#include <list>
#include "BrickBase.hpp"
#include "../UIBaseLayer.hpp"

class BrickHero;
class BrickFactory : public UIBaseLayer
{
public:
    BrickFactory();
    ~BrickFactory();
    virtual bool init() override;
    CREATE_FUNC(BrickFactory);
    void resetData();
    void createBrick(BrickHero* hero);
    bool canCreateNexBrick();
    void removeUnUsedBrick();
    void stopBrickList();
    inline void setUpSpeed(const int &speed){_upSpeed = speed;}
private:
    void addBrick(BrickBase* brick, const Vec2& pos);
private:
    bool _first = true;
    int _brickCount = 0;
    float _offsetY= 250;
    float _upSpeed = 0;
    float _brickSpace = 150.0;
    std::list<BrickBase*> brickVec;
};

#endif /* BrickFactory_hpp */
