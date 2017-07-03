//
//  BrickMainLayer.hpp
//  Minos
//
//  Created by jingjing on 2017/6/21.
//
//

#ifndef BrickMainLayer_hpp
#define BrickMainLayer_hpp

#include "UIBaseLayer.hpp"
#include "../Hero/BrickHero.hpp"
#include "BrickFactory.hpp"

class BrickMainLayer : public UIBaseLayer
{
public:
    static void show();
    virtual bool init() override;
    CREATE_FUNC(BrickMainLayer);
    
    BrickMainLayer();
    ~BrickMainLayer();
    void updateCurBlood(const int& blood);
    void gameOver();
private:
    void initUI();
    void loadMoveGround();
    void startHero();
    void startBrick();
    void update(float dt) override;
    void brickMove();
    void backgroundMove();
private:
    float _scaleX = 1.0;
    float _scaleY = 1.0;
    float _inputX = 6.0;
    
    bool _lightOn = true;
    BrickHero* _hero;
    BrickFactory* _brickFactory;
    Layer* _bgLayer;
    Size _moveBgSize;
    
    Text *_score = nullptr;
    std::vector<ImageView*> _bloodVec;
    std::vector<ImageView*> _movebgVec;
};

#endif /* BrickMainLayer_hpp */
