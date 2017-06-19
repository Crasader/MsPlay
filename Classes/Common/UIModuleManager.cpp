//
//  UIModuleManager.cpp
//  Minos
//
//  Created by Jingjing on 2017/6/19.
//
//

#include "UIModuleManager.hpp"

void UIModuleManager::pushModule(UIBaseLayer *layer, const string &name)
{
    _modules.insert({name, layer});
}

void UIModuleManager::popModule(UIBaseLayer *layer, const string &name)
{
    _modules.erase(name);
}

UIBaseLayer* UIModuleManager::getModule(const string &name)
{
    auto it = _modules.find(name);
    if(it != _modules.end())
        return (*it).second;
    return nullptr;
}
