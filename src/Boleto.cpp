#include <iostream>
#include <cstring>
#include <iomanip>
#include "../include/Boleto.h"

using namespace std;
Boleto::Boleto() {
    cod_boleto = 0;
    precio = 0.0;
    strcpy(codigo_vuelo, "");
    strcpy(asiento, "");
    strcpy(tipo, "");
    strcpy(dni_pasajero, "");
}

Boleto::Boleto(int cod, float pre, char Vuelo[20], char Asiento[10], char Tipo[20], char Dni[15]) {
    cod_boleto = cod;
    precio = pre;
    strcpy(codigo_vuelo, Vuelo);
    strcpy(asiento, Asiento);
    strcpy(tipo, Tipo);
    strcpy(dni_pasajero, Dni);
}

void Boleto::SetCodigo(int cod) {
    cod_boleto = cod;
}

void Boleto::SetPrecio(float pre) {
    precio = pre;
}

void Boleto::SetBoleto(float pre, char Vuelo[20], char Asiento[10], char Tipo[20], char Dni[15]) {
    precio = pre;
    strcpy(codigo_vuelo, Vuelo);
    strcpy(asiento, Asiento);
    strcpy(tipo, Tipo);
    strcpy(dni_pasajero, Dni);
}

void Boleto::SetBoleto(Boleto boleto) {
    cod_boleto = boleto.GetCodigo();
    precio = boleto.GetPrecio();
    strcpy(codigo_vuelo, boleto.GetCodigoVuelo());
    strcpy(asiento, boleto.GetAsiento());
    strcpy(tipo, boleto.GetTipo());
    strcpy(dni_pasajero, boleto.GetDniPasajero());
}

int Boleto::GetCodigo() {
    return cod_boleto;
}

float Boleto::GetPrecio() {
    return precio;
}

char* Boleto::GetCodigoVuelo() {
    return codigo_vuelo;
}

char* Boleto::GetAsiento() {
    return asiento;
}

char* Boleto::GetTipo() {
    return tipo;
}

char* Boleto::GetDniPasajero() {
    return dni_pasajero;
}

void Boleto::Mostrar() {
    cout << "=======================================" << endl;
    cout << " DETALLE DEL BOLETO #" << cod_boleto << endl;
    cout << "=======================================" << endl;
    cout << " Vuelo      : " << codigo_vuelo << endl;
    cout << " Pasajero   : " << dni_pasajero << endl;
    cout << " Asiento    : " << asiento << endl;
    cout << " Tipo       : " << tipo << endl;
    cout << " Precio     : S/. " << fixed << setprecision(2) << precio << endl;
    cout << "=======================================" << endl;
}

void Boleto::MostrarConsulta() {
    cout << left << setw(10) << cod_boleto 
         << setw(15) << codigo_vuelo 
         << setw(10) << asiento 
         << setw(15) << dni_pasajero 
         << "S/. " << fixed << setprecision(2) << precio << endl;
}

Boleto::~Boleto() {
}