#include "../include/ArregloPasajeros.h"
#include <iostream>
#include <cstring> 

using namespace std;

ArregloPasajeros::ArregloPasajeros() {
    cantidad = 0;
    capacidad = 10;
    arreglo = new Pasajero*[capacidad];
    CargarDesdeArchivo(); 
}

ArregloPasajeros::~ArregloPasajeros() {
    GuardarEnArchivo(); 
    for (int i = 0; i < cantidad; i++) delete arreglo[i];
    delete[] arreglo;
}

void ArregloPasajeros::Agregar(Pasajero* obj) {
    if (cantidad == capacidad) {
        capacidad += 10;
        Pasajero** temporal = new Pasajero*[capacidad];
        for (int i = 0; i < cantidad; i++) temporal[i] = arreglo[i];
        delete[] arreglo;
        arreglo = temporal;
    }
    arreglo[cantidad++] = obj;
}

Pasajero* ArregloPasajeros::BuscarPorDni(const char* dni) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(arreglo[i]->GetDni(), dni) == 0) {
            return arreglo[i];
        }
    }
    return nullptr;
}

int ArregloPasajeros::BuscarPosicion(const char* dni) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(arreglo[i]->GetDni(), dni) == 0) return i;
    }
    return -1;
}

Pasajero* ArregloPasajeros::Obtener(int indice) {
    return (indice >= 0 && indice < cantidad) ? arreglo[indice] : nullptr;
}

int ArregloPasajeros::GetCantidad() {
    return cantidad;
}

void ArregloPasajeros::Eliminar(int indice) {
    if (indice >= 0 && indice < cantidad) {
        delete arreglo[indice];
        for (int i = indice; i < cantidad - 1; i++) arreglo[i] = arreglo[i + 1];
        cantidad--;
    }
}

void ArregloPasajeros::GuardarEnArchivo() {
    ofstream archivo("pasajeros.bin", ios::binary);
    if (!archivo) { cout << "Error guardando pasajeros.bin" << endl; return; }
    
    archivo.write((char*)&cantidad, sizeof(int));
    for (int i = 0; i < cantidad; i++) {
        archivo.write((char*)arreglo[i], sizeof(Pasajero));
    }
    archivo.close();
}

void ArregloPasajeros::CargarDesdeArchivo() {
    ifstream archivo("pasajeros.bin", ios::binary);
    if (!archivo) return;

    int cant;
    archivo.read((char*)&cant, sizeof(int));
    for (int i = 0; i < cant; i++) {
        Pasajero objTemp;
        archivo.read((char*)&objTemp, sizeof(Pasajero));
        Agregar(new Pasajero(objTemp.GetDni(), objTemp.GetNombres(), objTemp.GetTelefono(), objTemp.GetNacionalidad()));
    }
    archivo.close();
}