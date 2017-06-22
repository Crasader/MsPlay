//
//  Display.cpp
//  Minos
//
//  Created by jingjing on 2017/6/22.
//
//

#include "Display.hpp"

const Size Display::designSize = Size(1280, 720);
Display* Display::_instance = nullptr;

Display* Display::getInstance()
{
    if( _instance == nullptr )
    {
        _instance = new Display();
        _instance->setAutoScale();
    }
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

void Display::setAutoScale()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    auto framesize = glview->getFrameSize();
    
    auto scaleX = framesize.width / designSize.width;
    auto scaleY = framesize.height / designSize.height;
    auto width = framesize.width;
    auto height = framesize.height;
    
    auto fRatio = framesize.width / framesize.height;
    auto dRatio = designSize.width / designSize.height;
    if (fRatio <= dRatio)
    {
        width = framesize.width / scaleX;
        height = framesize.height / scaleX;
        glview->setDesignResolutionSize(width, height, ResolutionPolicy::NO_BORDER);
    }
    else
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
    CCLOG("# display.designSize           = {width = %0.2f, height = %0.2f}", designSize.width, designSize.height);
    CCLOG("# display.size                 = {width = %0.2f, height = %0.2f}", size.width, size.height);
    CCLOG("# display.center               = {x = %0.2f, y = %0.2f}", center.x, center.y);
    CCLOG("# display.width                = %0.2f", width);
    CCLOG("# display.height               = %0.2f", height);
}
