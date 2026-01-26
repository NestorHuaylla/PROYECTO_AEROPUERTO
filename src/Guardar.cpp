#include "../include/Guardar.h"
#include <iostream>

using namespace std;

void Guardar::GuardarTodo(ArregloPasajeros* pasajeros, ArregloVuelos* vuelos, ArregloBoletos* boletos) {
    cout << "\nIniciando proceso de guardado..." << endl;

    if (pasajeros != nullptr) {
        pasajeros->GuardarEnArchivo();
        cout << "- Pasajeros guardados correctamente (pasajeros.bin)." << endl;
    }

    if (vuelos != nullptr) {
        vuelos->GuardarEnArchivo();
        cout << "- Vuelos guardados correctamente (vuelos.bin)." << endl;
    }

    if (boletos != nullptr) {
        boletos->GuardarEnArchivo();
        cout << "- Boletos guardados correctamente (boletos.dat)." << endl;
    }

    cout << "Todos los datos han sido respaldados." << endl;
}