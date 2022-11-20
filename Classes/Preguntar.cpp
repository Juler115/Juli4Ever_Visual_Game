#include "Juli4Ever.h"

int x = 0;

USING_NS_CC;

Scene* Preguntar::createScene()
{
	return Preguntar::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Preguntar.cpp\n");
}


bool Preguntar::init()
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

    _Voz = Label::createWithTTF("Que te gustaria saber?", "fonts/Marker Felt.ttf", 12);
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


    auto Quien = Label::createWithTTF("Quien eres?", "fonts/Marker Felt.ttf", 15);
    auto quien = MenuItemLabel::create(Quien, CC_CALLBACK_1(Preguntar::EresP, this));
    quien->setPosition(0, 0);
    auto Servir = Label::createWithTTF("Para que sirves?", "fonts/Marker Felt.ttf", 15);
    auto servir = MenuItemLabel::create(Servir, CC_CALLBACK_1(Preguntar::SirvesP, this));
    servir->setPosition(0, -20);
    auto Pienso = Label::createWithTTF("Cuales son tus pensamientos?", "fonts/Marker Felt.ttf", 15);
    auto pienso = MenuItemLabel::create(Pienso, CC_CALLBACK_1(Preguntar::PensamientosP, this));
    pienso->setPosition(0, -40);
    auto Nosotros = Label::createWithTTF("Que piensas sobre nosotros?", "fonts/Marker Felt.ttf", 15);
    auto nosotros = MenuItemLabel::create(Nosotros, CC_CALLBACK_1(Preguntar::NosotrosP, this));
    nosotros->setPosition(0, -60);
    auto Cuentame = Label::createWithTTF("Cuentame algo sobre ti?", "fonts/Marker Felt.ttf", 15);
    auto cuentame = MenuItemLabel::create(Cuentame, CC_CALLBACK_1(Preguntar::MiP, this));
    cuentame->setPosition(0, -80);
    auto Volver = Label::createWithTTF("Volver", "fonts/Marker Felt.ttf", 15);
    auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_1(Preguntar::Volver, this));
    volver->setPosition(0, -100);


    _MainMenu = Menu::create(quien, servir, pienso, nosotros, cuentame, volver, NULL);
    _MainMenu->setPosition(200, 200);
    this->addChild(_MainMenu, 6);

	return true;

}

void Preguntar::EresP(Ref* pSender)
{
    x = 0;
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
    _Voz->setString(Eres(x));
    x = 1;

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (x == EresT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Eres(x));
                x++;
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);

}
void Preguntar::SirvesP(Ref* pSender)
{
    x = 0;
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
    _Voz->setString(Sirves(x));
    x = 1;

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (x == SirvesT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Sirves(x));
                x++;
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);

}
void Preguntar::PensamientosP(Ref* pSender)
{
    x = 0;
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
    _Voz->setString(Pensamientos(x));
    x = 1;

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (x == PensamientosT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Pensamientos(x));
                x++;
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);

}
void Preguntar::NosotrosP(Ref* pSender)
{
    x = 0;
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
    _Voz->setString(Nosotros(x));
    x = 1;

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (x == NosotrosT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Nosotros(x));
                x++;
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
}
void Preguntar::MiP(Ref* pSender)
{
    x = 0;
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
    _Voz->setString(Mi(x));
    x = 1;

    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
        {
            if (x == MiT.size())
            {
                VolverT();
            }
            else {
                _Voz->setString(Mi(x));
                x++;
            }
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);

}
void Preguntar::Volver(Ref* pSender)
{
    auto scene = Hablar::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Preguntar::VolverT()
{
    auto scene = Preguntar::createScene();
       Director::getInstance()->replaceScene(scene);
}