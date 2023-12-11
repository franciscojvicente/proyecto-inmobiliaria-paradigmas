/*
 * Terreno.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Terreno.h"
Terreno::Terreno():Inmueble(),seEncuentraAlambrado(false){
}
Terreno::Terreno(float s, string d, Estado e, float pb,bool sa, string serv):Inmueble(s,d,e,pb),seEncuentraAlambrado(sa),servicios(serv){

}
Terreno::Terreno(float s, string d, Estado e, float pb):Inmueble(s,d,e,pb),seEncuentraAlambrado(false){

}
string Terreno::GetTipo(){
	return "Terreno";
}

void Terreno::CambiarEstado(TipoPropiedad* ne){

}
void Terreno::Listar(){
	Inmueble::ListarAux();
	if(seEncuentraAlambrado){
		cout<<"Terreno alambrado"<<endl;
	}else{
		cout<<"Terreno no alambrado"<<endl;
	}
	cout<<"Servicios: "<<servicios<<endl;
}
Terreno::~Terreno(){

}
