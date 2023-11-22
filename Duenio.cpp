#include "Duenio.h"

int Duenio::autonumerico = 0;
Duenio::Duenio() :codigo(autonumerico)
{
	autonumerico++;
}
Duenio::Duenio(string Mail, string Telefono, string Direccion, string Nombre) :codigo(autonumerico), mail(Mail), telefono(Telefono), direccion(Direccion), nombre(Nombre)
{
	autonumerico++;
}

Duenio::~Duenio()
{

}
