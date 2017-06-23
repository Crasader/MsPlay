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

class BrickMainLayer : public UIBaseLayer
{
public:
    static void show();
    virtual bool init() override;
    CREATE_FUNC(BrickMainLayer);
    
    BrickMainLayer();
    ~BrickMainLayer() = default;
    
private:
    void initUI();
    void loadMoveGround();
    void startHero();
private:
    float _scaleX = 1.0;
    float _scaleY = 1.0;
    
    bool _lightOn = true;
    
    Text *_score = nullptr;
    std::vector<ImageView*> _bloodVec;
    std::vector<ImageView*> _movebgVec;
    
};

#endif /* BrickMainLayer_hpp */
