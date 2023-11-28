/*
 * Inmobiliaria.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Inmobiliaria.h"
Inmobiliaria::Inmobiliaria():Contacto(),porcentajeCobra(0){

}

Inmobiliaria::Inmobiliaria(string m, string t, string d, string sw, float pc):Contacto(m,t,d),sitioWeb(sw), porcentajeCobra(pc){

}

float Inmobiliaria::Precio(float pb){
	float precioFinal  = pb+(pb*porcentajeCobra/100);
	return (precioFinal);
}

string Inmobiliaria::GetTipo(){
	return "Inmobiliaria";
}

void Inmobiliaria::Listar(){
	this->ListarAux();
	cout<<"\t\t\t\t- Sitio Web: "<<sitioWeb<<endl;
	cout<<"\t\t\t\t- Porcentaje que Cobra: "<<porcentajeCobra<<endl;
}

Inmobiliaria::~Inmobiliaria(){

}

