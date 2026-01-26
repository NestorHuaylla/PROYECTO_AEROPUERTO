#ifndef ARREGLOPASAJEROS_H
#define ARREGLOPASAJEROS_H

#include "Pasajero.h"
#include <fstream>

class ArregloPasajeros {
private:
    Pasajero** arreglo;
    int cantidad;
    int capacidad;

public:
    ArregloPasajeros();
    ~ArregloPasajeros();

    void Agregar(Pasajero* obj);
    void Eliminar(int indice);
    
    Pasajero* BuscarPorDni(const char* dni);
    int BuscarPosicion(const char* dni);
    
    Pasajero* Obtener(int indice);
    int GetCantidad();

    void GuardarEnArchivo();
    void CargarDesdeArchivo();
};

#endif 