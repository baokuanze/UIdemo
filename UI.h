//
//  UI.h
//  UIDemo
//
//  Created by student on 15/8/8.
//
//

#ifndef __UIDemo__UI__
#define __UIDemo__UI__
#include <stdio.h>
#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocos2d;
USING_NS_CC;
#endif /* defined(__UIDemo__UI__) */
class UI:public cocos2d::Scene,public cocos2d::ui::EditBoxDelegate{
public:
    static UI *createWithTag(int tag);
    bool initWithTag(int tag);
    void onMenuBack(cocos2d::Ref *sender);
    //初始化Scale9Sprite
    void initScale9Sprite();
    //初始化                 
    void initLoadingBar();
    void LoadingBarUpdate(float dt);
    
   void initSliderView();
   void SliserCall(cocos2d::Ref *sender,cocos2d::ui::Slider::EventType ty);
    //初始化listView
    void initListView();
    void ListViewCall(cocos2d::Ref *sender,ListView::EventType ty);
    //初始化滑动视图
    void initSrollView();
    void ScrollView(Ref*s,cocos2d::ui::ScrollView::EventType ty);
    //按钮
    void initButton();
    void buttonClick(cocos2d::Ref* sendr);
    //初始化复选框
    void initCheckBox();
    void checkBoxClick(cocos2d::Ref* ,cocos2d::ui::CheckBox::EventType ty);
    //图片
    void initImageView();
     //文本框
    void initEditBox();
    void editBoxEditingDidBegin(EditBox* editBox);
    void editBoxEditingDidEnd(EditBox* editBox);
    void editBoxTextChanged(EditBox* editBox, const std::string& text);
    void editBoxReturn(EditBox* editBox);
   //分页。
    void initPageView();
    
    //louyoud
    void initLayout();
    Layout *createLayout(int i);
    void pageView(cocos2d::Ref*sender ,cocos2d::ui::PageView::EventType ty);





};
