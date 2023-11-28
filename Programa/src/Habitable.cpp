/*
 * Habitable.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Habitable.h"
Habitable::Habitable():TipoPropiedad(){

}
string Habitable::GetTipo(){
	return "Habitable";
}
void Habitable::Listar(){
	cout<<"Tipo de Propiedad: "<<this->GetTipo()<<endl;
}

Habitable::~Habitable(){

}


