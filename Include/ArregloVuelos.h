#ifndef ARREGLOVUELOS_H
#define ARREGLOVUELOS_H

#include "Vuelo.h"
#include <fstream>

class ArregloVuelos {
private:
    Vuelo** arreglo;
    int cantidad;
    int capacidad;

public:
    ArregloVuelos();
    ~ArregloVuelos();

    void Agregar(Vuelo* obj);
    void Eliminar(int indice);
    Vuelo* BuscarPorCodigo(int codigo);
    int BuscarPosicion(int codigo);
    Vuelo* Obtener(int indice);
    
    int GetCantidad();
    int GenerarCodigoCorrelativo(); 

    void GuardarEnArchivo();
    void CargarDesdeArchivo();
};

#endif 