#include "Particular.h"
Particular::Particular() :Duenio()
{

}

Particular::Particular(string Mail, string Telefono, string Direccion, string Nombre) :Duenio(Mail, Telefono, Direccion, Nombre)
{

}

float Particular::Precio(float PrecioBase)
{
	return PrecioBase;
}
void Particular::MostrarDuenio()
{
	cout << "			 " << this->nombre << endl;
	cout << "Mail: " << this->mail << endl;
	cout << "Telefono: " << this->telefono << endl;
	cout << "Direccion: " << this->direccion << endl;
}
Particular::~Particular()
{

}


