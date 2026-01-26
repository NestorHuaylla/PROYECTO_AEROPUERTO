#include "../include/Consultar.h"
#include <iostream>
#include <cstdlib> 

using namespace std;


void Consultar::ListarPasajeros(ArregloPasajeros* obj) {
    if (obj->GetCantidad() == 0) {
        cout << "No hay pasajeros registrados." << endl;
        return;
    }
    
    cout << "\n=== LISTA DE PASAJEROS (" << obj->GetCantidad() << ") ===" << endl;
    for(int i = 0; i < obj->GetCantidad(); i++) {
        obj->Obtener(i)->Mostrar(); 
    }
}

void Consultar::BuscarPasajero(ArregloPasajeros* obj) {
    char dni[10];
    cout << "\nIngrese DNI a buscar: ";
    cin >> dni;
    
    Pasajero* encontrado = obj->BuscarPorDni(dni);
    
    if (encontrado != nullptr) {
        cout << "\n[RESULTADO ENCONTRADO]" << endl;
        encontrado->Mostrar();
    } else {
        cout << "\n[!] No se encontro ningun pasajero con DNI " << dni << endl;
    }
}


void Consultar::ListarVuelos(ArregloVuelos* obj) {
    if (obj->GetCantidad() == 0) {
        cout << "No hay vuelos registrados." << endl;
        return;
    }

    cout << "\n=== LISTA DE VUELOS DISPONIBLES ===" << endl;
    for(int i = 0; i < obj->GetCantidad(); i++) {
        obj->Obtener(i)->Mostrar();
    }
}

void Consultar::BuscarVuelo(ArregloVuelos* obj) {
    int codigo;
    cout << "\nIngrese Codigo de Vuelo a buscar: ";
    cin >> codigo;

    Vuelo* encontrado = obj->BuscarPorCodigo(codigo);

    if (encontrado != nullptr) {
        cout << "\n[RESULTADO ENCONTRADO]" << endl;
        encontrado->Mostrar();
    } else {
        cout << "\n[!] No existe el vuelo #" << codigo << endl;
    }
}


void Consultar::ListarVentas(ArregloBoletos* obj) {
    if (obj->GetCantidad() == 0) {
        cout << "No se han realizado ventas aun." << endl;
        return;
    }

    cout << "\n=== REPORTE DE VENTAS (BOLETOS) ===" << endl;
    for(int i = 0; i < obj->GetCantidad(); i++) {
        obj->Obtener(i)->Mostrar(); 
    }
}