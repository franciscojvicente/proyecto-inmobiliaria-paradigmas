#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente() {}

Cliente::Cliente(int Dni, string Nombre, string Mail, string Telefono): dni(Dni), nombre(Nombre), mail(Mail), telefono(Telefono) {

}

void Cliente::EliminarPropiedadInteres(Propiedad* propiedad) {
    // Iterar sobre el vector para encontrar la propiedad y eliminarla
    for (auto i = PropiedadesInteres.begin(); i != PropiedadesInteres.end(); ++i) {
        if (PropiedadesInteres[i] == *propiedad) {
            delete *i;
            // Se encontró la propiedad, eliminarla del vector
            PropiedadesInteres.erase(i);
            break;  // Salir del bucle después de eliminar la propiedad
        }
    }
}

void Cliente::AgregarPropiedadInteres(Propiedad* propiedad) {
    PropiedadesInteres.push_back(propiedad);
}

string Cliente::GetMail() {
    return (this->mail);
}

Cliente::~Cliente() {

}