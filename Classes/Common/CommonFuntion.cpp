//
//  CommonFuntion.cpp
//  Minos
//
//  Created by jingjing on 2017/6/22.
//
//

#include "CommonFuntion.hpp"
USING_NS_CC;

void CommonFunction::addColorLayer(cocos2d::Node *node)
{
    Size winSize = Director::getInstance()->getWinSize();
    LayerColor * laye = LayerColor::create(Color4B(40, 40, 40, 160), winSize.width, winSize.height);
    node->addChild(laye, -1);
}

void CommonFunction::runPopUpAction(Node *node)
{
    node->setScale(0.2);
    node->runAction(Sequence::create(EaseBackOut::create(ScaleTo::create(0.25, 1)), NULL));
}

void CommonFunction::runPopDownAction(Node *node, const std::function<void()> func)
{
    EaseBackIn *easeback = EaseBackIn::create(ScaleTo::create(0.25, 0));
    if (func)
    {
        CallFunc *call = CallFunc::create(func);
        node->runAction(Sequence::create(easeback, call, NULL));
    }
    else
    {
        node->runAction(easeback);
    }
}

void CommonFunction::autoFullScreen(Node *node)
{
    Size winSize = Director::getInstance()->getWinSize();
    Size nodeSize = node->getContentSize();
    node->setScale(std::max(winSize.width / nodeSize.width, winSize.height / nodeSize.height));
}
