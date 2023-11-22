#ifndef INMOBILIARIA_H_
#define INMOBILIARIA_H_
#include "Duenio.h"
using namespace std;

class Inmobiliaria :public Duenio
{
private:
	string sitioWeb;
	float porcentajeCobra;
public:
	Inmobiliaria();
	Inmobiliaria(string Mail, string Telefono, string Direccion, string Nombre, string sitio, float porcentaje);
	virtual void MostrarDuenio();
	float Precio(float PrecioBase);
	~Inmobiliaria();
};





#endif /* INMOBILIARIA_H_ */
