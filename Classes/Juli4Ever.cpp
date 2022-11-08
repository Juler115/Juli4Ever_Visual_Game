/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "Juli4Ever.h"

USING_NS_CC;

Julieta Juli("1", "2", "3");

Scene* Juli4Ever::createScene()
{
    return Juli4Ever::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Juli4Ever::init()
{
    check();
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto back = Sprite::create("Utils/daylight_Background.png");
    back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(back, 0);

        auto Habla = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 12);
        Habla->setString(Bienvenida());
        Habla->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
        this->addChild(Habla, 2);
        auto dial = Sprite::create("Utils/blueStextbox.png");
        dial->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
        this->addChild(dial, 1);

    _l = Sprite::create("Juli_sprites/Poses/1l.png");
    _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
        this->addChild(_l, 3);
    _r = Sprite::create("Juli_sprites/Poses/1r.png");
    _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
        this->addChild(_r, 4);
    _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
    _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
        this->addChild(_c, 5);


        auto myScene = Scene::create();

        auto Hablar = Label::createWithTTF("Hablar", "fonts/Marker Felt.ttf", 20);
        Hablar->setPosition(100, 100);
        auto hablar = MenuItemLabel::create(Hablar);

        auto Jugar = Label::createWithTTF("Jugar", "fonts/Marker Felt.ttf", 20);
        Jugar->setPosition(100, 80);
        auto jugar = MenuItemLabel::create(Jugar);

        auto Musica = Label::createWithTTF("Musica", "fonts/Marker Felt.ttf", 20);
        Musica->setPosition(100, 60);
        auto musica = MenuItemLabel::create(Musica);

        auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            CC_CALLBACK_1(Juli4Ever::menuCloseCallback, this));
        //closeItem->setPosition(50, 50);

        _MainMenu = Menu::create(hablar, jugar, musica, closeItem,NULL);
        _MainMenu->setPosition(100, 100);
        this->addChild(_MainMenu, 6);    
        
        

    return true;
}



void Juli4Ever::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
