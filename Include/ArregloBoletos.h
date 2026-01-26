#ifndef ARREGLOBOLETOS_H
#define ARREGLOBOLETOS_H

#include "Boleto.h"
#include <fstream>

class ArregloBoletos {
private:
    Boleto** arreglo; 
    
    int cantidad;
    int capacidad;

public:
    ArregloBoletos();
    ~ArregloBoletos();

    void Agregar(Boleto* obj);
    void Eliminar(int indice);
    
    Boleto* BuscarPorCodigo(int codigo);
    Boleto* Obtener(int indice);
    int BuscarPosicion(int codigo);

    int GetCantidad();
    int GenerarCodigoCorrelativo();

    void GuardarEnArchivo();
    void CargarDesdeArchivo();
};

#endif