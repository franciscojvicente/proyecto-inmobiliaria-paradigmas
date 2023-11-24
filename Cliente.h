#ifndef CLIENTE_H_
#define CLIENTE_H_
#define MAX 100
#include "Propiedad.h"
#include <iostream>
#include <vector>
using namespace std;

class Cliente
{
private:
    int dni;
    string nombre;
    string mail;
    string telefono;
    vector<Inmueble*> inmueblesInteres;

public:
    Cliente();
    Cliente(int Dni, string Nombre, string Mail, string Telefono);
    string GetMail();
    void AgregarInmuebleInteres(Inmueble* Inmueble);
    void EliminarInmuebleInteres(Inmueble* Inmueble);
    ~Cliente();
};


#endif