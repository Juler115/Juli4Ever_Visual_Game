#include "Functions.h"

void Preguntar()
{
	int selec;
	do
	{
		cout << "Que te gustaria preguntar ahora ?\n";
		cout << "1. Quien eres?\n";
		cout << "2. Para que sirves?\n";
		cout << "3. Cuales son tus pensamientos?\n";
		cout << "4. Que piensas sobre nosotros?\n";
		cout << "5. Cuentame algo sobre ti?\n";
		cout << "6. Volver\n";
		cin >> selec;
		system("cls");
		Preguntas(selec);
	} while (selec != 6);

}
void Preguntas(int selec)
{
	switch (selec)
	{
	case 1: cout << Eres()<<"\n"; break;
	case 2: cout << Sirves()<<"\n"; break;
	case 3: cout << Pensamientos()<<"\n"; break;
	case 4: cout << Nosotros()<<"\n"; break;
	case 5: cout << Mi()<<"\n"; break;
	}
}
