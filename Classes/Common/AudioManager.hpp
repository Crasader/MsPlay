//
//  AudioManager.hpp
//  Minos
//
//  Created by jingjing on 2017/6/29.
//
//

#ifndef AudioManager_hpp
#define AudioManager_hpp

#include <vector>
#include <string>
#include "cocos2d.h"
#include "../../cocos2d/cocos/audio/include/SimpleAudioEngine.h"
using CocosDenshion::SimpleAudioEngine;

class AudioManager
{
public:
    static AudioManager* getInstance();
    static void destroyInstance();
    
    void playMusic(const std::string &filename, bool loop);
    void popMusic(const std::string &filename);
    
    void playSound(const std::string &filename, bool loop);
    void stopSound(unsigned int &soundID);
    
private:
    AudioManager() = default;
    ~AudioManager() = default;
    static AudioManager* _instance;
    static SimpleAudioEngine* _engine;
    std::vector<std::string> _musicVec;
};

#endif /* AudioManager_hpp */
