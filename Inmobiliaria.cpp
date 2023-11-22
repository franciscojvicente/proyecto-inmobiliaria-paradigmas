#include "Inmobiliaria.h"
Inmobiliaria::Inmobiliaria() :Duenio(), porcentajeCobra(0)
{

}

Inmobiliaria::Inmobiliaria(string Mail, string Telefono, string Direccion, string Nombre, string sitio, float porcentaje) :Duenio(Mail, Telefono, Direccion, Nombre), sitioWeb(sitio), porcentajeCobra(porcentaje)
{

}

float Inmobiliaria::Precio(float PrecioBase)
{
	return PrecioBase + PrecioBase * porcentajeCobra;
}

void Inmobiliaria::MostrarDuenio()
{
	cout << "			Inmobiliaria " << this->nombre << endl;
	cout << "Mail: " << this->mail << endl;
	cout << "Telefono: " << this->telefono << endl;
	cout << "Direccion: " << this->direccion << endl;
	cout << "Sitio: " << this->sitioWeb << endl;
	cout << "Porcentaje de Aumento: " << this->porcentajeCobra << endl;
}
Inmobiliaria::~Inmobiliaria()
{

}





