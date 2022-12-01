#include "Functions.h"
map<string, string> Datos;
vector<string> DatMusic;

bool check()
{
    ifstream infile("Data.txt");
    if (infile.good())
    {
        Act();
        Juli.AcAf(stoi(Datos["Afecto"]));
        Juli.ActRel(stoi(Datos["Relacion"]));
        ifstream leer;
        leer.open("Music.txt", ios::in);
        string Mus;
        while (!leer.eof())
        {
            getline(leer, Mus);
            DatMusic.push_back(Mus);
        }
        leer.close();
        return 1;
    }
    else
    {
        dat();
        ofstream data;
        data.open("Data.txt", ios::app);
        data << "\nAfecto " << 0;
        data << "\nRelacion " << 0;
        data.close();
        Act();
        Juli.AcAf(stoi(Datos["Afecto"]));
        Juli.ActRel(stoi(Datos["Relacion"]));
        ifstream leer;
        leer.open("Music.txt", ios::in);
        string Mus;
        while (!leer.eof())
        {
            getline(leer, Mus);
            DatMusic.push_back(Mus);
        }
        leer.close();
        return 0;
    }
}
void dat()
{
    ifstream data;
    data.open("Data.txt", ios::app);
    data.close();
}
void Act()
{
    ifstream leer;
    leer.open("Data.txt", ios::in);
    string datos;
    while (!leer.eof())
    {
        leer >> datos;
        string aux;
        getline(leer, aux);
        Datos[datos] = aux;
        if (datos == "Cumple")Usados[1] = true;
        else if(datos == "FavComi")Usados[2] = true;
        else if (datos == "FavPasat")Usados[3] = true;
        else if (datos == "Aspiraciones")Usados[4] = true;
    }
    leer.close();
}
void Modi(string tipo, string info)
{
    Act();
    ofstream modi;
    modi.open("Data.txt", ios::trunc);
    for (auto& a : Datos)
    {
        if (a.second == "")continue;
        if (a.first==tipo)
        {
            modi<<"\n" << tipo <<" " << info;
        }
        else {
            modi <<"\n" << a.first << a.second;
        }
    }
}
void ACF()
{
    Modi("Afecto", to_string(Juli.Afecto()));
}
void CAAfecto()
{
    Modi("Afecto", to_string(Juli.Afecto()));
}