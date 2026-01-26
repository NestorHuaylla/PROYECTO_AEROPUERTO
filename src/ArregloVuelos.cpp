#include "../include/ArregloVuelos.h"
#include <iostream>

using namespace std;

ArregloVuelos::ArregloVuelos() {
    cantidad = 0;
    capacidad = 10;
    arreglo = new Vuelo*[capacidad];
    CargarDesdeArchivo(); 
}

ArregloVuelos::~ArregloVuelos() {
    GuardarEnArchivo();
    for (int i = 0; i < cantidad; i++) delete arreglo[i];
    delete[] arreglo;
}

void ArregloVuelos::Agregar(Vuelo* obj) {
    if (cantidad == capacidad) {
        capacidad += 10;
        Vuelo** temporal = new Vuelo*[capacidad];
        for (int i = 0; i < cantidad; i++) temporal[i] = arreglo[i];
        delete[] arreglo;
        arreglo = temporal;
    }
    arreglo[cantidad++] = obj;
}

Vuelo* ArregloVuelos::BuscarPorCodigo(int codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (arreglo[i]->GetCodigo() == codigo) return arreglo[i];
    }
    return nullptr;
}

int ArregloVuelos::BuscarPosicion(int codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (arreglo[i]->GetCodigo() == codigo) return i;
    }
    return -1;
}

Vuelo* ArregloVuelos::Obtener(int indice) {
    return (indice >= 0 && indice < cantidad) ? arreglo[indice] : nullptr;
}

int ArregloVuelos::GetCantidad() { return cantidad; }

void ArregloVuelos::Eliminar(int indice) {
    if (indice >= 0 && indice < cantidad) {
        delete arreglo[indice];
        for (int i = indice; i < cantidad - 1; i++) arreglo[i] = arreglo[i + 1];
        cantidad--;
    }
}

int ArregloVuelos::GenerarCodigoCorrelativo() {
    if (cantidad == 0) return 1001; 
    return arreglo[cantidad - 1]->GetCodigo() + 1;
}

void ArregloVuelos::GuardarEnArchivo() {
    ofstream archivo("vuelos.bin", ios::binary);
    if (!archivo) { cout << "Error guardando vuelos.bin" << endl; return; }
    
    archivo.write((char*)&cantidad, sizeof(int));
    for (int i = 0; i < cantidad; i++) {
        archivo.write((char*)arreglo[i], sizeof(Vuelo));
    }
    archivo.close();
}

void ArregloVuelos::CargarDesdeArchivo() {
    ifstream archivo("vuelos.bin", ios::binary);
    if (!archivo) return;

    int cant;
    archivo.read((char*)&cant, sizeof(int));
    for (int i = 0; i < cant; i++) {
        Vuelo objTemp;
        archivo.read((char*)&objTemp, sizeof(Vuelo));
        
        Agregar(new Vuelo(
            objTemp.GetCodigo(), objTemp.GetAerolinea(), 
            objTemp.GetOrigen(), objTemp.GetDestino(), 
            objTemp.GetFecha(), objTemp.GetPrecioBase()
        ));
    }
    archivo.close();
}