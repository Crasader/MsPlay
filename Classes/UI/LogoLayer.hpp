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
    virtual bool init() override;
    CREATE_FUNC(LogoLayer);
    void test();
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
