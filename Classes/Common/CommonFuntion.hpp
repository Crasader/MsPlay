//
//  CommonFuntion.hpp
//  Minos
//
//  Created by jingjing on 2017/6/22.
//
//

#ifndef CommonFuntion_hpp
#define CommonFuntion_hpp
#include "cocos2d.h"
using cocos2d::Node;

class CommonFunction
{
public:
    static void addColorLayer(Node *node);
    static void runPopUpAction(Node *node);
    static void runPopDownAction(Node *node, const std::function<void()> func);
    static void autoFullScreen(Node *node);
};

#endif /* CommonFuntion_hpp */
