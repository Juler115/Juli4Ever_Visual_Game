#include "Juli4Ever.h"

int s = 0;

USING_NS_CC;

Scene* Siento::createScene()
{
    return Siento::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Hablar.cpp\n");
}


bool Siento::init()
{
    Act();
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto back = Sprite::create("Utils/daylight_Background.png");
    back->setScale(1.3);
    back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(back, 0);

    _Voz = Label::createWithTTF("Como te sientes hoy?", "fonts/ComicRelief.ttf", 12);
    _Voz->enableGlow(Color4B::BLACK);
    _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_Voz, 8);
    _TextBox = Sprite::create("Utils/blueStextbox.png");
    _TextBox->setScale(1.2);
    _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_TextBox, 7);

    
    _l = Sprite::create("Juli_sprites/Poses/1l.png");
    _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_l, 3);
    _r = Sprite::create("Juli_sprites/Poses/1r.png");
    _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_r, 4);
    _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
    _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
    this->addChild(_c, 5);


    auto Enojado = Label::createWithTTF("Enojado", "fonts/ComicRelief.ttf", 15);
    Enojado->enableGlow(Color4B::BLACK);
    auto enojado = MenuItemLabel::create(Enojado, CC_CALLBACK_0(Siento::EnojadoP, this));
    enojado->setPosition(0, 0);
    auto Triste = Label::createWithTTF("Triste", "fonts/ComicRelief.ttf", 15);
    Triste->enableGlow(Color4B::BLACK);
    auto triste = MenuItemLabel::create(Triste, CC_CALLBACK_0(Siento::TristeP, this));
    triste->setPosition(0, -30);
    auto Feliz = Label::createWithTTF("Feliz", "fonts/ComicRelief.ttf", 15);
    Feliz->enableGlow(Color4B::BLACK);
    auto feliz = MenuItemLabel::create(Feliz, CC_CALLBACK_0(Siento::FelizP, this));
    feliz->setPosition(0, -60);
    auto Aburrido = Label::createWithTTF("Aburrido", "fonts/ComicRelief.ttf", 15);
    Aburrido->enableGlow(Color4B::BLACK);
    auto aburrido = MenuItemLabel::create(Aburrido, CC_CALLBACK_0(Siento::AburridoP, this));
    aburrido->setPosition(0, -90);
    auto Nervioso = Label::createWithTTF("Nervioso", "fonts/ComicRelief.ttf", 15);
    Nervioso->enableGlow(Color4B::BLACK);
    auto nervioso = MenuItemLabel::create(Nervioso, CC_CALLBACK_0(Siento::NerviosoP, this));
    nervioso->setPosition(0, -120);
    auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
    Volver->enableGlow(Color4B::BLACK);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Siento::Volver, this));
    volver->setPosition(0, -150);


    _MainMenu = Menu::create(enojado, triste, feliz, aburrido, nervioso, volver, NULL);
    _MainMenu->setPosition(175, 250);
    this->addChild(_MainMenu, 6);

    return true;

}

void Siento::EnojadoP()
{
    s = 0;
    auto men = MoveTo::create(0.000001, Vec2(2000, 2000));
    _MainMenu->runAction(men);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Enojado(s));
    _c->setTexture("Juli_sprites/Cabezas/Preocupada por ti.png");
    s = 1;

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (s == EnojadoT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Enojado(s));
                _c->setTexture("Juli_sprites/Cabezas/Nerviosa_boca abierta.png");
                s++;
                if (s == EnojadoT.size())
                {
                    _c->setTexture("Juli_sprites/Cabezas/Feliz_Boca abierta.png");
                }
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);


}

void Siento::TristeP()
{
    s = 0;
    auto men = MoveTo::create(0.000001, Vec2(2000, 2000));
    _MainMenu->runAction(men);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Triste(s));
    s = 1;
    _c->setTexture("Juli_sprites/Cabezas/Preocupada por ti.png");

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (s == TristeT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Triste(s));
                _c->setTexture("Juli_sprites/Cabezas/Feliz_Boca abierta.png");
                s++;
                if (s == TristeT.size())
                {
                    _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");
                }
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
}
void Siento::FelizP()
{
    s = 0;
    auto men = MoveTo::create(0.000001, Vec2(2000, 2000));
    _MainMenu->runAction(men);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Feliz(s));
    s = 1;
    _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (s == FelizT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Feliz(s));
                s++;
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
}
void Siento::AburridoP()
{
    s = 0;
    auto men = MoveTo::create(0.000001, Vec2(2000, 2000));
    _MainMenu->runAction(men);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Aburrido(s));
    s = 1;
    _c->setTexture("Juli_sprites/Cabezas/Preocupada.png");

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (s == AburridoT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Aburrido(s));
                s++;
                _c->setTexture("Juli_sprites/Cabezas/Feliz_Boca abierta.png");
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
}
void Siento::NerviosoP()
{
    s = 0;
    auto men = MoveTo::create(0.000001, Vec2(2000, 2000));
    _MainMenu->runAction(men);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Nervioso(s));
    s = 1;
    _c->setTexture("Juli_sprites/Cabezas/Feliz.png");

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (s == NerviosoT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Nervioso(s));
                s++;
                _c->setTexture("Juli_sprites/Cabezas/Feliz_Boca abierta.png");
                if (s == TristeT.size())
                {
                    _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");
                }
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
}
void Siento::Volver()
{
    auto scene = Hablar::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Siento::VolverT()
{
    auto scene = Siento::createScene();
    Director::getInstance()->replaceScene(scene);
}