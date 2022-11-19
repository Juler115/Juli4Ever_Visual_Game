#include "Juli4Ever.h"
#include <ui/UITextField.h>

USING_NS_CC;

Scene* Cambio::createScene()
{
    return Cambio::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Cambio.cpp\n");
}

bool Cambio::init()
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

    _Voz = Label::createWithTTF("", "fonts/Marker Felt.ttf", 12);
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


    auto Cumple = Label::createWithTTF("Cuando cumples?", "fonts/Marker Felt.ttf", 15);
    auto cumple = MenuItemLabel::create(Cumple, CC_CALLBACK_0(Cambio::Cumple, this));
    cumple->setPosition(0, 0);
    auto FavComi = Label::createWithTTF("Cual es tu comida favorita?", "fonts/Marker Felt.ttf", 15);
    auto favComi = MenuItemLabel::create(FavComi, CC_CALLBACK_0(Cambio::FavComi, this));
    favComi->setPosition(0, -20);
    auto FavPasat = Label::createWithTTF("Cual es tu pasatiempo favorito?", "fonts/Marker Felt.ttf", 15);
    auto favPasat = MenuItemLabel::create(FavPasat, CC_CALLBACK_0(Cambio::FavPasat, this));
    favPasat->setPosition(0, -40);
    auto Aspiraciones = Label::createWithTTF("A que aspiras?", "fonts/Marker Felt.ttf", 15);
    auto aspiraciones = MenuItemLabel::create(Aspiraciones, CC_CALLBACK_0(Cambio::Aspiraciones, this));
    aspiraciones->setPosition(0, -60);
    auto Volver = Label::createWithTTF("Volver", "fonts/Marker Felt.ttf", 15);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Cambio::Volver, this));
    volver->setPosition(0, -80);

    _MainMenu = Menu::create(cumple, favComi, favPasat, aspiraciones, volver, NULL);
    _MainMenu->setPosition(200, 200);
    this->addChild(_MainMenu, 6);


    return true;
}

void Cambio::Volver()
{
    Act();
    auto scene = Hablar::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Cambio::VolverT(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    Act();
    auto scene = Hablar::createScene();
    Director::getInstance()->replaceScene(scene);
}


void Cambio::Cumple()
{
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
    string pasado = Datos["Cumple"];

    if (Datos["Cumple"] == "")
    {
        _Voz->setString("mmm no parece que sepa tu cumpleanos aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {

        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _Voz->setString("Que dia cumples ?");
                auto Input = ui::TextField::create("cumple", "fonts/Marker Felt.ttf", 30);
                Input->setPosition(Vec2(200, 200));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["Cumple"])
                        {
                            string cumple = Input->getString();
                            Modi("Cumple", cumple);
                            _Voz->setString("Entendido lo recordare");
                            Input->setPosition(Vec2(1000, 1000));
                            Act();
                        }
                        auto Return = EventListenerKeyboard::create();
                        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
                        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);
                    }
                };
                _eventDispatcher->addEventListenerWithSceneGraphPriority(ST2, this);
            }

        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }

}
void Cambio::FavComi()
{
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
    string pasado = Datos["FavComi"];

    if (Datos["FavComi"] == "")
    {
        _Voz->setString("mmm no parece que sepa tu comida favorita aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {

        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _Voz->setString("Cual es tu comida Favorita ?");
                auto Input = ui::TextField::create("FavComi", "fonts/Marker Felt.ttf", 30);
                Input->setPosition(Vec2(200, 200));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["FavComi"])
                        {
                            string FavComi = Input->getString();
                            Modi("FavComi", FavComi);
                            _Voz->setString("Entendido lo recordare");
                            Input->setPosition(Vec2(1000, 1000));
                            Act();
                        }
                        auto Return = EventListenerKeyboard::create();
                        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
                        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);
                    }
                };
                _eventDispatcher->addEventListenerWithSceneGraphPriority(ST2, this);
            }

        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }
}
void Cambio::FavPasat()
{
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
    string pasado = Datos["FavPasat"];

    if (Datos["FavPasat"] == "")
    {
        _Voz->setString("mmm no parece que sepa tu pasatiempo favorito aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {

        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _Voz->setString("Cual es tu pasatiempo favorito ?");
                auto Input = ui::TextField::create("FavPasat", "fonts/Marker Felt.ttf", 30);
                Input->setPosition(Vec2(200, 200));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["FavPasat"])
                        {
                            string FavPasat = Input->getString();
                            Modi("FavPasat", FavPasat);
                            _Voz->setString("Entendido lo recordare");
                            Input->setPosition(Vec2(1000, 1000));
                            Act();
                        }
                        auto Return = EventListenerKeyboard::create();
                        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
                        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);
                    }
                };
                _eventDispatcher->addEventListenerWithSceneGraphPriority(ST2, this);
            }

        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }
}
void Cambio::Aspiraciones()
{
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
    string pasado = Datos["Aspiraciones"];

    if (Datos["Aspiraciones"] == "")
    {
        _Voz->setString("mmm no parece que sepa tus aspiraciones aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {

        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _Voz->setString("A que aspiras ?");
                auto Input = ui::TextField::create("Aspiraciones", "fonts/Marker Felt.ttf", 30);
                Input->setPosition(Vec2(200, 200));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["Aspiraciones"])
                        {
                            string Aspiraciones = Input->getString();
                            Modi("Aspiraciones", Aspiraciones);
                            _Voz->setString("Entendido lo recordare");
                            Input->setPosition(Vec2(1000, 1000));
                            Act();
                        }
                        auto Return = EventListenerKeyboard::create();
                        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
                        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);
                    }
                };
                _eventDispatcher->addEventListenerWithSceneGraphPriority(ST2, this);
            }

        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }
}
