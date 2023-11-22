#include <iostream>
#include <string>
using namespace std;
class TipoPropiedad{
    protected:
    virtual string ObtenerTipo()=0;
    virtual void ListarInformacion()=0;
};