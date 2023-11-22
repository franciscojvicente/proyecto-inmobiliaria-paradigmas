#ifndef CLIENTE_H_
#define CLIENTE_H_
#define MAX 100
#include "Propiedad.h"
#include <iostream>
#include <vector>
using namespace std;

class Propiedad;
class Cliente
{
private:
    int dni;
    string nombre;
    string mail;
    string telefono;
    vector<Propiedad*> PropiedadesInteres;

public:
    Cliente();
    Cliente(int Dni, string Nombre, string Mail, string Telefono);
    string GetMail();
    void AgregarPropiedadInteres(Propiedad* propiedad);
    void EliminarPropiedadInteres(Propiedad* propiedad);
    ~Cliente();
};


#endif