#include "Functions.h"

void Cambi(int x)
{
	switch (x)
	{
    case 1: CACumple(); cout << "\n"; break;
	case 2: CAFavComi(); cout << "\n"; break;
	case 3: CAFavPasat(); cout << "\n"; break;
	case 4: CAAspiraciones(); cout << "\n"; break;
	}
}

void Cambio()
{

	int selec;
    if (Datos["Cumple"] == "" || Datos["FavComi"] == "" || Datos["FavPasat"] == "" || Datos["Aspiraciones"] == "")
        cout << "Lo siento, aun no te conozco lo suficiente\n\n";
    else {
        do
        {
            cout << " Que deseas cambiar sobre ti ?\n";
            cout << "1. Fecha de nacimiento\n";
            cout << "2. Comida favorita\n";
            cout << "3. Pasatiempo Favorito\n";
            cout << "4. Aspiraciones\n";
            cout << "5. Salir\n";
            cin >> selec;
            system("cls");
            Cambi(selec);
        } while (selec != 5);
    }

}
void CACumple()
{
        cout << "Que dia cumples ?\n";
        string cumple;
        cin.ignore();
        getline(cin, cumple);
        Modi("Cumple", cumple);
        cout << "Entendido,lo recordare :3\n";
}
void CAFavComi()
{
        cout << "Cual es tu comida favorita?\n";
        string comi;
        cin.ignore();
        getline(cin, comi);
        Modi("FavComi", comi);
        cout << "Entendido,la recordare :3\n";
}
void CAFavPasat()
{
        cout << "Cual es tu Pasatiempo favorito?\n";
        string pasa;
        cin.ignore();
        getline(cin, pasa);
        Modi("FavPasat", pasa);
        cout << "Entendido,lo recordare :3\n";
}
void CAAspiraciones()
{
        cout << "Cual es tu mayor deseo a futuro?\n";
        string aspi;
        cin.ignore();
        getline(cin, aspi);
        Modi("Aspiraciones", aspi);
        cout << "Entendido,lo recordare :3\n";
}
void CAAfecto()
{
    Modi("Afecto", to_string(Juli.Afecto()));
}
