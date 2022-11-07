#include "Functions.h"

void Hablar()
{
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
}
