#include "Functions.h"
bool Usados[5];

void Conocer()
{
    int x;
    srand(time(NULL));
    if (Datos["Cumple"] != "" && Datos["FavComi"] != "" && Datos["FavPasat"] != "" && Datos["Aspiraciones"] != "")
        cout << "Conozco suficiente de ti por ahora, te parece si hacemos otra cosa ?\n\n";
    else {
        cout << "Ok, es mi turno de preguntar entonces\n";
        do {
            x = 1 + rand() % 4;
        } while (Usados[x] == true);
        switch (x)
        {
        case 1: Cumple(); Usados[x] = true; break;
        case 2: FavComi(); Usados[x] = true;  break;
        case 3: FavPasat(); Usados[x] = true; break;
        case 4: Aspiraciones(); Usados[x] = true; break;
        }
    }
}
void Cumple()
{
    if (Datos["Cumple"] == "") {
        cout << "Que dia cumples ?\n";
        string cumple;
        cin.ignore();
        getline(cin, cumple);
        ofstream data;
        data.open("Data.txt", ios::app);
        data << "\nCumple " << cumple;
        cout << "Entendido,lo recordare :3\n";
        Juli.Afs();
    }
    else cout << "cumples el " + Datos["Cumple"] + " aun lo recuerdo :3\n";
}
void FavComi()
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
void FavPasat()
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
void Aspiraciones()
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