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

#ifndef __Juli4Ever_SCENE_H__
#define __Juli4Ever_SCENE_H__

#include "cocos2d.h"
#include "Functions.h"

class BienvenidaS : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void Op(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    CREATE_FUNC(BienvenidaS);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};


class Juli4Ever : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void MainMenu(cocos2d::Ref* pSender);
    void Hablarrr(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Juli4Ever);
private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};

class Hablar : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void Preguntar(cocos2d::Ref* pSender);
    void Volver(cocos2d::Ref* pSender);
    CREATE_FUNC(Hablar);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};

class Preguntar : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void EresP(cocos2d::Ref* pSender);
    void SirvesP(cocos2d::Ref* pSender);
    void PensamientosP(cocos2d::Ref* pSender);
    void NosotrosP(cocos2d::Ref* pSender);
    void MiP(cocos2d::Ref* pSender);
    void Volver(cocos2d::Ref* pSender);
    void VolverT(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    CREATE_FUNC(Preguntar);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};

#endif
