#include <iostream>
#include <cstring>
#include "../include/Pasajero.h"

using namespace std;

Pasajero::Pasajero() {
    strcpy(dni, "");
    strcpy(nombres, "");
    strcpy(telefono, "");
    strcpy(nacionalidad, "");
}

Pasajero::Pasajero(char Dni[10], char Nom[50], char Tel[15], char Nac[20]) {
    strcpy(dni, Dni);
    strcpy(nombres, Nom);
    strcpy(telefono, Tel);
    strcpy(nacionalidad, Nac);
}

void Pasajero::SetPasajero(char Dni[10], char Nom[50], char Tel[15], char Nac[20]) {
    strcpy(dni, Dni);
    strcpy(nombres, Nom);
    strcpy(telefono, Tel);
    strcpy(nacionalidad, Nac);
}

char* Pasajero::GetDni() {
    return dni;
}

char* Pasajero::GetNombres() {
    return nombres;
}

char* Pasajero::GetTelefono() {
    return telefono;
}

char* Pasajero::GetNacionalidad() {
    return nacionalidad;
}


void Pasajero::Mostrar() {
    cout << "--- DATOS DEL PASAJERO ---" << endl;
    cout << "DNI         : " << dni << endl;
    cout << "Nombres     : " << nombres << endl;
    cout << "Telefono    : " << telefono << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "--------------------------" << endl;
}