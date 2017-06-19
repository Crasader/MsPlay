//
//  LogoLayer.hpp
//  Minos
//
//  Created by jingjing on 2017/6/19.
//
//

#ifndef LogoLayer_hpp
#define LogoLayer_hpp

#include "UIBaseLayer.hpp"

class LogoLayer : public UIBaseLayer
{
public:
    static void show();
    LogoLayer();
    ~LogoLayer();
    virtual bool init();
    CREATE_FUNC(LogoLayer);
    
private:
    void initUI();
    void runDefaultLogoAction();
    void runCampLogoAction();
    void runGameLogoAction();
private:
    ImageView* m_gameLogo;
    ImageView* m_campLogo;
    ImageView* m_defaultLogo;
};

#endif /* LogoLayer_hpp */
