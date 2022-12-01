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

    _Voz = Label::createWithTTF("", "fonts/ComicRelief.ttf", 12);
    _Voz->enableGlow(Color4B::BLACK);
    _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_Voz, 8);
    _TextBox = Sprite::create("Utils/blueStextbox.png");
    _TextBox->setScale(1.3);
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


    auto Cumple = Label::createWithTTF("Cuando cumples?", "fonts/ComicRelief.ttf", 15);
    Cumple->enableGlow(Color4B::BLACK);
    auto cumple = MenuItemLabel::create(Cumple, CC_CALLBACK_0(Cambio::Cumple, this));
    cumple->setPosition(0, 0);
    auto FavComi = Label::createWithTTF("Cual es tu comida favorita?", "fonts/ComicRelief.ttf", 15);
    FavComi->enableGlow(Color4B::BLACK);
    auto favComi = MenuItemLabel::create(FavComi, CC_CALLBACK_0(Cambio::FavComi, this));
    favComi->setPosition(0, -30);
    auto FavPasat = Label::createWithTTF("Cual es tu pasatiempo favorito?", "fonts/ComicRelief.ttf", 15);
    FavPasat->enableGlow(Color4B::BLACK);
    auto favPasat = MenuItemLabel::create(FavPasat, CC_CALLBACK_0(Cambio::FavPasat, this));
    favPasat->setPosition(0, -60);
    auto Aspiraciones = Label::createWithTTF("A que aspiras?", "fonts/ComicRelief.ttf", 15);
    Aspiraciones->enableGlow(Color4B::BLACK);
    auto aspiraciones = MenuItemLabel::create(Aspiraciones, CC_CALLBACK_0(Cambio::Aspiraciones, this));
    aspiraciones->setPosition(0, -90);
    auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
    Volver->enableGlow(Color4B::BLACK);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Cambio::Volver, this));
    volver->setPosition(0, -120);

    _MainMenu = Menu::create(cumple, favComi, favPasat, aspiraciones, volver, NULL);
    _MainMenu->setPosition(175, 225);
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
    string pasado = Datos["Cumple"];

    if (Datos["Cumple"] == "")
    {
        _c->setTexture("Juli_sprites/Cabezas/Preocupada.png");
        _Voz->setString("mmm no parece que sepa\n tu cumpleanos aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {
        _c->setTexture("Juli_sprites/Cabezas/Neutral.png");
        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _c->setTexture("Juli_sprites/Cabezas/Nerviosa_mirando aun lado.png");
                _Voz->setString("Que dia cumples ?");
                auto Input = ui::TextField::create("___", "fonts/ComicRelief.ttf", 30);
                Input->setPosition(Vec2(100, 200));
                Input->setColor(Color3B(0, 255, 255));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["Cumple"])
                        {
                            string cumple = Input->getString();
                            Modi("Cumple", cumple);
                            _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");
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
    string pasado = Datos["FavComi"];

    if (Datos["FavComi"] == "")
    {
        _c->setTexture("Juli_sprites/Cabezas/Preocupada.png");
        _Voz->setString("mmm no parece que sepa\n tu comida favorita aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {
        _c->setTexture("Juli_sprites/Cabezas/Neutral.png");
        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _c->setTexture("Juli_sprites/Cabezas/Nerviosa_mirando aun lado.png");
                _Voz->setString("Cual es tu comida Favorita ?");
                auto Input = ui::TextField::create("___", "fonts/ComicRelief.ttf", 30);
                Input->setPosition(Vec2(100, 200));
                Input->setColor(Color3B(0, 255, 255));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["FavComi"])
                        {
                            string FavComi = Input->getString();
                            Modi("FavComi", FavComi);
                            _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");
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
    string pasado = Datos["FavPasat"];

    if (Datos["FavPasat"] == "")
    {
        _c->setTexture("Juli_sprites/Cabezas/Preocupada.png");
        _Voz->setString("mmm no parece que sepa\n tu pasatiempo favorito aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {
        _c->setTexture("Juli_sprites/Cabezas/Neutral.png");
        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _c->setTexture("Juli_sprites/Cabezas/Nerviosa_mirando aun lado.png");
                _Voz->setString("Cual es tu pasatiempo favorito ?");
                auto Input = ui::TextField::create("___", "fonts/ComicRelief.ttf", 30);
                Input->setPosition(Vec2(100, 200));
                Input->setColor(Color3B(0,255,255));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["FavPasat"])
                        {
                            string FavPasat = Input->getString();
                            Modi("FavPasat", FavPasat);
                            _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");
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
    string pasado = Datos["Aspiraciones"];

    if (Datos["Aspiraciones"] == "")
    {
        _c->setTexture("Juli_sprites/Cabezas/Preocupada.png");
        _Voz->setString("mmm no parece que sepa\n tus aspiraciones aun \n asi que no puedo cambiarlo");
        auto Return = EventListenerKeyboard::create();
        Return->onKeyPressed = CC_CALLBACK_2(Cambio::VolverT, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);

    }
    else {
        _c->setTexture("Juli_sprites/Cabezas/Neutral.png");
        _Voz->setString("Ok parece que cambiaste, entonces");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                _c->setTexture("Juli_sprites/Cabezas/Nerviosa_mirando aun lado.png");
                _Voz->setString("A que aspiras ?");
                auto Input = ui::TextField::create("___", "fonts/ComicRelief.ttf", 30);
                Input->setPosition(Vec2(100, 200));
                Input->setColor(Color3B(0, 255, 255));
                this->addChild(Input, 10);
                auto ST2 = EventListenerKeyboard::create();
                ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
                    if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
                    {
                        if (pasado == Datos["Aspiraciones"])
                        {
                            string Aspiraciones = Input->getString();
                            Modi("Aspiraciones", Aspiraciones);
                            _c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");
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
