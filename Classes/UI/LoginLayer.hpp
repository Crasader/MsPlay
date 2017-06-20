//
//  LoginLayer.hpp
//  Minos
//
//  Created by jingjing on 2017/6/20.
//
//

#ifndef LoginLayer_hpp
#define LoginLayer_hpp

#include "UIBaseLayer.hpp"

class LoginLayer : public UIBaseLayer
{
public:
    static void show();
    LoginLayer();
    ~LoginLayer();
    virtual bool init() override;
    CREATE_FUNC(LoginLayer);
private:
    void initUI();
public:
    
};

#endif /* LoginLayer_hpp */
