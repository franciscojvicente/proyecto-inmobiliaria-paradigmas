/*
 * GestionInmueble.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "GestionInmueble.h"
GestionInmueble::GestionInmueble():inmuebles(),clientes(){

}

void GestionInmueble::ListarInmuebles(string t, Estado e, float m){
	for(Inmueble* i : inmuebles){
		i->Listar(t,e,m);
	}
}
void GestionInmueble::ListarPropiedadesContacto(int codC){
	for(Inmueble* i:inmuebles){
		i->ListarPropContacto(codC);
	}
}
Inmueble* GestionInmueble::InmuebleMasInteresado(){
	int max = 0;
	Inmueble* inmuebleMasI=nullptr;
	for(Inmueble* i: inmuebles){
		if(i->CantidadInteresados()>=max){
			max=i->CantidadInteresados();
			inmuebleMasI = i;
		}
	}
	return inmuebleMasI;
}

void GestionInmueble::CambiarEstado(Inmueble* i, TipoPropiedad* nuevoE){
	i->CambiarEstado(nuevoE);
}
void GestionInmueble::AgregarInmueble(Inmueble* i, Contacto* d){
	i->AgregarDuenio(d);
	inmuebles.push_back(i);
}
void GestionInmueble::EliminarInmueble(Inmueble* inm){
	for(Cliente* c:this->clientes){
		c->EliminarI(inm);
	}
	for(int i = 0;i<inmuebles.size();i++){
		if(inmuebles[i]==inm){
			inmuebles.erase(inmuebles.begin()+i);
		}
	}
}
void GestionInmueble::InformacionContacto(Inmueble* i){
	i->ListarInformacionContacto();
}
GestionInmueble::~GestionInmueble(){

}
