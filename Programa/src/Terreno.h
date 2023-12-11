/*
 * Terreno.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef TERRENO_H_
#define TERRENO_H_
#include "Inmueble.h"
#include "TipoPropiedad.h"
class Terreno : public Inmueble{
	bool seEncuentraAlambrado;
	string servicios;
public:
	Terreno();
	Terreno(float s, string d, Estado e, float pb,bool se, string serv);
	Terreno(float s, string d, Estado e, float pb);
	string GetTipo();
	void CambiarEstado(TipoPropiedad* nuevoEstado);
	void Listar();
	~Terreno();
};




#endif /* TERRENO_H_ */
