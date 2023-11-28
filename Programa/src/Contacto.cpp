/*
 * Contacto.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Contacto.h"
int Contacto::autonumerico=1;
Contacto::Contacto():codigo(autonumerico){
	autonumerico++;
}
Contacto::Contacto(string m, string t, string d):codigo(autonumerico), mail(m),telefono(t),direccion(d){
	autonumerico++;
}

void Contacto::ListarAux(){
	cout<<"\t\t\tDATOS Contacto: "<<endl;
	cout<<"\t\t\t\t -Mail: "<<this->mail<<endl;
	cout<<"\t\t\t\t -Telefono: "<<this->telefono<<endl;
	cout<<"\t\t\t\t -Direccion: "<<this->direccion<<endl;
	cout<<"\t\t\t\t -Tipo: "<<GetTipo()<<endl;
}
int Contacto::GetCodigo(){
	return(this->codigo);
}
Contacto::~Contacto(){

}
