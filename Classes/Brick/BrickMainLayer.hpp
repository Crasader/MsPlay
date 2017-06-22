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
    ~BrickMainLayer();
    
private:
    void initUI();
private:
    
};

#endif /* BrickMainLayer_hpp */
