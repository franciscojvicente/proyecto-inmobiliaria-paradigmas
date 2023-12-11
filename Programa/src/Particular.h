/*
 * Particular.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef PARTICULAR_H_
#define PARTICULAR_H_
#include "Contacto.h"
class Particular:public Contacto{
	string horarios;
public:
	Particular();
	Particular(string m, string t, string d, string h);
	float Precio(float precioBase);
	void Listar();
	string GetTipo();
	~Particular();
};





#endif /* PARTICULAR_H_ */
