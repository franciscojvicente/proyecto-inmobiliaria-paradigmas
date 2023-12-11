/*
 * Inmueble.h
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */

#ifndef INMUEBLE_H_
#define INMUEBLE_H_
#include "Contacto.h"
#include "TipoPropiedad.h"
#include <vector>
enum Estado{
	enVenta=1,
	enAlquiler=2,
	noDisponible=3
};

class Cliente;
class Inmueble{
	bool EncuentraRango(float p, float r);
protected:
	static int autonumerico;
	int codigo;
	float superficie;
	string direccion;
	Estado estado;
	float precioBase;
	Contacto* duenio;
	vector<Cliente*> clientesInteresados;
public:
	Inmueble();
	Inmueble(float s, string d, Estado e, float pb);
	virtual string GetTipo()=0;
	float GetSuperficie();
	string GetDireccion();
	Estado GetEstado();
	float GetPrecioBase();
	int GetCodigo();
	float Precio();
	virtual void Listar()=0;
	void ModificarInmueble(Inmueble* i);
	virtual void CambiarEstado(TipoPropiedad* nuevoEstado)=0;
	void AgregarDuenio(Contacto* contacto);
	void ListarInformacionContacto();
	void Listar(string t, Estado e, float m);
	void ListarPropContacto(int c);
	void AgregarInteresado(Cliente* c);
	void EliminarInteresado(Cliente* c);
	int CantidadInteresados();
	void InformarClientes();
	void ListarAux();
	vector<Cliente*> ListarClientesInteresados();
	virtual ~Inmueble();
};




#endif /* INMUEBLE_H_ */
