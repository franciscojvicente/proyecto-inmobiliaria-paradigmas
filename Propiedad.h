#include "Inmueble.h"
#include "TipoPropiedad.h"

class Propiedad : public Inmueble{ 
    int Habitaciones;
    int Banios;
    int cocheras;
    int Suits;
    TipoPropiedad *Tipo;
};