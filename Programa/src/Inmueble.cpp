/*
 * Inmueble.cpp
 *
 *  Created on: 24 nov 2023
 *      Author: USUARIO
 */
#include "Inmueble.h"
#include "Cliente.h"
int Inmueble::autonumerico=1;
Inmueble::Inmueble():codigo(autonumerico),superficie(0),estado(),precioBase(0),duenio(),clientesInteresados(){
	autonumerico++;
}

Inmueble::Inmueble(float s, string d, Estado e, float pb):codigo(autonumerico),superficie(s),direccion(d),estado(e),precioBase(pb),duenio(),clientesInteresados(){

}
float Inmueble::GetSuperficie(){
	return (this->superficie);
}
string Inmueble::GetDireccion(){
	return(direccion);
}
Estado Inmueble::GetEstado(){
	return (estado);
}
float Inmueble::GetPrecioBase(){
	return (precioBase);
}
float Inmueble::Precio(){
	return (duenio->Precio(this->precioBase));
}
void Inmueble::ModificarInmueble(Inmueble* i){
	superficie = i->superficie;
	direccion = i->direccion;
	estado = i->estado;
	precioBase = i->precioBase;
}
void Inmueble::AgregarDuenio(Contacto* d){
	this->duenio = d;
}
void Inmueble::ListarInformacionContacto(){
	this->duenio->Listar();
}
void Inmueble::Listar(string t, Estado e, float m){
	if(this->GetTipo()==t && this->EncuentraRango(m,10) && this->estado==e){
		this->Listar();
	}
}

bool Inmueble::EncuentraRango(float p, float r){
	return ((this->Precio()>=(p*(100-r)/100)) && (this->Precio()<= p*(100+r)/100));
}

void Inmueble::ListarPropContacto(int codContacto){
	if(this->duenio->GetCodigo()==codContacto){
		this->Listar();
	}
}
void Inmueble::AgregarInteresado(Cliente* c){
	this->clientesInteresados.push_back(c);
}

void Inmueble::EliminarInteresado(Cliente* c){
	for(int i = 0; i<clientesInteresados.size();i++){
		if(c==clientesInteresados[i]){
			this->clientesInteresados.erase(clientesInteresados.begin()+i);
		}
	}
}
int Inmueble::CantidadInteresados(){
	return (this->clientesInteresados.size());
}

void Inmueble::InformarClientes(){
	cout<<"--- CAMBIO DE ESTADO----"<<endl;
	cout<<"Se desea informar a los clientes: "<<endl;
	for(Cliente* c:clientesInteresados){
		cout<<"\t_ "<<c->GetMail()<<endl;
	}
	cout<<"La modificacion del estado del inmueble: "<<endl;
	this->Listar();
}
void Inmueble::ListarAux(){
	cout<<"\t\t- Superficie: "<<superficie<<endl;
	cout<<"\t\t- Direccion: "<<direccion<<endl;
	cout<<"\t\t- Estado: "<<estado<<endl;
	cout<<"\t\t- precio Base: "<<precioBase<<endl;
	cout<<"\t\t- Precio Final: "<<this->Precio()<<endl;
	cout<<"\t\t- Tipo: "<<this->GetTipo()<<endl;
	cout<<"\t\t- CantidadInteresados: "<<this->CantidadInteresados()<<endl;
}
int Inmueble::GetCodigo(){
	return(this->codigo);
}
vector<Cliente*> Inmueble::ListarClientesInteresados(){
	return(this->clientesInteresados);
}
Inmueble::~Inmueble(){

}
