#include "AppDelegate.h"
#include "AppSystem.hpp"
#include "Display.hpp"


// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Minos");
        director->setOpenGLView(glview);
    }
    
    director->setDisplayStats(false);
    director->setAnimationInterval(1.0f / 60);
    
    glview->setFrameSize(1800, 1100);
    
    Display::getInstance()->setAutoScale(designResolutionSize);
    AppSystem::getInstance();
    
    
    /*
     local scaleX, scaleY = framesize.width / r.width, framesize.height / r.height
     local width, height = framesize.width, framesize.height
     if r.autoscale == "FIXED_WIDTH" then
     width = framesize.width / scaleX
     height = framesize.height / scaleX
     view:setDesignResolutionSize(width, height, cc.ResolutionPolicy.NO_BORDER)
     elseif r.autoscale == "FIXED_HEIGHT" then
     width = framesize.width / scaleY
     height = framesize.height / scaleY
     view:setDesignResolutionSize(width, height, cc.ResolutionPolicy.NO_BORDER)
     elseif r.autoscale == "EXACT_FIT" then
     view:setDesignResolutionSize(r.width, r.height, cc.ResolutionPolicy.EXACT_FIT)
     elseif r.autoscale == "NO_BORDER" then
     view:setDesignResolutionSize(r.width, r.height, cc.ResolutionPolicy.NO_BORDER)
     elseif r.autoscale == "SHOW_ALL" then
     view:setDesignResolutionSize(r.width, r.height, cc.ResolutionPolicy.SHOW_ALL)
     else
     printError(string.format("display - invalid r.autoscale \"%s\"", r.autoscale))
     end
     */
    
    return true;
}

/*
bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Minos", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Minos");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_HEIGHT);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }

    register_all_packages();


    return true;
}
 */

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}

void AppDelegate::setDesignResolution()
{
//    auto framesize = Director::getInstance()->getOpenGLView();
//    if r.autoscale == "FILL_ALL" then
//        view:setDesignResolutionSize(framesize.width, framesize.height, cc.ResolutionPolicy.FILL_ALL)
//        else
//            local scaleX, scaleY = framesize.width / r.width, framesize.height / r.height
//            local width, height = framesize.width, framesize.height
//            if r.autoscale == "FIXED_WIDTH" then
//                width = framesize.width / scaleX
//                height = framesize.height / scaleX
//                view:setDesignResolutionSize(width, height, cc.ResolutionPolicy.NO_BORDER)
//                elseif r.autoscale == "FIXED_HEIGHT" then
//                width = framesize.width / scaleY
//                height = framesize.height / scaleY
//                view:setDesignResolutionSize(width, height, cc.ResolutionPolicy.NO_BORDER)
//                elseif r.autoscale == "EXACT_FIT" then
//                view:setDesignResolutionSize(r.width, r.height, cc.ResolutionPolicy.EXACT_FIT)
//                elseif r.autoscale == "NO_BORDER" then
//                view:setDesignResolutionSize(r.width, r.height, cc.ResolutionPolicy.NO_BORDER)
//                elseif r.autoscale == "SHOW_ALL" then
//                view:setDesignResolutionSize(r.width, r.height, cc.ResolutionPolicy.SHOW_ALL)
//                else
//                    printError(string.format("display - invalid r.autoscale \"%s\"", r.autoscale))
//                    end
//                    end
}
