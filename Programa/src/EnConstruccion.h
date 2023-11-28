/*
 * EnConstruccion.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef ENCONSTRUCCION_H_
#define ENCONSTRUCCION_H_
#include "TipoPropiedad.h"
#include "Fecha.h"
class EnConstruccion:public TipoPropiedad{
	float porcentajeAvance;
	Fecha* fechaEstimadaHabitable;
public:
	EnConstruccion();
	EnConstruccion(float pa, Fecha* feh);
	string GetTipo();
	void Listar();
	~EnConstruccion();
};




#endif /* ENCONSTRUCCION_H_ */
