#include "Functions.h"

void Musica() {
	int selec;
	do
	{
		cout << "Dime que te gustaria escuchar ?\n";
		for (int i = 0; i < DatMusic.size(); i++)
		{
			cout << i << ". " << DatMusic[i]<<"\n";
		}
		cout << DatMusic.size() << ". " << "Regresar\n";
		cin >> selec;
		system("cls");
		if (selec < DatMusic.size())Music(DatMusic[selec]);
		else cout << "Ingrese porfavor un numero valido\n";
	
	} while (selec != DatMusic.size());
	system("cls");
}
void JuMusica(int selec) {
	try {
		Music(DatMusic[selec]);
	}
	catch (...)
	{
		cout << "hubo un error al inciar la musica";
	}
}