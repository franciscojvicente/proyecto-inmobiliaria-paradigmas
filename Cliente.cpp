#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente() {}

Cliente::Cliente(int Dni, string Nombre, string Mail, string Telefono): dni(Dni), nombre(Nombre), mail(Mail), telefono(Telefono) {

}

void Cliente::EliminarInmuebleInteres(Inmueble* inmueble) {
    auto it = std::find(inmueblesInteres.begin(), inmueblesInteres.end(), inmueble);
    if (it != inmueblesInteres.end()) {
        delete *it;
        inmueblesInteres.erase(it);
    }
}

void Cliente::AgregarInmuebleInteres(Inmueble* inmueble) {
    auto it = std::find(inmueblesInteres.begin(), inmueblesInteres.end(), inmueble);
    if (it != inmueblesInteres.end()) {
        std::cout << "El inmueble ya está en la lista." << std::endl;
    } else {
        inmueblesInteres.push_back(inmueble);
        std::cout << "El inmueble ha sido agregado a la lista." << std::endl;
    }
}

string Cliente::GetMail() {
    return (this->mail);
}

Cliente::~Cliente() {

}