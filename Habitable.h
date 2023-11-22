#include "TipoPropiedad.h"


class Habitable : public TipoPropiedad {
    public:
    string ObtenerTipo(){
    return("Habitable");
        
    }
    void ListarInformacion(){
        cout<<"La Propiedad es Habitable"<<endl;
    }

};