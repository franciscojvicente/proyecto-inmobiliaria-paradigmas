/*
 * Cliente.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include"Inmueble.h"
using namespace std;
class Cliente{
	static int autonumerico;
	int codigo;
	string nombre;
	string mail;
	string telefono;
	vector<Inmueble*> inmueblesInteresados;
public:
	Cliente();
	Cliente(string n,string m,string t);
	int GetCodigo();
	string GetMail();
	void Interesar(Inmueble* inmueble);
	void Desinteresar(Inmueble* inmueble);
	void EliminarI(Inmueble* inmueble);
	void Listar();
	~Cliente();
};




#endif /* CLIENTE_H_ */
