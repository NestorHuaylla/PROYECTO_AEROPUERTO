#include "../include/ArregloBoletos.h"
#include <iostream>

using namespace std;

ArregloBoletos::ArregloBoletos() {
    this->cantidad = 0;
    this->capacidad = 10;
    this->arreglo = new Boleto*[this->capacidad];
    
    this->CargarDesdeArchivo();
}

ArregloBoletos::~ArregloBoletos() {
    this->GuardarEnArchivo();

    for (int i = 0; i < cantidad; i++) {
        delete arreglo[i];
    }
    delete[] arreglo;
}

void ArregloBoletos::Agregar(Boleto* obj) {
    if (cantidad == capacidad) {
        capacidad += 10;
        Boleto** temporal = new Boleto*[capacidad]; 

        for (int i = 0; i < cantidad; i++) {
            temporal[i] = arreglo[i];
        }

        delete[] arreglo;
        arreglo = temporal;
    }

    arreglo[cantidad] = obj;
    cantidad++;
}

Boleto* ArregloBoletos::BuscarPorCodigo(int codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (arreglo[i]->GetCodigo() == codigo) {
            return arreglo[i];
        }
    }
    return nullptr;
}

int ArregloBoletos::BuscarPosicion(int codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (arreglo[i]->GetCodigo() == codigo) {
            return i;
        }
    }
    return -1;
}

void ArregloBoletos::Eliminar(int indice) {
    if (indice >= 0 && indice < cantidad) {
        delete arreglo[indice];

        for (int i = indice; i < cantidad - 1; i++) {
            arreglo[i] = arreglo[i + 1];
        }
        
        cantidad--;
    }
}

Boleto* ArregloBoletos::Obtener(int indice) {
    if (indice >= 0 && indice < cantidad) {
        return arreglo[indice];
    }
    return nullptr;
}

int ArregloBoletos::GetCantidad() {
    return cantidad;
}

int ArregloBoletos::GenerarCodigoCorrelativo() {
    if (cantidad == 0) {
        return 10001;
    } else {
        return arreglo[cantidad - 1]->GetCodigo() + 1;
    }
}

void ArregloBoletos::GuardarEnArchivo() {
    ofstream archivo("boletos.dat", ios::binary); 
    
    if (!archivo) {
        cout << "Error al intentar guardar el archivo de boletos." << endl;
        return;
    }

    archivo.write((char*)&cantidad, sizeof(int));

    for (int i = 0; i < cantidad; i++) {
        archivo.write((char*)arreglo[i], sizeof(Boleto));
    }

    archivo.close();
}

void ArregloBoletos::CargarDesdeArchivo() {
    ifstream archivo("boletos.dat", ios::binary);
    
    if (!archivo) {
        return;
    }

    int cantidadGuardada;
    archivo.read((char*)&cantidadGuardada, sizeof(int));

    for (int i = 0; i < cantidadGuardada; i++) {
        Boleto objTemporal;
        archivo.read((char*)&objTemporal, sizeof(Boleto));

        Boleto* nuevoBoleto = new Boleto(
            objTemporal.GetCodigo(),
            objTemporal.GetPrecio(),
            objTemporal.GetCodigoVuelo(),
            objTemporal.GetAsiento(),
            objTemporal.GetTipo(),
            objTemporal.GetDniPasajero()
        );

        this->Agregar(nuevoBoleto);
    }

    archivo.close();
}