/*
 * Contacto.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_
#include <iostream>
using namespace std;

class Contacto{
protected:
	static int autonumerico;
	int codigo;
	string mail;
	string telefono;
	string direccion;
public:
	Contacto();
	Contacto(string mail, string telefono, string direccion);
	virtual float Precio(float precioBase)=0;
	virtual void Listar()=0;
	void ListarAux();
	virtual string GetTipo()=0;
	int GetCodigo();
	virtual ~Contacto();
};



#endif /* CONTACTO_H_ */
