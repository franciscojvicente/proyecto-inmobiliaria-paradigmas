#include "TipoPropiedad.h"

struct Fecha
{
   int dia;
   int mes;
   int anio;
};

class EnCostruccion : public TipoPropiedad {
    float PorcentajeAvance;
    struct Fecha FechaEstimadaHabitable;
};