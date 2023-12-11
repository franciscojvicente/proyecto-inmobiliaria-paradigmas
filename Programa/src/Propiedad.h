/*
 * Propiedad.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef PROPIEDAD_H_
#define PROPIEDAD_H_
#include "Inmueble.h"
#include "TipoPropiedad.h"
class Propiedad:public Inmueble{
	int cantidadHabitaciones;
	int cantidadBanios;
	int cantidadCocheras;
	int cantidadSuits;
	TipoPropiedad* tipo;
public:
	Propiedad();
	Propiedad(float s, string d, Estado e,float pb,int ch,int cb, int cc, int cs, TipoPropiedad* tipo);
	string GetTipo();
	void CambiarEstado(TipoPropiedad* nuevoEstado);
	void Listar();
	~Propiedad();
};




#endif /* PROPIEDAD_H_ */
