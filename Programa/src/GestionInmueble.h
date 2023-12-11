/*
 * GestionInmueble.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef GESTIONINMUEBLE_H_
#define GESTIONINMUEBLE_H_
#include "Cliente.h"
#include "Inmueble.h"
#include "TipoPropiedad.h"
class GestionInmueble{
	vector<Inmueble*> inmuebles;
	vector<Cliente*> clientes;
public:
	GestionInmueble();
	void ListarInmuebles(string tipo, Estado e, float m);
	void ListarPropiedadesContacto(int codC);
	Inmueble* InmuebleMasInteresado();
	void CambiarEstado(Inmueble* i, TipoPropiedad* nuevoEstado);
	void AgregarInmueble(Inmueble* i, Contacto* duenio);
	void EliminarInmueble(Inmueble* i);
	void InformacionContacto(Inmueble* i);
	~GestionInmueble();
};




#endif /* GESTIONINMUEBLE_H_ */
