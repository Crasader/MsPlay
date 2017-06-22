//
//  Display.cpp
//  Minos
//
//  Created by jingjing on 2017/6/22.
//
//

#include "Display.hpp"

Display* Display::_instance = nullptr;

Display* Display::getInstance()
{
    if( _instance == nullptr )
        _instance = new Display();
    return _instance;
}

void Display::destroyInstance()
{
    if (_instance != nullptr)
    {
        delete _instance;
        _instance = nullptr;
    }
}

void Display::setAutoScale(cocos2d::Size &designSize)
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    auto framesize = glview->getFrameSize();
    
    auto autoscale =  ResolutionPolicy::FIXED_HEIGHT;
    //if (framesize.width / framesize.height <= designSize.width / designSize.height)
    if (framesize.width / framesize.height <= 1.77)
    {
        autoscale = ResolutionPolicy::FIXED_WIDTH;
    }
    
    auto scaleX = framesize.width / designSize.width;
    auto scaleY = framesize.height / designSize.height;
    auto width = framesize.width;
    auto height = framesize.height;
    if (autoscale == ResolutionPolicy::FIXED_WIDTH)
    {
        width = framesize.width / scaleX;
        height = framesize.height / scaleX;
        glview->setDesignResolutionSize(width, height, ResolutionPolicy::NO_BORDER);
    }
    else if (autoscale == ResolutionPolicy::FIXED_HEIGHT)
    {
        width = framesize.width / scaleY;
        height = framesize.height / scaleY;
        glview->setDesignResolutionSize(width, height, ResolutionPolicy::NO_BORDER);
    }
    
    setConstants();
}

void Display::setConstants()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    
    auto framesize = glview->getFrameSize();
    auto viewsize = director->getWinSize();
    
    sizeInPixels = framesize;
    size = viewsize;
    center = Vec2(size.width/2, size.height/2);
    width = size.width;
    height = size.height;
    
    CCLOG("# display.sizeInPixels         = {width = %0.2f, height = %0.2f}", sizeInPixels.width, sizeInPixels.height);
    CCLOG("# display.size                 = {width = %0.2f, height = %0.2f}", size.width, size.height);
    CCLOG("# display.center               = {x = %0.2f, y = %0.2f}", center.x, center.y);
    CCLOG("# display.width                = %0.2f", width);
    CCLOG("# display.height               = %0.2f", height);
    
}
