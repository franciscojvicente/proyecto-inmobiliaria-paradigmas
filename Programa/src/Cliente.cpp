/*
 * Cliente.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Cliente.h"
int Cliente::autonumerico = 0;
Cliente::Cliente():codigo(autonumerico), inmueblesInteresados(){
	autonumerico++;
}

Cliente::Cliente(string n, string m, string t):codigo(autonumerico),nombre(n),mail(m),telefono(t){
	autonumerico++;
}
int Cliente::GetCodigo(){
	return codigo;
}

string Cliente::GetMail(){
	return mail;
}

void Cliente::Interesar(Inmueble* i){
	i->AgregarInteresado(this);
	inmueblesInteresados.push_back(i);
}

void Cliente::Desinteresar(Inmueble* i){
	i->EliminarInteresado(this);
	this->EliminarI(i);
}

void Cliente::EliminarI(Inmueble* in){
	for(int i = 0; i<inmueblesInteresados.size();i++){
		if(in == inmueblesInteresados[i]){
			inmueblesInteresados.erase(inmueblesInteresados.begin()+i);
		}
	}
}
void Cliente::Listar(){
	cout<<"Nombre: "<<this->nombre<<endl;
	cout<<"Mail: "<< this->mail<<endl;
	cout<<"Telefono: "<< this->telefono<<endl;

}
Cliente::~Cliente(){

}
