#include <iostream>
#include <cstring>
#include <iomanip> 
#include "../include/Vuelo.h"

using namespace std;

Vuelo::Vuelo() {
    cod_vuelo = 0;
    strcpy(aerolinea, "");
    strcpy(origen, "");
    strcpy(destino, "");
    strcpy(fecha, "");
    precio_base = 0.0;
}

Vuelo::Vuelo(int Cod, char Aero[30], char Ori[20], char Des[20], char Fec[15], float Pre) {
    cod_vuelo = Cod;
    strcpy(aerolinea, Aero);
    strcpy(origen, Ori);
    strcpy(destino, Des);
    strcpy(fecha, Fec);
    precio_base = Pre;
}

void Vuelo::SetVuelo(int Cod, char Aero[30], char Ori[20], char Des[20], char Fec[15], float Pre) {
    cod_vuelo = Cod;
    strcpy(aerolinea, Aero);
    strcpy(origen, Ori);
    strcpy(destino, Des);
    strcpy(fecha, Fec);
    precio_base = Pre;
}

int Vuelo::GetCodigo() {
    return cod_vuelo;
}

char* Vuelo::GetAerolinea() {
    return aerolinea;
}

char* Vuelo::GetOrigen() {
    return origen;
}

char* Vuelo::GetDestino() {
    return destino;
}

char* Vuelo::GetFecha() {
    return fecha;
}

float Vuelo::GetPrecioBase() {
    return precio_base;
}

void Vuelo::Mostrar() {
    cout << "=== VUELO #" << cod_vuelo << " ===" << endl;
    cout << "Aerolinea : " << aerolinea << endl;
    cout << "Ruta      : " << origen << " -> " << destino << endl;
    cout << "Fecha     : " << fecha << endl;
    cout << "Precio Base: S/." << fixed << setprecision(2) << precio_base << endl;
    cout << "=========================" << endl;
}