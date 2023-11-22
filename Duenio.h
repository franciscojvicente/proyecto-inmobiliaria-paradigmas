#include <iostream>
using namespace std;
#ifndef DUENIO_H_
#define DUENIO_H_
class Duenio
{
protected:
	static int autonumerico;
	int codigo;
	string mail;
	string telefono;
	string direccion;	
	string nombre;
public:
	Duenio();
	Duenio(string Mail, string Telefono, string Direccion, string Nombre);
	virtual void MostrarDuenio() = 0;
	virtual float Precio(float precioBase) = 0;
	virtual ~Duenio();
};

#endif
