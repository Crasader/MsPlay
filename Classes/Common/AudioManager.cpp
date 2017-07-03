//
//  AudioManager.cpp
//  Minos
//
//  Created by jingjing on 2017/6/29.
//
//

#include "AudioManager.hpp"

AudioManager* AudioManager::_instance = nullptr;
SimpleAudioEngine*  AudioManager::_engine = SimpleAudioEngine::getInstance();

AudioManager* AudioManager::getInstance() {
    if( _instance == nullptr ) {
        _instance = new AudioManager();
    }
    return _instance;
}

void AudioManager::destroyInstance()
{
    if (_instance != nullptr)
    {
        delete _instance;
        _instance = nullptr;
    }
}

void AudioManager::playMusic(const std::string &filename, bool loop)
{
    _engine->playBackgroundMusic(filename.c_str(), loop);
}

void AudioManager::popMusic(const std::string &filename)
{
    _engine->stopBackgroundMusic();
}

void AudioManager::playSound(const std::string &filename, bool loop)
{
    _engine->playEffect(filename.c_str());
}

void AudioManager::stopSound(unsigned int &soundID)
{
    _engine->stopEffect(soundID);
}

