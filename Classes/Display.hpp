//
//  Display.hpp
//  Minos
//
//  Created by jingjing on 2017/6/22.
//
//

#ifndef Display_hpp
#define Display_hpp

#include "cocos2d.h"
USING_NS_CC;

class Display : public Ref
{
public:
    static Display* getInstance();
    void destroyInstance();
    void setAutoScale();
private:
    void setConstants();
    Display() = default;
    ~Display() = default;
    static Display* _instance;
public:
    Size sizeInPixels = Size(0.0, 0.0);
    Size size = Size(0.0, 0.0);
    Vec2 center = Vec2(0.0, 0.0);
    float width = 0.0;
    float height = 0.0;
    static const Size designSize;
};

#endif /* Display_hpp */
