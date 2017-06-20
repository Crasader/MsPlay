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
#include "cocos2d.h"

using std::unordered_map;
using std::string;
using cocos2d::Layer;
//using namespace ms;


class UIModuleManager
{
public:
    static UIModuleManager* getInstance();
    static void destroyInstance();
    
    void pushModule(Layer* layer, const string& name);
    void popModule(const string& name);
    Layer* getModule(const string& name);
    void dump();
private:
    UIModuleManager() = default;
    ~UIModuleManager() = default;
    static UIModuleManager* _instance;
private:
    unordered_map<string, Layer*> _modules;
};

//#define UIModuleManagerInstance Singleton<UIModuleManager>::Instance()

#endif /* UIModuleManager_hpp */
