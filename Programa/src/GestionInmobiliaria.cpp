//============================================================================
// Name        : GestionInmobiliaria.cpp
// Author      : GonzaloRobinson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include "GestionInmueble.h"
#include "Propiedad.h"
#include "Terreno.h"
#include"EnConstruccion.h"
#include "Habitable.h"
#include "Inmobiliaria.h"
#include "Particular.h"


// Definir aquí las clases Inmueble y Contacto y sus funcionalidades

void InmueblesDisponibles(vector<Inmueble*> inmuebles){
	int contador = 0;
	for(Inmueble* i: inmuebles){
		cout<<"-> Opcion  "<<contador<<endl;
		i->Listar();
		cout<<endl;
		cout<<endl;
		contador++;
	}
}
Inmueble* ElegirInmueble(vector<Inmueble*> inmuebles){
	int opcion;
	InmueblesDisponibles(inmuebles);
	cout<<"Inmueble elegido:  ";
	cin>>opcion;
	cout<<endl;
	if(opcion>=0 && opcion<inmuebles.size()){
		return (inmuebles[opcion]);
	}else{
		return nullptr;
	}
}
void ClientesDisponibles(vector<Cliente*> clientes){
	int contador = 0;
	for(Cliente* c: clientes){
		cout<<"-> Opcion  "<<contador<<endl;
		c->Listar();
		cout<<endl;
		cout<<endl;
		contador++;
	}
}
Cliente* ElegirCliente(vector<Cliente*> clientes){
	int opcion;
	ClientesDisponibles(clientes);
	cout<<"Cliente elegido:  ";
	cin>>opcion;
	cout<<endl;
	if(opcion>=0 && opcion<clientes.size()){
		return (clientes[opcion]);
	}else{
		return nullptr;
	}
}
void MostrarContactos(vector<Contacto*> contactos){
	for(int i = 0; i<contactos.size();i++){
		cout<<"-> Opcion "<<i<<endl;
		contactos[i]->Listar();
		cout<<endl<<endl;
	}
}
Contacto* SeleccionarContacto(vector<Contacto*> contactos){
	int opcion;
	MostrarContactos(contactos);
	cin>>opcion;
	if(opcion>=0 && opcion<contactos.size()){
		return (contactos[opcion]);
	}else{
		return nullptr;
	}
}
Habitable* CrearTipoHabitable(){
	Habitable* creado = new Habitable();
	return creado;
}
EnConstruccion* CrearTipoEnConstruccion(){
	cout<<"Porcentaje de avance: ";
	double porcD;
	cin>>porcD;
	float porcF = static_cast<float> (porcD);
	cout<<"dia: ";
	int dia;
	cin>>dia;
	cout<<" - mes: ";
	int mes;
	cin>>mes;
	cout<<" - anio: ";
	int anio;
	cin>>anio;
	Fecha* f = new Fecha(dia,mes,anio);
	EnConstruccion* tipo = new EnConstruccion(porcF, f);
	return tipo;
	cin>>anio;
}
void listarInmueblesPorTipoEstadoMonto(GestionInmueble& gestion) {
	int tipoI;
	string tipo;
	int e;
	Estado estadoEnum;
	float montoF;
	cout<<"Ingrese el tipo de inmueble que desea buscar (1=Propiedad o otro=Terreno): ";
	cin>>tipoI;
	if(tipoI==1){
		tipo="Propiedad";
	}else{
		tipo="Terreno";
	}
	cout<<endl<<"Ingrese el Estado que desea buscar (en Venta=1, en Alquiler=2, no Disponible=3):  ";
	cin>>e;
	cin.ignore();
	if(e>=1 && e<=3){
		estadoEnum = static_cast<Estado>(e);
	}else{
		estadoEnum = static_cast<Estado>(1);
	}
	cout<<endl<<"Ingrese un monto para buscar (los resultados devolveran los inmuebles con un precio del monto ingresado +- un 10 %):  ";
	cin>>montoF;
	cin.ignore();
	gestion.ListarInmuebles(tipo,estadoEnum,montoF);
}
void listarTodasPropiedadesContacto(GestionInmueble& gestion, vector<Contacto*> c) {
	Contacto* elegido = SeleccionarContacto(c);
	if(elegido!=nullptr){
		gestion.ListarPropiedadesContacto(elegido->GetCodigo());
	}else{
		cout<<"Contacto inexistente";
	}
}

void listarInmuebleMasInteresado(GestionInmueble& gestion) {
    // Implementar la lógica para listar el inmueble más interesado
	Inmueble* i = gestion.InmuebleMasInteresado();
	if(i!=nullptr){
		i->Listar();
	}else{
		cout<<"No hay ningun inmueble con interesados"<<endl;
	}
}
TipoPropiedad* CargarTipo(){
	cout<<"Ingrese que tipo desea que tenga su propiedad (1=Habitable, otra=En construccion): "<<endl;
		int opcion;
		cin>>opcion;
		TipoPropiedad* tipo;
		if(opcion==1){
			tipo = CrearTipoHabitable();
		}else{
			tipo = CrearTipoEnConstruccion();
		}
		return tipo;
}
void cambiarEstadoInmueble(GestionInmueble& gestion, vector<Inmueble*> inmuebles) {
	Inmueble* elegido = ElegirInmueble(inmuebles);
	if(elegido!=nullptr){
		TipoPropiedad* tipo = CargarTipo();
		gestion.CambiarEstado(elegido,tipo);
	}else{
		cout<<"No hay existe el inmueble que se queria elegir"<<endl;
	}
}
Inmueble* CrearInmueble(vector<Contacto*> contactos){
	Inmueble* creado;

	    // Implementar la lógica para agregar un nuevo inmueble
			float superficie;
		    string direccion;
		    Estado estado;
		    float precioBase;

		    // Ingresar la superficie
		    cout << "Ingrese la superficie: ";
		    cin >> superficie;

		    // Limpiar el buffer después de ingresar un número para leer la cadena de caracteres (string) correctamente
		    cin.ignore();

		    // Ingresar la dirección
		    cout << "Ingrese la direccion: ";
		    getline(cin, direccion);


		    int opcionEstado;
		    cout << "Ingrese el estado (1: EN VENTA, 2: EN ALQUILER, 3: NO DISPONIBLE): ";
		    cin >> opcionEstado;
		    estado = static_cast<Estado>(opcionEstado);

		    cout << "Ingrese el precio base: ";
		    cin >> precioBase;
		    cin.ignore();

		    int tipoI;
		    cout<<endl<<"Ingrese el tipo (1=propiedad, otro = terreno):  ";
		    cin>>tipoI;
		    if(tipoI == 1){
		    	int cantidadHabitaciones;
		    	    int cantidadBanios;
		    	    int cantidadCocheras;
		    	    int cantidadSuits;

		    	    // Ingresar la cantidad de habitaciones
		    	    cout << "Ingrese la cantidad de habitaciones: ";
		    	    cin >> cantidadHabitaciones;

		    	    // Ingresar la cantidad de baños
		    	    cout << "Ingrese la cantidad de baños: ";
		    	    cin >> cantidadBanios;

		    	    // Ingresar la cantidad de cocheras
		    	    cout << "Ingrese la cantidad de cocheras: ";
		    	    cin >> cantidadCocheras;

		    	    // Ingresar la cantidad de suites
		    	    cout << "Ingrese la cantidad de suites: ";
		    	    cin >> cantidadSuits;

		    	    TipoPropiedad* tipo = CargarTipo();
		    	    creado = new Propiedad(superficie, direccion,estado, precioBase,cantidadHabitaciones,cantidadBanios,cantidadCocheras, cantidadSuits,tipo);


		    }else{
		    	bool seEncuentraAlambrado;
		    	string servicios;

		    	    // Ingresar si se encuentra alambrado (true o false)
		    	    cout << "¿Se encuentra alambrado? (1 para verdadero, 0 para falso): ";
		    	    cin >> seEncuentraAlambrado;

		    	    // Limpiar el buffer de entrada para leer la cadena
		    	    cin.ignore();
		    	    // Ingresar los servicios
		    	    cout << "Ingrese los servicios: ";
		    	    getline(cin, servicios);
		    	    creado = new Terreno(superficie, direccion, estado, precioBase, seEncuentraAlambrado,servicios);
		    }
		    return (creado);
}
void agregarInmueble(GestionInmueble& gestion, vector<Inmueble*>& inmuebles,vector<Contacto*> contactos) {

		Contacto* duenio = SeleccionarContacto(contactos);
		Inmueble* creado = CrearInmueble(contactos);
	    if(creado!=nullptr && duenio!=nullptr){
			inmuebles.push_back(creado);
			gestion.AgregarInmueble(creado,duenio);
	    }else{
	    	cout<<"El contacto elegido o el inmueble no existe en el sistema"<<endl;
	    }
}

void eliminarInmueble(GestionInmueble& gestion, vector<Inmueble*>&inmuebles) {
    Inmueble* in=ElegirInmueble(inmuebles);
    if(in != nullptr){
		gestion.EliminarInmueble(in);
		for(int i = 0; i<inmuebles.size();i++){
			if(in == inmuebles[i]){
				inmuebles.erase(inmuebles.begin()+i);
				delete in;
			}
		}
    }else{
    	cout<<"El inmueble elegido no existe"<<endl;
    }
}

void devolverInformacionContacto(GestionInmueble& gestion, vector<Inmueble*> inmuebles) {
    Inmueble* in = ElegirInmueble(inmuebles);
    if(in!=nullptr){
    	gestion.InformacionContacto(in);
    }else{
    	cout<<"El inmueble elegido no existe"<<endl;
    }
}
void CargarContactos(vector<Contacto*>& contactos){
	Contacto* c1 = new Inmobiliaria("gonchyrobinson@gmail.com","3815799416","La Rioja 3500", "proyecto.com", 15);
	Contacto* c2 = new Inmobiliaria("rickyrobinson@gmail.com","3815799440","La Rioja 3500", "proyecto2.com", 5);
	Contacto* c3 = new Particular("csss@gmail.com","381544444","Argentina 3500", "Lunes, miercoles y viernes a la tarde");
	Contacto* c4 = new Particular("aaasss@gmail.com","3777744444","Brasil", "martes, miercoles y viernes a la tarde");
	contactos.push_back(c1);
	contactos.push_back(c2);
	contactos.push_back(c3);
	contactos.push_back(c4);
}
void CargarClientes(vector<Cliente*>& clientes){
	Cliente* c1 = new Cliente("Messi", "lionelmessi@hotmail.com","3989898989");
	Cliente* c2 = new Cliente("Ronaldo", "cronaldo@hotmail.com","37779898989");
	Cliente* c3 = new Cliente("Neymar", "neymar@hotmail.com","31555555");
	clientes.push_back(c1);
	clientes.push_back(c2);
	clientes.push_back(c3);
}
Inmueble* crearModificado(){
	float superficie;
	string direccion;
	Estado estado;
	float precioBase;

	// Ingresar la superficie
	cout << "Ingrese la superficie: ";
	cin >> superficie;

	// Limpiar el buffer después de ingresar un número para leer la cadena de caracteres (string) correctamente
	cin.ignore();

	// Ingresar la dirección
	cout << "Ingrese la direccion: ";
	getline(cin, direccion);


	int opcionEstado;
	cout << "Ingrese el estado (1: EN VENTA, 2: EN ALQUILER, 3: NO DISPONIBLE): ";
	cin >> opcionEstado;
	estado = static_cast<Estado>(opcionEstado);

	cout << "Ingrese el precio base: ";
	cin >> precioBase;
	cin.ignore();
	Inmueble* creado = new Terreno(superficie, direccion, estado, precioBase);
	return creado;
}
void modificarInmueble(GestionInmueble& gestion, vector<Inmueble*>& inmuebles){
	Inmueble* elegido = ElegirInmueble(inmuebles);
	Inmueble* modificado =crearModificado();
	if(elegido!=nullptr){
		elegido->ModificarInmueble(modificado);
	}else{
		cout<<"El inmueble que intenta elegir no existe"<<endl;
	}
	delete modificado;
}


void cambiarDuenioPropiedad(GestionInmueble& gestion, vector<Inmueble*>& inmuebles, vector<Contacto*>& contactos){
	Inmueble* iElegido = ElegirInmueble(inmuebles);
	Contacto* cElegido = SeleccionarContacto(contactos);
	if(iElegido!=nullptr && cElegido!=nullptr){
		iElegido->AgregarDuenio(cElegido);
	}else{
		cout<<"El inmueble o contacto que desea elegir no existe"<<endl;
	}
}

void agregarInteresClienteInmueble(GestionInmueble& gestion, vector<Cliente*>& clientes, vector<Inmueble*>& inmuebles){
	Cliente* cElegido = ElegirCliente(clientes);
	Inmueble* iElegido = ElegirInmueble(inmuebles);
	if(cElegido!=nullptr && iElegido !=nullptr){
		cElegido->Interesar(iElegido);
	}else{
		cout<<"El inmueble o cliente que desea elegir no existe"<<endl;
	}
}

void eliminarInteresClienteInmueble(GestionInmueble& gestion, vector<Inmueble*>& inmuebles){
	Inmueble* iElegido = ElegirInmueble(inmuebles);
	if(iElegido!=nullptr){
		vector<Cliente*> clientes =iElegido->ListarClientesInteresados();
		Cliente* cElegido = ElegirCliente(clientes);
		if(cElegido!=nullptr){
			cElegido->Desinteresar(iElegido);
		}else{
			cout<<"El cliente que intenta elegir no existe"<<endl;
		}
	}else{
		cout<<"El inmueble que intenta elegir no existe"<<endl;
	}

}
void CargarInmuebles(GestionInmueble& sistema,vector<Inmueble*>& inmuebles, vector<Contacto*> contactos){
	Estado enVenta = static_cast<Estado>(1);
	Estado enAlquiler = static_cast<Estado>(2);
	Estado noDisponible = static_cast<Estado>(3);
	TipoPropiedad* t1 = new Habitable();
	TipoPropiedad* t2 = new Habitable();
	Fecha* f1 = new Fecha(14,10,2024);
	Fecha* f2 = new Fecha(1,12,2023);
	TipoPropiedad* t3 = new EnConstruccion(75,f1);
	TipoPropiedad* t4 = new EnConstruccion(90,f2);
	Inmueble* i1 = new Propiedad(100, "Av.Aconquija 1500",enVenta, 100000,2,1,1, 1,t1);
	Inmueble* i2 = new Propiedad(50, "Av. Peron 1500",enVenta, 109000,2,2,1,0,t2);
	Inmueble* i3 = new Propiedad(150, "Av. Mate de Luna 1500",enAlquiler, 10000,5,2,1,0,t3);
	Inmueble* i4 = new Propiedad(2000, "Camino del Peru 100",noDisponible, 100000,3,2,1,0,t4);
	Inmueble* i5 = new Terreno(600, "Av. Solano Vera 100",enVenta,50000,true,"posibilidad de tener luz y gas");
	Inmueble* i6 = new Terreno(1000, "Av. Independencia 1000",enAlquiler,25000,false,"posibilidad de tener luz, todavia no se instalo gas");
	inmuebles.push_back(i1);
	inmuebles.push_back(i2);
	inmuebles.push_back(i3);
	inmuebles.push_back(i4);
	inmuebles.push_back(i5);
	inmuebles.push_back(i6);
	sistema.AgregarInmueble(i1,contactos[0]);
	sistema.AgregarInmueble(i2,contactos[0]);
	sistema.AgregarInmueble(i3,contactos[1]);
	sistema.AgregarInmueble(i4,contactos[0]);
	sistema.AgregarInmueble(i5,contactos[2]);
	sistema.AgregarInmueble(i6,contactos[3]);
}
void LiberarMemoria(vector<Cliente*> clientes, vector<Inmueble*> inmuebles,vector<Contacto*> contactos){
	for(Cliente* c:clientes){
		delete c;
	}
	for(Inmueble* i:inmuebles){
		delete i;
	}
	for(Contacto* c: contactos){
		delete c;
	}
}



int main() {
    int opcion;
    vector<Contacto*> contactos;
    CargarContactos(contactos);
    vector<Cliente*> clientes;
	CargarClientes(clientes);
    vector<Inmueble*> inmuebles;
	GestionInmueble sistema;
    CargarInmuebles(sistema,inmuebles,contactos);


	do {
		cout<<endl<<endl;
		std::cout << "MENU" << std::endl;
		std::cout << "1- Listar Inmuebles por tipo, estado y monto" << std::endl;
		std::cout << "2- Listar todas las propiedades de un contacto" << std::endl;
		std::cout << "3- Listar el inmueble mas interesado" << std::endl;
		std::cout << "4- Cambiar de estado un inmueble" << std::endl;
		std::cout << "5- Agregar inmueble" << std::endl;
		std::cout << "6- Eliminar Inmueble" << std::endl;
		std::cout << "7- Devolver la informacion de un contacto" << std::endl;
		std::cout << "8- Modificar un Inmueble" << std::endl;
		std::cout << "9- Cambiar de dueño de la propiedad" << std::endl;
		std::cout << "10- Agregar Interes de un cliente por un inmueble" << std::endl;
		std::cout << "11- Eliminar Interes de un cliente por un inmueble" << std::endl;
		std::cout << "0- Salir" << std::endl;

		std::cout << "Ingrese una opcion: ";
		std::cin >> opcion;
		cout<<endl;
		switch (opcion) {
			case 1:
				listarInmueblesPorTipoEstadoMonto(sistema);
				break;
			case 2:
				listarTodasPropiedadesContacto(sistema, contactos);
				break;
			case 3:
				listarInmuebleMasInteresado(sistema);
				break;
			case 4:
				cambiarEstadoInmueble(sistema, inmuebles);
				break;
			case 5:
				agregarInmueble(sistema, inmuebles, contactos);
				break;
			case 6:
				eliminarInmueble(sistema, inmuebles);
				break;
			case 7:
				devolverInformacionContacto(sistema, inmuebles);
				break;
			case 8:
				modificarInmueble(sistema, inmuebles);
				break;
			case 9:
				cambiarDuenioPropiedad(sistema, inmuebles, contactos);
				break;
			case 10:
				agregarInteresClienteInmueble(sistema, clientes, inmuebles);
				break;
			case 11:
				eliminarInteresClienteInmueble(sistema, inmuebles);
				break;
			case 0:
				std::cout << "Saliendo del programa..." << std::endl;
				break;
			default:
				std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
		}
	} while (opcion != 0);
	LiberarMemoria(clientes,inmuebles,contactos);



    return 0;
}
