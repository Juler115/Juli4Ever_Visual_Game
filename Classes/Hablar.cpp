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
	
    check();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto back = Sprite::create("Utils/daylight_Background.png");
    back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(back, 0);

    _Voz = Label::createWithTTF("De que quieres Hablar?", "fonts/Marker Felt.ttf", 12);
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

    //auto volvi = MenuItemSprite::create(volv, volv2, CC_CALLBACK_1(Hablar::Volver, this));

    auto Preguntar = Label::createWithTTF("Preguntar", "fonts/Marker Felt.ttf", 15);
    auto preguntar = MenuItemLabel::create(Preguntar, CC_CALLBACK_1(Hablar::Preguntar, this));
    preguntar->setPosition(0, 0);
    auto Conozcas = Label::createWithTTF("Quiero que me conozcas", "fonts/Marker Felt.ttf", 15);
    auto conozcas = MenuItemLabel::create(Conozcas, CC_CALLBACK_1(Hablar::Conocer, this));
    conozcas->setPosition(0, -20);
    auto Siento = Label::createWithTTF("Me siento...", "fonts/Marker Felt.ttf", 15);
    auto siento = MenuItemLabel::create(Siento, CC_CALLBACK_1(Hablar::Volver, this));
    siento->setPosition(0, -40);
    auto Decir = Label::createWithTTF("Te quiero decir...", "fonts/Marker Felt.ttf", 15);
    auto decir = MenuItemLabel::create(Decir, CC_CALLBACK_1(Hablar::Volver, this));
    decir->setPosition(0, -60);
    auto Cambiar = Label::createWithTTF("Quiero cambiar algo", "fonts/Marker Felt.ttf", 15);
    auto cambiar = MenuItemLabel::create(Cambiar, CC_CALLBACK_1(Hablar::Volver, this));
    cambiar->setPosition(0, -80);
    auto Volver = Label::createWithTTF("Volver", "fonts/Marker Felt.ttf", 15);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_1(Hablar::Volver, this));
    volver->setPosition(0, -100);

    _MainMenu = Menu::create(preguntar,conozcas,siento,decir,cambiar,volver,NULL);
    _MainMenu->setPosition(200, 200);
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

