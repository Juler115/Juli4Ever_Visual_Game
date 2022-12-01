#include "Functions.h"

string Bienvenida() {
	if (Juli.Afecto() >= -1)
	{
		int x;
		srand(time(NULL));
		x = 1 + rand() % 5;
		switch (x)
		{
		case 1: return "Hola bienvenido de nuevo" + Datos["Nombre"]; break;
		case 2: return "Que tal tu dia" + Datos["Nombre"] + "?"; break;
		case 3: return "Te extrane" + Datos["Nombre"]; break;
		case 4: return "Crei que me habias olvidado" + Datos["Nombre"]; break;
		default: return "Tanto tiempo como has estado" + Datos["Nombre"] + "?"; break;
		}
	}
	else
	{
		return "No estoy tan feliz como crees despues de lo que dijiste";
	}
}