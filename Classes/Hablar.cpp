#include "Juli4Ever.h"

USING_NS_CC;

Scene* Hablar::createScene()
{
	return Hablar::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Hablar.cpp\n");
}


bool Hablar::init()
{
	
    Act();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto back = Sprite::create("Utils/daylight_Background.png");
    back->setScale(1.3);
    back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(back, 0);

    _Voz = Label::createWithTTF("De que quieres Hablar?", "fonts/ComicRelief.ttf", 12);
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

    auto Preguntar = Label::createWithTTF("Preguntar", "fonts/ComicRelief.ttf", 15);
    Preguntar->enableGlow(Color4B::BLACK);
    auto preguntar = MenuItemLabel::create(Preguntar, CC_CALLBACK_1(Hablar::Preguntar, this));
    preguntar->setPosition(0, 0);
    auto Conozcas = Label::createWithTTF("Quiero que me conozcas", "fonts/ComicRelief.ttf", 15);
    Conozcas->enableGlow(Color4B::BLACK);
    auto conozcas = MenuItemLabel::create(Conozcas, CC_CALLBACK_1(Hablar::Conocer, this));
    conozcas->setPosition(0, -30);
    auto Siento = Label::createWithTTF("Me siento...", "fonts/ComicRelief.ttf", 15);
    Siento->enableGlow(Color4B::BLACK);
    auto siento = MenuItemLabel::create(Siento, CC_CALLBACK_1(Hablar::Siento, this));
    siento->setPosition(0, -60);
    auto Decir = Label::createWithTTF("Te quiero decir...", "fonts/ComicRelief.ttf", 15);
    Decir->enableGlow(Color4B::BLACK);
    auto decir = MenuItemLabel::create(Decir, CC_CALLBACK_1(Hablar::Decir, this));
    decir->setPosition(0, -90);
    auto Cambiar = Label::createWithTTF("Quiero cambiar algo", "fonts/ComicRelief.ttf", 15);
    Cambiar->enableGlow(Color4B::BLACK);
    auto cambiar = MenuItemLabel::create(Cambiar, CC_CALLBACK_1(Hablar::Cambio, this));
    cambiar->setPosition(0, -120);
    auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
    Volver->enableGlow(Color4B::BLACK);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_1(Hablar::Volver, this));
    volver->setPosition(0, -150);

    _MainMenu = Menu::create(preguntar,conozcas,siento,decir,cambiar,volver,NULL);
    _MainMenu->setPosition(175, 250);
    this->addChild(_MainMenu, 6);
   
    return true;
	
}

void Hablar::Volver(Ref* pSender)
{
    auto scene = Juli4Ever::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Hablar::Preguntar(Ref* pSender)
{
    auto scene = Preguntar::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Hablar::Conocer(Ref* pSender)
{
    auto scene = Conocer::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Hablar::Cambio(Ref* pSender)
{
    auto scene = Cambio::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Hablar::Siento(Ref* pSender)
{
    auto scene = Siento::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Hablar::Decir(Ref* pSender)
{
    auto scene = Decir::createScene();
    Director::getInstance()->replaceScene(scene);
}

