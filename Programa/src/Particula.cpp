/*
 * Particula.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Particular.h"
Particular::Particular():Contacto(){

}
Particular::Particular(string m, string t, string d, string h):Contacto(m,t,d),horarios(h){

}
float Particular::Precio(float pb){
	return pb;
}

void Particular::Listar(){
	this->ListarAux();
	cout<<"\t\t\t\tHorarios: "<<horarios<<endl;
}
string Particular::GetTipo(){
	return "Particular";
}

Particular::~Particular(){

}

