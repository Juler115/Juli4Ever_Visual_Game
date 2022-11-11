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
    Music("ZZ Top  La Grange");
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

    _l = Sprite::create("Juli_sprites/Poses/1l.png");
    _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_l, 3);
    _r = Sprite::create("Juli_sprites/Poses/1r.png");
    _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_r, 4);
    _c = Sprite::create("Juli_sprites/Cabezas/Feliz.png");
    _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
    this->addChild(_c, 5);

    auto Hablar = Label::createWithTTF("Volver", "fonts/Marker Felt.ttf", 20);
    Hablar->setPosition(0, -5);
    auto habl = Sprite::create("Utils/blueStextbox.png");
    habl->setPosition(0, -5);
    auto habl2 = Sprite::create("Utils/bluetextbox.png");
    habl2->setPosition(0, -5);
    auto hablar = MenuItemLabel::create(Hablar, CC_CALLBACK_1(Hablar::Volver, this));
    auto hable = MenuItemSprite::create(habl, habl2, CC_CALLBACK_1(Hablar::Volver, this));

    auto Jugar = Label::createWithTTF("Jugar", "fonts/Marker Felt.ttf", 20);
    Jugar->setPosition(0, -20);
    auto jugar = MenuItemLabel::create(Jugar);

    auto Musica = Label::createWithTTF("Musica", "fonts/Marker Felt.ttf", 20);
    Musica->setPosition(0, -40);
    auto musica = MenuItemLabel::create(Musica);
    _MainMenu = Menu::create(hable, hablar, jugar, musica, NULL);
    _MainMenu->setPosition(200, 200);
    this->addChild(_MainMenu, 6);
   
    return true;
	/*
	int selec;

	do
	{
		Act();
		cout << "De que te gustaria hablar ahora ?\n";
		cout << "1. Preguntar\n";
		cout << "2. Quiero que me conozcas\n";
		cout << "3. Me siento...\n";
		cout << "4. Te quiero decir...\n";
		cout << "5. Quiero cambiar algo\n";
		cout << "6. Volver\n";
		cin >> selec;
		system("cls");
		Hablar_Op(selec);
	} while (selec != 6);

}
void Hablar_Op(int selec)
{

	switch (selec)
	{
	case 1: system("cls"), Preguntar(); break;
	case 2: system("cls"), Conocer(); break;
	case 3: system("cls"), Siento(); break;
	case 4: system("cls"), Decir(); break;
	case 5: system("cls"), Cambio(); break;
	}
}*/
}

void Hablar::Volver(Ref* pSender)
{
    auto scene = Juli4Ever::createScene();
    Director::getInstance()->replaceScene(scene);
}

