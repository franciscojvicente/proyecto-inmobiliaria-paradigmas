#include "TipoPropiedad.h"
#include <iostream>
#include <string>
using namespace std;

struct Fecha
{
   int dia;
   int mes;
   int anio;
};

class EnCostruccion : public TipoPropiedad {
    float PorcentajeAvance;
    struct Fecha FechaEstimadaHabitable;
    public:
    string ObtenerTipo(){
    return("EnConstruccion");
        
    }
    void ListarInformacion(){
        cout<<"La Propiedad está en Construccion"<<endl;
        cout<<"La Propiedad está "<<PorcentajeAvance<<"% completada"<<endl;
        cout<<"La Propiedad estará lista aproximadamente en"<<FechaEstimadaHabitable.dia<<"/"<<FechaEstimadaHabitable.mes<<"/"<<FechaEstimadaHabitable.anio<<endl;
    }

};