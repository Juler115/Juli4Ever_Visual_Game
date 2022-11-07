#include "Functions.h"

void Jugar()
{
	int selec;
	Music("ZZ Top  La Grange");
	do
	{
		cout << "Que quieres jugar ahora ?\n";
		cout << "1.Snake\n";
		cout << "2.Vacas y toros\n";
		cout << "3.Regresar\n";
		cin >> selec;
		JugarOp(selec);
		system("cls");

	} while (selec !=3);
	system("cls");



}
void JugarOp(int selec)
{
	switch (selec)
	{
		case 1: system("snake.exe"); system("color F"); break;
		case 2: system("cls"); TyV(); break;
	}
}