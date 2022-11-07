#include <iostream>
using namespace std;

class IA {

protected:
	int afecto=0;
	string nombre;
	string creacion;
	string futuro;
	bool viva=false;
	bool relacion=false;

public:

	int Afecto()
	{
		return afecto;
	}
	string Nombre()
	{
		return nombre;
	}
	string Creacion()
	{
		return creacion;
	}
	string Futuro()
	{
		return futuro;
	}
	bool Relacion()
	{
		return relacion;
	}
	void Datos() {
		cout << afecto << "\n";
		cout << nombre << "\n";
		cout << creacion << "\n";
		cout << futuro << "\n";
		cout << relacion << "\n";
	}
};
class Julieta : public IA {

public:
	Julieta(string nombre, string creacion, string futuro)
	{
		this->afecto = 0;
		this->nombre = nombre;
		this->creacion = creacion;
		this->futuro = futuro;
		this->viva = true;
		this->relacion = false;
	}
	void ActNombre(string nombre)
	{
		this->nombre = nombre;
	}
	void ActCreacion(string creacion)
	{
		this->creacion = creacion;
	}
	void ActFuturo(string futuro)
	{
		this->futuro = futuro;
	}
	void Afb()
	{
		this->afecto--;
	}
	void Afs()
	{
		this->afecto++;
	}
	void AcAf(int n)
	{
		this->afecto=n;
	}
	void ActRel(bool n)
	{
		this->relacion = n;
	}

};