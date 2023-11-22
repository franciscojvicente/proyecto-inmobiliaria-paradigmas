#include "Duenio.h"
using namespace std;
#ifndef PARTICULAR_H_
#define PARTICULAR_H_
class Particular :public Duenio
{
private:
	string Horario;
public:
	Particular();
	Particular(string Mail, string Telefono, string Direccion, string Nombre);
	void MostrarDuenio();
	float Precio(float PrecioBase);
	~Particular();
};

#endif
