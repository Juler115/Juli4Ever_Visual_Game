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
    check();
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto back = Sprite::create("Utils/daylight_Background.png");
    back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(back, 0);

    _Voz = Label::createWithTTF("Como te sientes hoy?", "fonts/Marker Felt.ttf", 12);
    _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_Voz, 2);
    _TextBox = Sprite::create("Utils/blueStextbox.png");
    _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_TextBox, 1);

    /*
    _l = Sprite::create("Juli_sprites/Poses/1l.png");
    _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_l, 3);
    _r = Sprite::create("Juli_sprites/Poses/1r.png");
    _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_r, 4);
    _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
    _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
    this->addChild(_c, 5);*/


    auto Enojado = Label::createWithTTF("Enojado", "fonts/Marker Felt.ttf", 15);
    auto enojado = MenuItemLabel::create(Enojado, CC_CALLBACK_0(Siento::EnojadoP, this));
    enojado->setPosition(0, 0);
    auto Triste = Label::createWithTTF("Triste", "fonts/Marker Felt.ttf", 15);
    auto triste = MenuItemLabel::create(Triste, CC_CALLBACK_0(Siento::TristeP, this));
    triste->setPosition(0, -20);
    auto Feliz = Label::createWithTTF("Feliz", "fonts/Marker Felt.ttf", 15);
    auto feliz = MenuItemLabel::create(Feliz, CC_CALLBACK_0(Siento::FelizP, this));
    feliz->setPosition(0, -40);
    auto Aburrido = Label::createWithTTF("Aburrido", "fonts/Marker Felt.ttf", 15);
    auto aburrido = MenuItemLabel::create(Aburrido, CC_CALLBACK_0(Siento::AburridoP, this));
    aburrido->setPosition(0, -60);
    auto Nervioso = Label::createWithTTF("Nervioso", "fonts/Marker Felt.ttf", 15);
    auto nervioso = MenuItemLabel::create(Nervioso, CC_CALLBACK_0(Siento::NerviosoP, this));
    nervioso->setPosition(0, -80);
    auto Volver = Label::createWithTTF("Volver", "fonts/Marker Felt.ttf", 15);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Siento::Volver, this));
    volver->setPosition(0, -100);


    _MainMenu = Menu::create(enojado, triste, feliz, aburrido, nervioso, volver, NULL);
    _MainMenu->setPosition(200, 200);
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
    /*
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);*/
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Enojado(s));
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
                s++;
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
    /*
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);*/
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Triste(s));
    s = 1;

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
                s++;
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
    /*
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);*/
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Feliz(s));
    s = 1;

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
    /*
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);*/
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Aburrido(s));
    s = 1;

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
    /*
    auto move = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _l->runAction(move);
    auto move2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30));
    _r->runAction(move2);
    auto move3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y + 30 - .15));
    _c->runAction(move3);*/
    auto move4 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _TextBox->runAction(move4);
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);
    _Voz->setString(Nervioso(s));
    s = 1;

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