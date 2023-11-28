/*
 * Inmobiliaria.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef INMOBILIARIA_H_
#define INMOBILIARIA_H_
#include "Contacto.h"
class Inmobiliaria : public Contacto{
	string sitioWeb;
	float porcentajeCobra;
public:
	Inmobiliaria();
	Inmobiliaria(string m, string t, string d, string sw, float pc);
	float Precio(float precioBase);
	void Listar();
	string GetTipo();
	~Inmobiliaria();
};




#endif /* INMOBILIARIA_H_ */
