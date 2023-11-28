/*
 * Propiedad.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Propiedad.h"
Propiedad::Propiedad():Inmueble(),cantidadHabitaciones(0),cantidadBanios(0),cantidadCocheras(0),cantidadSuits(0),tipo(){

}

Propiedad::Propiedad(float s, string d, Estado e, float pb, int ch, int cb, int cc, int cs, TipoPropiedad* t):Inmueble(s,d,e,pb),cantidadHabitaciones(ch),cantidadBanios(cb),cantidadCocheras(cc),cantidadSuits(cs),tipo(t){

}
string Propiedad::GetTipo(){
	return "Propiedad";
}

void Propiedad::CambiarEstado(TipoPropiedad*nuevoEstado){
	delete tipo;
	tipo = nuevoEstado;
	this->InformarClientes();
}

void Propiedad::Listar(){
	Inmueble::ListarAux();
	cout<<"Cantidad de Habitaciones: "<<cantidadHabitaciones<<endl;
	cout<<"Cantidad de Banios: "<<cantidadBanios<<endl;
	cout<<"Cantidad de Cocheras: "<<cantidadCocheras<<endl;
	cout<<"Cantidad de Suits: "<<cantidadSuits<<endl;
	tipo->Listar();
}
Propiedad::~Propiedad(){

}
