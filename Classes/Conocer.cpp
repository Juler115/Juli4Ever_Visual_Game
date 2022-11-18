#include "Juli4Ever.h"
#include <ui/UITextField.h>
bool Usados[5];
//int x = 0;
bool hola = true;

USING_NS_CC;

Scene* Conocer::createScene()
{
    return Conocer::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in Conocer.cpp\n");
}

bool Conocer::init()
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

    _Voz = Label::createWithTTF("", "fonts/Marker Felt.ttf", 12);
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

    /*
    int c=1;
    srand(time(NULL));
    if (Datos["Cumple"] != "" && Datos["FavComi"] != "" && Datos["FavPasat"] != "" && Datos["Aspiraciones"] != "")
    {
        auto ST1 = EventListenerKeyboard::create();
        ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            _Voz->setString("Conozco suficiente de ti \n te parece si hacemos otra cosa ?");
            auto Return = EventListenerKeyboard::create();
            Return->onKeyPressed = CC_CALLBACK_2(Conocer::VolverT, this);
            _eventDispatcher->addEventListenerWithSceneGraphPriority(Return, this);
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    }
    else {
        do {
           // c = 1 + rand() % 4;
        } while (Usados[c] == true);
        switch (c)
        {
        case 1: Usados[c] = true; CC_CALLBACK_1(Conocer::Cumple,this);break;
        case 2: Usados[c] = true; CC_CALLBACK_1(Conocer::FavComi, this); break;
        case 3: Usados[c] = true; CC_CALLBACK_1(Conocer::FavPasat, this); break;
        case 4: Usados[c] = true; CC_CALLBACK_1(Conocer::Aspiraciones, this); break;
        }
    }*/
    if(hola)
    hola=false,Cumple();
    
    
    return true;
}

void Conocer::Volver()
{
    auto scene = Hablar::createScene();
    Director::getInstance()->replaceScene(scene);
}
void Conocer::VolverT(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    auto scene = Hablar::createScene();
    Director::getInstance()->replaceScene(scene);
}

void Conocer::Cumple()
{
    int x = 0;
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
    _Voz->setString("Ok es mi turno de preguntar entonces");
    x = 1;
    auto move5 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 100));
    _Voz->runAction(move5);


    auto ST1 = EventListenerKeyboard::create();
    ST1->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        _Voz->setString("Que dia cumples ?");
        auto Input = ui::TextField::create("cumple", "fonts/Marker Felt.ttf", 30);
        Input->setPosition(Vec2(200, 200));
        this->addChild(Input,10);
        
        auto ST2 = EventListenerKeyboard::create();
        ST2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
            {
               //cumple = Input->getString();
               string cumple = "hola";
               log("%s", cumple);
               Volver();
            }
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(ST2, this);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(ST1, this);
    /*
    if (Datos["Cumple"] == "") {
        cin.ignore();
        getline(cin, cumple);
        ofstream data;
        data.open("Data.txt", ios::app);
        data << "\nCumple " << cumple;
        //cout << "Entendido,lo recordare :3\n";
        Juli.Afs();
    }*/
    //else cout << "cumples el " + Datos["Cumple"] + " aun lo recuerdo :3\n";
}
void Conocer::FavComi(Ref* pSender)
{
    if (Datos["FavComi"] == "") {
        cout << "Cual es tu comida favorita?\n";
        string comi;
        cin.ignore();
        getline(cin, comi);
        ofstream data;
        data.open("Data.txt", ios::app);
        data << "\nFavComi " << comi;
        cout << "Entendido,la recordare :3\n";
        Juli.Afs();
    }
    else cout << "Tu comida favorita era " + Datos["FavComi"] + " aun la recuerdo :3\n";
}
void Conocer::FavPasat(Ref* pSender)
{
    if (Datos["FavPasat"] == "") {
        cout << "Cual es tu Pasatiempo favorito?\n";
        string pasa;
        cin.ignore();
        getline(cin, pasa);
        ofstream data;
        data.open("Data.txt", ios::app);
        data << "\nFavPasat " << pasa;
        cout << "Entendido,lo recordare :3\n";
        Juli.Afs();
    }
    else cout << "Tu pasatiempo favortio era " + Datos["FavPasat"] + " aun lo recuerdo :3\n";
}
void Conocer::Aspiraciones(Ref* pSender)
{
    if (Datos["Aspiraciones"] == "") {
        cout << "Cual es tu mayor deseo a futuro?\n";
        string aspi;
        cin.ignore();
        getline(cin, aspi);
        ofstream data;
        data.open("Data.txt", ios::app);
        data << "\nAspiraciones " << aspi;
        cout << "Entendido,lo recordare :3\n";
        Juli.Afs();
    }
    else cout << "Tu mayor deseo era " + Datos["Aspiraciones"] + " aun lo recuerdo :3\n";
}