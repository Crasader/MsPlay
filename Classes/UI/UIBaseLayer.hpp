//
//  UIBaseLayer.hpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#ifndef UIBaseLayer_hpp
#define UIBaseLayer_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <string>
#include "AppSystem.hpp"
#include "../Display.hpp"
//#include "Net/MsgCommon.hpp"
//#include "Net/NetManagerEx.hpp"

//using namespace ui;
//using namespace cocostudio;
//using namespace cocos2d;

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

#define BIND_TOUCH_EVENT_LISTENER(function)   std::bind(&function, this, std::placeholders::_1, std::placeholders::_2)
#define MainLayer AppSystem::getInstance()->getScene()->getMainLayer()
#define display (*Display::getInstance())

class UIBaseLayer:public Layer
{
public:
    explicit UIBaseLayer(const std::string& name);
    virtual ~UIBaseLayer() = default;
    
    virtual void onEnter();
    virtual void onExit();
    void dispose();
public:
    using endCallback = std::function<void()>;
    void handleTouch(const endCallback callback = nullptr);
private:
    const std::string _uiLayerName;
};

#endif /* UIBaseLayer_hpp */
