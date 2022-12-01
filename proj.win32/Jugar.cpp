#include "Juli4Ever.h"


USING_NS_CC;

Scene* Jugar::createScene()
{
    return Jugar::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Jugar.cpp\n");
}


bool Jugar::init()
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

    _Voz = Label::createWithTTF("Que te gustaria jugar?", "fonts/ComicRelief.ttf", 12);
    _Voz->enableGlow(Color4B::BLACK);
    _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_Voz, 7);
    _TextBox = Sprite::create("Utils/blueStextbox.png");
    _TextBox->setScale(1.15);
    _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_TextBox, 6);

    _l = Sprite::create("Juli_sprites/Poses/3l.png");
    _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_l, 3);
    _r = Sprite::create("Juli_sprites/Poses/2r.png");
    _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_r, 4);
    _c = Sprite::create("Juli_sprites/Cabezas/Feliz_Boca abierta.png");
    _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
    this->addChild(_c, 5);


    auto VCT = Label::createWithTTF("Vacas y Toros", "fonts/ComicRelief.ttf", 15);
    VCT->enableGlow(Color4B::BLACK);
    auto vCT = MenuItemLabel::create(VCT, CC_CALLBACK_0(Jugar::VyT, this));
    vCT->setPosition(0, -20);
    auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
    Volver->enableGlow(Color4B::BLACK);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Jugar::Volver, this));
    volver->setPosition(0, -80);

    _MainMenu = Menu::create(vCT,volver, NULL);
    _MainMenu->setPosition(175, 200);
    this->addChild(_MainMenu, 6);

    return true;

}

void Jugar::VyT()
{
    Music("ZZ Top  La Grange");
    auto scene = VacasYToros::createScene();
    Director::getInstance()->replaceScene(scene);
}

void Jugar::Volver()
{
    auto scene = Juli4Ever::createScene();
    Director::getInstance()->replaceScene(scene);
}
