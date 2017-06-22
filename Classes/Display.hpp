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
    void setAutoScale(Size &designSize);
private:
    void setConstants();
    Display() = default;
    ~Display() = default;
    static Display* _instance;
public:
    Size sizeInPixels;
    Size size;
    Vec2 center;
    float width;
    float height;
};

#endif /* Display_hpp */
