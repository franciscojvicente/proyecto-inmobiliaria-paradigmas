/*
 * EnConstruccion.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "EnConstruccion.h"
EnConstruccion::EnConstruccion():TipoPropiedad(),porcentajeAvance(0),fechaEstimadaHabitable(){

}

EnConstruccion::EnConstruccion(float pa, Fecha* feh):TipoPropiedad(),porcentajeAvance(pa),fechaEstimadaHabitable(feh){

}
string EnConstruccion::GetTipo(){
	return "En Construccion";
}

void EnConstruccion::Listar(){
	cout<<"Tipo: "<<GetTipo()<<endl;
	cout<<"Porcentaje de avance de la construccion: "<<porcentajeAvance<<endl;
	cout<<"Fecha que se estima que sera habitable: "<<(*fechaEstimadaHabitable)<<endl;
}
EnConstruccion::~EnConstruccion(){

}
