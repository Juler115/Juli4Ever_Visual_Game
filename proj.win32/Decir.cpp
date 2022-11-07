#include "Functions.h"

void Decir()
{
	int selec;
	if (Juli.Afecto() >= 4)
	{
		do {
			cout << "1. Me gustas\n";
			cout << "2. Te odio\n";
			cout << "3. Regresar\n";
			cin >> selec;
			system("cls");
			DecirOp(selec);
		} while (selec != 3);
	}
	else if(Juli.Afecto()<0)
	{
		cout << "No quiero hablar contigo, no me siento con los animos de verte :c\n\n";
		do {
			cout << "1. Lamento lo que dije\n";
			cout << "2. Regresar\n";
			cin >> selec;
			system("cls");
		} while (selec < 1);
		if (selec == 1)
		{
			cout << "Me dolio un poco lo que me dijiste, pero confio en ti y se que no lo dijiste a proposito \n\n";
			Juli.AcAf(0);
		}
	}
	else {
		do {
			cout << "1. Te quiero\n";
			cout << "2. Te odio\n";
			cout << "3. Regresar\n";
			cin >> selec;
			system("cls");
			DecirOp2(selec);
		} while (selec != 3);
	}

}
void DecirOp(int selec)
{
	switch (selec)
	{
	case 1: Gustar(); break;
	case 2: {
		stopMusic();
		if (Juli.Afecto() < 0)
		{
			cout << "No quiero que me hables\n"; ACF(); Sleep(2000); exit(EXIT_FAILURE);
		}
		cout << "Eso no es muy lindo" << Datos["Nombre"]<<" >:c\n\n";
		Juli.Afb();
		break;
	}
	}
}
void DecirOp2(int selec)
{
	switch (selec)
	{
	case 1: {
		cout << "Yo tambien siento que te quiero :3\n\n";
		Juli.Afs();
		break;
	}
	case 2: {
		stopMusic();
		if (Juli.Afecto() < 0)
		{
			cout << "No quiero que me hables\n"; ACF(); Sleep(2000); exit(EXIT_FAILURE);
		}
		cout << "Eso no es muy lindo" << Datos["Nombre"] << " >:c\n\n";
		Juli.Afb();
		break;
	}
	}
}