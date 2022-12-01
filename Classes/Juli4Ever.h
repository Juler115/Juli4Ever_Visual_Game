
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
    void Musica(cocos2d::Ref* pSender);
    void Jugar(cocos2d::Ref* pSender);
    
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
    void Conocer(cocos2d::Ref* pSender);
    void Cambio(cocos2d::Ref* pSender);
    void Siento(cocos2d::Ref* pSender);
    void Decir(cocos2d::Ref* pSender);
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
    void VolverT();
    CREATE_FUNC(Preguntar);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};
class Conocer : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void Cumple();
    void FavComi();
    void FavPasat();
    void Aspiraciones();
    void Volver();
    void VolverT(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    CREATE_FUNC(Conocer);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};
class Cambio : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void Cumple();
    void FavComi();
    void FavPasat();
    void Aspiraciones();
    void Volver();
    void VolverT(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    CREATE_FUNC(Cambio);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};
class Siento : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void EnojadoP();
    void TristeP();
    void FelizP();
    void AburridoP();
    void NerviosoP();
    void Volver();
    void VolverT();
    CREATE_FUNC(Siento);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};
class Decir : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void GustarP();
    void QuererP();
    void OdiarP();
    void DisculparP();
    void Volver();
    void VolverT();
    CREATE_FUNC(Decir);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};
class Musica : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void Musicc(int m);
    void Volver();
    CREATE_FUNC(Musica);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};
class Jugar : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void VyT();
    void Volver();
    CREATE_FUNC(Jugar);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};
class VacasYToros : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void Volver();
    CREATE_FUNC(VacasYToros);

private:
    cocos2d::Sprite* _TextBox;
    cocos2d::Label* _Voz;
    cocos2d::Sprite* _l;
    cocos2d::Sprite* _r;
    cocos2d::Sprite* _c;
    cocos2d::Menu* _MainMenu;

};

#endif
