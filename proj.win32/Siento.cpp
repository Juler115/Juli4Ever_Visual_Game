#include "Functions.h"

void Siento()
{
	int selec;
	do
	{
		cout << "Como te sientes ahora ?\n";
		cout << "1. Enojado\n";
		cout << "2. Triste\n";
		cout << "3. Feliz\n";
		cout << "4. Aburrido\n";
		cout << "5. Nervioso\n";
		cout << "6. Volver\n";
		cin >> selec;
		system("cls");
		SientoOp(selec);
	} while (selec != 6);
}
void SientoOp(int selec)
{
	switch (selec)
	{
	case 1: cout << Enojado()<<"\n"; break;
	case 2: cout << Triste()<<"\n"; break;
	case 3: cout << Feliz()<<"\n"; break;
	case 4: cout << Aburrido()<<"\n"; break;
	case 5: cout << Nervioso()<<"\n"; break;
	}
}