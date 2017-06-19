//
//  UIModuleManager.hpp
//  Minos
//
//  Created by Jingjing on 2017/6/19.
//
//

#ifndef UIModuleManager_hpp
#define UIModuleManager_hpp

#include "Singleton.hpp"
#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;
//using ms::Singleton;

class UIBaseLayer;

class UIModuleManager
{
public:
    void pushModule(UIBaseLayer* layer, const string& name);
    void popModule(UIBaseLayer* layer, const string& name);
    UIBaseLayer* getModule(const string& name);
private:
    unordered_map<string, UIBaseLayer*> _modules;
};
//#define UIModuleMangerINS Singleton<UIModuleManager>::GetInstance();

#endif /* UIModuleManager_hpp */
