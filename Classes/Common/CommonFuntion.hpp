//
//  CommonFuntion.hpp
//  Minos
//
//  Created by jingjing on 2017/6/22.
//
//

#ifndef CommonFuntion_hpp
#define CommonFuntion_hpp
#include <string>
#include "editor-support/cocostudio/CocoStudio.h"
#include "cocos2d.h"
USING_NS_CC;

class CommonFunction
{
public:
    static void addColorLayer(Node *node);
    static void runPopUpAction(Node *node);
    static void runPopDownAction(Node *node, const std::function<void()> func);
    static void autoFullScreen(Node *node);
};

#endif /* CommonFuntion_hpp */
