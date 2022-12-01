#include "Juli4Ever.h"
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

    _Voz = Label::createWithTTF("Es Hora de jugar!!!\n veamos que tan bueno eres", "fonts/ComicRelief.ttf", 12);
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

	auto Volver = Label::createWithTTF("Volver", "fonts/ComicRelief.ttf", 15);
	Volver->enableGlow(Color4B::BLACK);
	auto volver = MenuItemLabel::create(Volver, CC_CALLBACK_0(VacasYToros::Volver, this));
	volver->setPosition(0, -100);
	_MainMenu = Menu::create(volver, NULL);
	_MainMenu->setPosition(175, 200);
	this->addChild(_MainMenu, 6);
	/*
	int num = 10000 + rand() % 99999;
	//cout << num;
	string pienso = to_string(num);
	string adiv;
	cout << "Juguemos vacas y toros, yo pienso en un numero y tu trataras de adivinarlo\n";
	cout << "Si algun numero esta correcto sera una vaca, si ademas de estar correcto esta en la posicion correcta, sera un toro \n";
	cout << "Que empiece la diversion!!!!\n";
	do {
		cout << "Si deseas volver ingresa el numero -1\n";
		cout << "Ingresa tu prediccion de 5 digitos\n";
		cin >> adiv;
		if (adiv == to_string(-1)) return;
		while (adiv.size() > 5 || adiv.size() < 5) {
			cout << "Porfavor ingresa un numero de 5 digitos\n";
			cin >> adiv;
		}
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
		cout << "toros: ";
		for (auto& a : toros) cout << a << " ";
		cout << "\n";
		cout << "vacas: ";
		for (auto& a : vacas) cout << a << " ";
		cout << "\n";
	} while (pienso != adiv);
	system("cls");
	cout << "Felicidades acertaste :3";
	*/

    return true;

}


void VacasYToros::Volver()
{
    auto scene = Jugar::createScene();
    Director::getInstance()->replaceScene(scene);
}



