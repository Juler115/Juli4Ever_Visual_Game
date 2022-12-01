#include "Juli4Ever.h"


USING_NS_CC;

Scene* Musica::createScene()
{
    return Musica::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Musica.cpp\n");
}


bool Musica::init()
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

    _Voz = Label::createWithTTF("Que te gustaria escuchar?", "fonts/ComicRelief.ttf", 12);
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
    

    int i = 0;
    Vector<MenuItem*> Canciones;
    for (i = 0; i < DatMusic.size(); i++)
    {
        auto Cancion = Label::createWithTTF(DatMusic[i], "fonts/ComicRelief.ttf", 10);
        Cancion->enableGlow(Color4B::BLACK);
        auto Sing = MenuItemLabel::create(Cancion, CC_CALLBACK_0(Musica::Musicc, this,i));
        Sing->setPosition(0, 0-(15*i));
        Canciones.pushBack(Sing);
    }
    auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 10);
    Volver->enableGlow(Color4B::BLACK);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(Musica::Volver, this));
    volver->setPosition(0, 0 - (15 * i));
    Canciones.pushBack(volver);

    _MainMenu = Menu::createWithArray(Canciones);
    _MainMenu->setPosition(150, 270);
    this->addChild(_MainMenu, 6);

    return true;

}

void Musica::Musicc(int m)
{
    int selec = m;
    Music(DatMusic[selec]);
}

void Musica::Volver()
{
    auto scene = Juli4Ever::createScene();
    Director::getInstance()->replaceScene(scene);
}
