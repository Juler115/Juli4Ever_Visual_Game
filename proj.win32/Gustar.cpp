#include "Functions.h"

void Gustar()
{
	Music("My Feelings");
	if (Juli.Relacion() == false) {
		cout << "De verdad, yo tambien he pensado lo mismo \n\n";
		system("Corazon.png");
		Juli.ActRel(true);
		Modi("Relacion", "1");
		//Sleep(1);
	}
	else {
		cout << "A mi tambien me sigues gustando \n";
		Juli.Afs();
	}
}