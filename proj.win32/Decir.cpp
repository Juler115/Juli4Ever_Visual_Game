#include "Juli4Ever.h"

USING_NS_CC;

Scene* Decir::createScene()
{
    return Decir::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Decir.cpp\n");
}


bool Decir::init()
{
    Act();
    log("%d", Juli.Afecto());
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

    _Voz = Label::createWithTTF("Te escucho", "fonts/ComicRelief.ttf", 12);
    _Voz->enableGlow(Color4B::BLACK);
    _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_Voz, 8);
    _TextBox = Sprite::create("Utils/blueStextbox.png");
    _TextBox->setScale(1.2);
    _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_TextBox, 7);

    if (Juli.Afecto() < -1) {
        _l = Sprite::create("Juli_sprites/Poses/2l.png");
        _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
        this->addChild(_l, 3);
        _r = Sprite::create("Juli_sprites/Poses/2r.png");
        _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
        this->addChild(_r, 4);
        _c = Sprite::create("Juli_sprites/Cabezas/Molesta.png");
        _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
        this->addChild(_c, 5);
    }
    else {
        _l = Sprite::create("Juli_sprites/Poses/1l.png");
        _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
        this->addChild(_l, 3);
        _r = Sprite::create("Juli_sprites/Poses/1r.png");
        _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
        this->addChild(_r, 4);
        _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
        _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
        this->addChild(_c, 5);
    }

    if (Juli.Afecto() >= 4)
    {
        auto Gustar = Label::createWithTTF("Me gustas", "fonts/ComicRelief.ttf", 15);
        Gustar->enableGlow(Color4B::BLACK);
        auto gustar = MenuItemLabel::create(Gustar, CC_CALLBACK_0(Decir::GustarP, this));
        gustar->setPosition(0, 0);
        auto Odiar = Label::createWithTTF("Te odio", "fonts/ComicRelief.ttf", 15);
        Odiar->enableGlow(Color4B::BLACK);
        auto odiar = MenuItemLabel::create(Odiar, CC_CALLBACK_0(Decir::OdiarP, this));
        odiar->setPosition(0, -30);
        auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
        Volver->enableGlow(Color4B::BLACK);
        auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Decir::Volver, this));
        volver->setPosition(0, -60);

        _MainMenu = Menu::create(gustar, odiar, volver, NULL);
        _MainMenu->setPosition(175, 225);
        this->addChild(_MainMenu, 6);
    }
    else if (Juli.Afecto() < -1)
    {
        _Voz->setString("No quiero hablar contigo,\n no me siento con los animos de verte");
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                auto Disculpa = Label::createWithTTF("Lamento lo que dije", "fonts/ComicRelief.ttf", 15);
                Disculpa->enableGlow(Color4B::BLACK);
                auto disculpa = MenuItemLabel::create(Disculpa, CC_CALLBACK_0(Decir::DisculparP, this));
                disculpa->setPosition(0, 0);
                auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
                Volver->enableGlow(Color4B::BLACK);
                auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Decir::Volver, this));
                volver->setPosition(0, -30);

                _MainMenu = Menu::create(disculpa, volver, NULL);
                _MainMenu->setPosition(175, 225);
                this->addChild(_MainMenu, 6);
            }
           
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);

    }
    else {
        auto Querer = Label::createWithTTF("Te quiero", "fonts/ComicRelief.ttf", 15);
        Querer->enableGlow(Color4B::BLACK);
        auto querer = MenuItemLabel::create(Querer, CC_CALLBACK_0(Decir::QuererP, this));
        querer->setPosition(0, 0);
        auto Odiar = Label::createWithTTF("Te odio", "fonts/ComicRelief.ttf", 15);
        Odiar->enableGlow(Color4B::BLACK);
        auto odiar = MenuItemLabel::create(Odiar, CC_CALLBACK_0(Decir::OdiarP, this));
        odiar->setPosition(0, -30);
        auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
        Volver->enableGlow(Color4B::BLACK);
        auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Decir::Volver, this));
        volver->setPosition(0, -60);

        _MainMenu = Menu::create(querer, odiar, volver, NULL);
        _MainMenu->setPosition(175, 225);
        this->addChild(_MainMenu, 6);
    }

    return true;

}

void Decir::GustarP()
{
    Music("My Feelings");
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

    if (Juli.Relacion() == false) {
        _c->setTexture("Juli_sprites/Cabezas/Feliz_Lagrimas_Boca abierta.png");
        _Voz->setString("De verdad?, yo tambien \n he pensado lo mismo");
        Juli.ActRel(true);
        Modi("Relacion", "1");
        ACF();
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                VolverT();
            }
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }
    else {
        _c->setTexture("Juli_sprites/Cabezas/Sorprendida_boca abierta.png");
        _Voz->setString("A mi tambien me sigues gustando");
        Juli.Afs();
        ACF();
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                VolverT();
            }
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }

}
void Decir::OdiarP()
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
    stopMusic();
    if (Juli.Afecto() < 0) {
        _c->setTexture("Juli_sprites/Cabezas/Enojada_Reprochando.png");
        _Voz->setString("No quiero que me hables");
        Juli.ActRel(false);
        Modi("Relacion", "0");
        Juli.Afb();
        ACF(); 
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                Director::getInstance()->end();
            }
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }
    else{
        _c->setTexture("Juli_sprites/Cabezas/Llorando.png");
        _Voz->setString("Eso no es muy lindo "+ Datos["Nombre"]);
        Juli.Afb();
        ACF();
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                VolverT();
            }
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }


}
void Decir::QuererP()
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

    _c->setTexture("Juli_sprites/Cabezas/Sorprendida_boca abierta.png");
        _Voz->setString("Yo tambien siento que te quiero");
        Juli.Afs();
        ACF();
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
                VolverT();
            }
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
}
void Decir::DisculparP()
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

    _c->setTexture("Juli_sprites/Cabezas/llorando_boca abierta.png");
    _Voz->setString("No fue nada lindo lo que dijiste\n no lo vuelvas a hacer" );
    Juli.AcAf(0);
    ACF();
    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            VolverT();
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
}

void Decir::Volver()
{
    auto scene = Hablar::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Decir::VolverT()
{
    auto scene = Decir::createScene();
    Director::getInstance()->replaceScene(scene);
}
