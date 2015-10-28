//
//  UI.cpp
//  UIDemo
//
//  Created by student on 15/8/8.
//
//

#include "UI.h"
 UI * UI:: createWithTag(int tag){
     UI *ui=new (std:: nothrow)UI;
     if (ui&&ui->initWithTag(tag)) {
         ui->autorelease();
         return ui;
     }
     
     CC_SAFE_DELETE(ui);
     return nullptr;
     
}
bool UI::initWithTag(int tag){
    if (!cocos2d::Scene::init()) {
        return false;
    }
    switch (tag) {
        case 1:
            initScale9Sprite();
            break;
            
        case 2:
            initListView();
            break;
            
        case 3:
            initLoadingBar();
            break;
            
        case 4:
            initPageView();
            break;
            
        case 5:
            initSliderView();
            break;
            
        case 6:
            initButton();
            break;
            
        case 7:
            initCheckBox();
            break;
            
        case 8:
            initImageView();
            break;
            
        case 9:
            initEditBox();
            break;
            
        case 10:
            initSrollView();
            break;
            
        case 11:
            initLayout();
            break;
        
            
        default:
            break;
    }
    
    
    
    
    return true;
}
void UI::onMenuBack(cocos2d::Ref *sender){

    
    
}
//9宫格
void UI::initScale9Sprite(){
    auto visibleSize=cocos2d::Director::getInstance()->getVisibleSize();
    auto s9p1=Scale9Sprite::create("HelloWorld.png");
    s9p1->setPosition(visibleSize.width/2,visibleSize.height-200);
    s9p1->setContentSize(cocos2d::Size(300,200));
    addChild(s9p1);
    
    auto s9p2=Scale9Sprite::create("HelloWorld.png");
    s9p2->setPosition(visibleSize.width/2,200);
    s9p2->setContentSize(cocos2d::Size(150,100));
    addChild(s9p2);
                         
    
}
void UI::initLoadingBar(){
    auto visibleSize=cocos2d::Director::getInstance()->getVisibleSize();
    auto lb=LoadingBar::create("editBG.png");
    auto lb1=lb->getContentSize();
    log("%f,%f",lb1.width,lb1.height);
    lb->setScale9Enabled(true);
    lb->setContentSize(Size(300,300));
    lb->setPosition(visibleSize/2);
    lb->setDirection(LoadingBar::Direction::LEFT);
    lb->setPercent(30);
    addChild(lb,2,1);
    //调度器
    schedule(CC_CALLBACK_1(UI::LoadingBarUpdate,this),"LoadingBarUpdate");


}
void UI::LoadingBarUpdate(float dt){
    LoadingBar *lb =dynamic_cast<LoadingBar*>(getChildByTag(1));
    CCASSERT(lb, "the childer with tag 1 is not a loadingBar Class");
    float per=lb->getPercent()+0.5f;
    lb->setPercent(per);
    if (per>=100) {
        per=100;
        unschedule("LoadingBarUpdate");
    }
}
//滑块
void UI::initSliderView(){
    auto visibleSiez=cocos2d::Director::getInstance()->getVisibleSize();
    auto sl=Slider::create();
    //轨道
    sl->loadBarTexture("xuetiao1.png");
    //覆盖轨道
    sl->loadProgressBarTexture("xuetiao2.png");
    sl->loadSlidBallTextureNormal("switch-thumb.png");
    sl->loadSlidBallTexturePressed("switch-thumb.png");
    sl->loadSlidBallTextureDisabled("switch-thumb.png");
    //添加事件
    sl->addEventListener(CC_CALLBACK_2(UI::SliserCall, this));
    sl->setPercent(30);
    sl->setPosition(visibleSiez/2);
    addChild(sl);
}

void UI::SliserCall(cocos2d::Ref *sender,cocos2d::ui::Slider::EventType t){
    cocos2d::ui::Slider *item=dynamic_cast<cocos2d::ui::Slider *>(sender);
    CCASSERT(item, "sender is not a Slider Class");
    CCLOG("Slider Value :%d",item->getPercent());

}
//按钮
void UI:: initButton(){
    auto visibleSize=Director::getInstance()->getVisibleSize();
    auto ub=Button::create();
    ub->loadTextureNormal("0.png");
    ub->loadTexturePressed("2.png");
    ub->loadTextureDisabled("2.png");
    ub->setScale9Enabled(true);
    ub->setContentSize(cocos2d::Size(128,128));
    ub->setPressedActionEnabled(true);
    ub->setZoomScale(2);
    ub->setTitleFontName("fonts/Marker Felt.ttf");
    ub->setTitleFontSize(30);
    ub->setTitleColor(cocos2d::Color3B::YELLOW);
    ub->setTitleText("HHLLO Button");
   // ub->addClickEventListener(CC_CALLBACK_1(UI::buttonClick, this));
    //添加触摸事件
    ub->addTouchEventListener (this,toucheventselector(UI::buttonClick));
    ub->setPosition(visibleSize/2);
    addChild(ub);
    
}
void UI:: buttonClick( cocos2d::Ref* sendr){
    Button* item=dynamic_cast<Button*>(sendr);
    CCASSERT(item, "sender is not a Button Class");
    CCLOG("ui::Button be Clicked");
}
//复选框
void UI:: initCheckBox(){
    auto visibleSize=Director::getInstance()->getVisibleSize();
    auto cb=CheckBox::create();
    cb->loadTextureBackGround("switch-mask.png");
    cb->loadTextureBackGroundSelected("switch-on.png");//点击时候
    cb->loadTextureFrontCross("switch-off.png");
    cb->addEventListener(CC_CALLBACK_2(UI::checkBoxClick, this));
    cb->setPosition(visibleSize/2);
    addChild(cb);
}

void UI::checkBoxClick(cocos2d::Ref* , cocos2d::ui::CheckBox::EventType ty){
    if (ty==CheckBox::EventType::SELECTED) {
        CCLOG("now is selected state");
    }else{
        CCLOG("now is nuselected state");
    }
}



void UI:: initImageView(){
    auto visibleSive=Director::getInstance()->getVisibleSize();
    auto iv=ImageView::create("HelloWorld.png");
    iv->setScale9Enabled(true);
    iv->setContentSize(cocos2d::Size(960,640));
    iv->setPosition(visibleSive/2);
    addChild(iv);
}

void UI::initEditBox(){
    auto visibleSize=Director::getInstance()->getVisibleSize();
    auto eb=EditBox::create(cocos2d::Size(800,200) ,"editBG.png");
    eb->setPlaceHolder("请输入内容");
    eb->setPlaceholderFont("font/Marker Felt.ttf", 40);
    eb->setPlaceholderFontColor(Color3B::YELLOW);
    eb->setFont("font/Marker Felt.ttf", 20);
    eb->setColor(Color3B::BLACK);
    //eb->setInputFlag(cocos2d::ui::EditBox::InputFlag::PASSWORD);
    eb->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);
    eb->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    //设置代理
    eb->setDelegate(this);
    eb->setMaxLength(20);
    eb->setPosition(visibleSize/2);
    addChild(eb);
    
}

void UI:: editBoxEditingDidBegin(EditBox* editBox){
    log("DidBegin");
}
void UI:: editBoxEditingDidEnd(EditBox* editBox){

    log("DidEnd");
}
void UI:: editBoxTextChanged(EditBox* editBox, const std::string& text){

    log("TextChanged");
    log("输入改变了:%s",text.c_str());
}
void UI:: editBoxReturn(EditBox* editBox){
    log("BoxReturen");
}


void UI:: initSrollView(){
    auto sc=ScrollView::create();
    //表面的大小
    sc->setContentSize(cocos2d::Size(960,640));
    //内部大小
    sc->setInnerContainerSize(cocos2d::Size(960*5,640));
    sc->setDirection(cocos2d::ui::ScrollView::Direction::HORIZONTAL);
    //默认回弹是关闭的
    sc->setBounceEnabled(true);
    //默认惯性滑动是开启的
    sc->setInertiaScrollEnabled(true);
   // sc->addEventListener(CC_CALLBACK_2(UI::ScrollView, this));
    for (int i=0; i<5; i++) {
        auto sp=Sprite::create("HelloWorld.png");
        sp->setPosition(Vec2(480+960*i,320));
        sc->addChild(sp);
    }
    sc->setPosition(Vec2(0,0));
    this-> addChild(sc);
}
void UI:: ScrollView(Ref*s,cocos2d::ui::ScrollView::EventType ty){
    auto scr=dynamic_cast<class ScrollView*>(s);
    if (ty==ScrollView::EventType::BOUNCE_BOTTOM)
        CCLOG("Bounce_BOtton");
    else if (ty==cocos2d::ui::ScrollView::EventType::BOUNCE_LEFT)
        CCLOG("scroll_To_left");
    else if(ty==cocos2d::ui::ScrollView::EventType::BOUNCE_RIGHT);
       CCLOG("Scroll_To_Right");
    
    Point a=scr->getInnerContainer()->getPosition();
    log("x=%f,y=%f",a.x,a.y);
}


void UI::initListView(){
    auto lv=ListView::create();
    lv->setContentSize(cocos2d::Size(640,480));
    lv->setItemsMargin(20);//设置间隔
    lv->setDirection(cocos2d::ui::ScrollView::Direction::VERTICAL);
        for (int i=0; i<50; i++) {
        auto ub=Button::create();
        ub->loadTextureNormal("0.png");
        ub->loadTexturePressed("1.png");
        ub->loadTextureDisabled("0.png");
        ub->setScale9Enabled(true);
        ub->setContentSize(Size(600,400));
        ub->setPressedActionEnabled(true);
        ub->setZoomScale(0.5f);
        ub->addClickEventListener(CC_CALLBACK_1(UI::buttonClick, this));
        ub->setTag(i);
        lv->pushBackCustomItem(ub);
    }
   
    lv->addEventListener(CC_CALLBACK_2(UI::ListViewCall, this));
    addChild(lv);

}
void UI:: ListViewCall(cocos2d::Ref *sender,ListView::EventType ty){
    ListView *item=dynamic_cast<ListView*>(sender);
    CCASSERT(item, "item si not a ListView class");
    if (ty==ListView::EventType::ON_SELECTED_ITEM_START) {
        long a= item->getCurSelectedIndex();
        CCLOG("start");
        log("a=%ld",a);
    }
    else if (ty==cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END)
    {
        CCLOG("end");
    }

}
//初始化Layout
void UI::initLayout(){
    auto lo=Layout::create();
    lo->setBackGroundImage("HelloWorld.png");
    lo->setBackGroundImageScale9Enabled(true);
    lo->setContentSize(Size(480,320)*1.5);
    for (int i=0; i<5; i++) {
        for (int j=0; j<7; j++) {
            auto ub=Button::create();
            ub->loadTextureNormal("editBG.png");
            ub->loadTexturePressed("editBG.png");
            ub->loadTextureDisabled("editBg.png");
            ub->setScale9Enabled(true);
            ub->setContentSize(Size(100,50));
            ub->setPressedActionEnabled(true);
            ub->setZoomScale(0.5f);
            ub->setTitleFontName("fonts/Marker Felt.ttf");
            ub->setTitleFontSize(30);
            ub->setTitleColor(Color3B::GREEN);
            ub->setTitleText(StringUtils::format("%d--%d",i,j));
            ub->addClickEventListener(CC_CALLBACK_1(UI::buttonClick, this));
            ub->setTag(i);
            ub->setPosition(Vec2(70+120*i, 35+j*60));
            lo->addChild(ub);
        }
    }
    addChild(lo);
   
}

Layout* UI::createLayout(int i){
    auto lo=Layout::create();
    lo->setBackGroundImage("HelloWorld.png");
    lo->setBackGroundImageScale9Enabled(true);
    lo->setContentSize(Size(480,320)*1.5);
    for (int i=0; i<5; i++) {
        for (int j=0; j<7; j++) {
            auto ub=Button::create();
            ub->loadTextureNormal("editBG.png");
            ub->loadTexturePressed("editBG.png");
            ub->loadTextureDisabled("editBg.png");
            ub->setScale9Enabled(true);
            ub->setContentSize(Size(100,50));
            ub->setPressedActionEnabled(true);
            ub->setZoomScale(0.5f);
            ub->setTitleFontName("fonts/Marker Felt.ttf");
            ub->setTitleFontSize(30);
            ub->setTitleColor(Color3B::GREEN);
            ub->setTitleText(StringUtils::format("%d--%d",i,j));
            ub->addClickEventListener(CC_CALLBACK_1(UI::buttonClick, this));
            ub->setTag(i);
            ub->setPosition(Vec2(70+120*i, 35+j*60));
            lo->addChild(ub);
        }
    }
    return lo;
}

void UI::initPageView(){
    auto pv=PageView::create();
    pv->setContentSize(Size(480,320)*1.5);
    for (int i=0; i<10; i++) {
        auto ly=createLayout(i);
        pv->addPage(ly);
    }
    //设置滑动阀值
    pv->setCustomScrollThreshold(100);
    pv->addEventListener(CC_CALLBACK_2(UI::pageView, this));
    pv->setPosition(Vec2::ZERO);
    addChild(pv);
    
}

void UI::pageView(cocos2d::Ref*sender ,cocos2d::ui::PageView::EventType ty ){
    PageView* item=dynamic_cast<PageView*>(sender);
    CCASSERT(item, "item is not a PageView class");
    CCLOG("curpage index is :%ld",item->getCurPageIndex());
    

}
