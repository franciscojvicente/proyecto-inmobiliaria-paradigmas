/*
 * Habitable.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef HABITABLE_H_
#define HABITABLE_H_
#include "TipoPropiedad.h"
class Habitable: public TipoPropiedad{
public:
	Habitable();
	string GetTipo();
	void Listar();
	~Habitable();
};




#endif /* HABITABLE_H_ */
