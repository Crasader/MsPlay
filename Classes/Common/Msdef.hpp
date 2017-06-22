//
//  Msdef.hpp
//  Minos
//
//  Created by Jingjing on 2017/6/22.
//
//

#ifndef Msdef_hpp
#define Msdef_hpp

#include "AppSystem.hpp"
#include "../Display.hpp"

#define BIND_TOUCH_EVENT_LISTENER(function)   std::bind(&function, this, std::placeholders::_1, std::placeholders::_2)
#define MAINLAYER AppSystem::getInstance()->getScene()->getMainLayer()
#define display (*Display::getInstance())


#endif /* Msdef_hpp */
