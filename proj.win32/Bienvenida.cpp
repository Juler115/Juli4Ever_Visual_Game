#include "Juli4Ever.h"

USING_NS_CC;

Scene* BienvenidaS::createScene()
{
    return BienvenidaS::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Hablar.cpp\n");
}


bool BienvenidaS::init()
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

    _Voz = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 12);
    _Voz->setString(Bienvenida());
    _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_Voz, 2);
    _TextBox = Sprite::create("Utils/blueStextbox.png");
    _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_TextBox, 1);

    _l = Sprite::create("Juli_sprites/Poses/1l.png");
    _l->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_l, 3);
    _r = Sprite::create("Juli_sprites/Poses/1r.png");
    _r->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_r, 4);
    _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
    _c->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30 - .15));
    this->addChild(_c, 5);


    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(BienvenidaS::Op, this));
    closeItem->setPosition(0, -5);

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(100, 100);
    this->addChild(menu, 1);

    return true;

}

void BienvenidaS::Op(Ref* pSender)
{
   
    auto scene = Juli4Ever::createScene();
    Director::getInstance()->replaceScene(scene);
}