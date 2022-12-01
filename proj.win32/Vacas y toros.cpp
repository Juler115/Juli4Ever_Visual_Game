#include "Juli4Ever.h"
#include <ui/UITextField.h>

vector<char> vacas;
vector<char> toros;

void clean() {
	vacas.clear();
	toros.clear();
}

USING_NS_CC;

Scene* VacasYToros::createScene()
{
    return VacasYToros::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in VacasYToros.cpp\n");
}


bool VacasYToros::init()
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

    _Voz = Label::createWithTTF("Juguemos vacas y toros, \n yo pienso en un numero\n y tu trataras de adivinarlo", "fonts/ComicRelief.ttf", 10);
    _Voz->enableGlow(Color4B::BLACK);
    _Voz->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_Voz, 7);
    _TextBox = Sprite::create("Utils/blueStextbox.png");
    _TextBox->setScale(1.15);
    _TextBox->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y - 100));
    this->addChild(_TextBox, 6);

    _l = Sprite::create("Juli_sprites/Poses/1l.png");
    _l->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_l, 3);
    _r = Sprite::create("Juli_sprites/Poses/1r.png");
    _r->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30));
    this->addChild(_r, 4);
    _c = Sprite::create("Juli_sprites/Cabezas/Feliz_Boca abierta.png");
    _c->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y + 30 - .15));
    this->addChild(_c, 5);

	auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
	Volver->enableGlow(Color4B::BLACK);
	auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(VacasYToros::Volver, this));
	volver->setPosition(0,0);
	_MainMenu = Menu::create(volver, NULL);
	_MainMenu->setPosition(175, 50);
	this->addChild(_MainMenu, 6);
	
	int num = 10000 + rand() % 99999;
	//cout << num;
	string pienso = to_string(num);

	auto inst = Label::createWithTTF("Si algun numero esta correcto\n  sera una vaca, si ademas de estar correcto \n esta en la posicion correcta, sera un toro", "fonts/ComicRelief.ttf", 12);
	inst->enableGlow(Color4B::YELLOW);
	//inst->setAlignment(TextHAlignment::);
	inst->setPosition(130, 270);
	this->addChild(inst, 10);
	auto Ing = Label::createWithTTF("Ingresa tu prediccion de 5 digitos", "fonts/ComicRelief.ttf", 12);
	Ing->enableGlow(Color4B::YELLOW);
	Ing->setPosition(100, 230);
	this->addChild(Ing, 12);
	auto Tor = Label::createWithTTF("", "fonts/ComicRelief.ttf", 12);
	Tor->enableGlow(Color4B::BLACK);
	Tor->setPosition(90, 210);
	this->addChild(Tor, 12);
	auto Vac = Label::createWithTTF("", "fonts/ComicRelief.ttf", 12);
	Vac->enableGlow(Color4B::BLACK);
	Vac->setPosition(90, 190);
	this->addChild(Vac, 12);
	

	auto Input = ui::TextField::create("___", "fonts/ComicRelief.ttf", 30);
	Input->setPosition(Vec2(100, 150));
	Input->setColor(Color3B(0, 255, 255));
	this->addChild(Input, 10);
	
		auto ST1 = EventListenerKeyboard::create();
		ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
			if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
			{
				string adiv = Input->getString();
				if (adiv.size() > 5 || adiv.size() < 5) {
					_Voz->setString("Porfavor ingresa un numero de 5 digitos");
					cin >> adiv;
				}
				else {
					clean();
					for (int i = 0; i < adiv.size(); i++)
					{
						for (int j = 0; j < pienso.size(); j++)
						{
							if (adiv[i] == pienso[j] && i == j)
							{
								toros.push_back(adiv[i]);
								break;
							}
							else if (adiv[i] == pienso[j])
							{
								vacas.push_back(adiv[i]);
								break;
							}
						}
					}
					string toross = "Toros: ";
					for (auto& a : toros) toross = toross + a + " ";
					Tor->setString(toross);
					string vacass = "Vacas: ";
					for (auto& a : vacas) vacass = vacass + a + " ";
					Vac->setString(vacass);

					if (adiv == pienso)
					{
						_Voz->setString("Felicidades, Lo descubriste");
						_c->setTexture("Juli_sprites/Cabezas/MuyFeliz.png");
						auto ST2 = EventListenerKeyboard::create();
						ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
							if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
							{
								this->Volver();
							}
						};
						_eventDispatcher->addEventListenerWithSceneGraphPriority(ST2, this);
					}
				}
			}

		};
		_eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);




    return true;

}


void VacasYToros::Volver()
{
    auto scene = Jugar::createScene();
    Director::getInstance()->replaceScene(scene);
}



