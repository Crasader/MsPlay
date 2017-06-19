//
//  AppSystem.cpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#include "AppSystem.hpp"

AppSystem* AppSystem::_instance = nullptr;

AppSystem* AppSystem::getInstance() {
    if( _instance == nullptr ) {
        _instance = new AppSystem();
        _instance->init();
    }
    
    return _instance;
}

AppSystem::~AppSystem() {
    throw std::runtime_error("Can not delete GameSystem!");
}

void AppSystem::init()
{
    loadAllConfig();
    _appScene = AppScene::create();
    Director::getInstance()->runWithScene(_appScene);
}

void AppSystem::loadAllConfig()
{
}

void AppSystem::unloadAllConfig()
{
}

void AppSystem::unloadConfig()
{
}

void AppSystem::reloadConfig()
{
}

void AppSystem::restart() {
    
    _reconnectCount = 0;
    unloadConfig();
    reloadConfig();
}

void AppSystem::resetGame() {
    
    _reconnectCount = 0;
    
    unloadAllConfig();
    loadAllConfig();
    
    _appScene = AppScene::create();
    Director::getInstance()->replaceScene(_appScene);
}
