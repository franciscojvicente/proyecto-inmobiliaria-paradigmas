#include <iostream>
#include "Duenio.h"
#include <vector>
#include <string>
using namespace std;


enum Estados {
    EnAlquiler,
    EnVenta,
    NoDisponible
};

class Inmueble {
    protected:
    static int Codigo;
    float Superficie;
    string Direccion; 
    Estados estado;
    float PrecioBase;
    

};

int Inmueble::Codigo = 0;