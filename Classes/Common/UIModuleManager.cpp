//
//  UIModuleManager.cpp
//  Minos
//
//  Created by Jingjing on 2017/6/19.
//
//

#include "UIModuleManager.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

UIModuleManager* UIModuleManager::_instance = nullptr;

UIModuleManager* UIModuleManager::getInstance() {
    if( _instance == nullptr ) {
        _instance = new UIModuleManager();
    }
    return _instance;
}

void UIModuleManager::destroyInstance()
{
    if (_instance != nullptr)
    {
        delete _instance;
        _instance = nullptr;
    }
}


void UIModuleManager::pushModule(Layer *layer, const string& name)
{
    _modules.insert({name, layer});
}

void UIModuleManager::popModule(const string& name)
{
    _modules.erase(name);
}

Layer* UIModuleManager::getModule(const string& name)
{
    auto it = _modules.find(name);
    if(it != _modules.end())
        return (*it).second;
    return nullptr;
}

void UIModuleManager::dump()
{
    cout << std::left;
    cout << setw(50) << setfill('+') << "+" << endl;
    cout << setw(20) << setfill(' ') << "+" << setw(10) << setfill(' ') << "dump start"
    << setw(19)  << setfill(' ') << "" << setw(1) << "+" << endl;
    
    cout << setw(10) << setfill(' ') <<"+" << setw(15) << setfill(' ') << "module" << setw(15)  << setfill(' ') << "name"
    << setw(9) << setfill(' ') << "" << setw(1) << "+" << endl;
    
    for (auto item : _modules)
    {
        cout << setw(10) << setfill(' ') << "+" << setw(15) << setfill(' ') << item.second
        << setw(15)  << setfill(' ') << item.first
        << setw(9) << setfill(' ') << "" << setw(1) << "+" << endl;
    }
    cout << setw(50) << setfill('+') << "+" << endl;
}
