#ifndef CONSULTAR_H
#define CONSULTAR_H

#include "ArregloPasajeros.h"
#include "ArregloVuelos.h"
#include "ArregloBoletos.h"

class Consultar {
public:
    static void ListarPasajeros(ArregloPasajeros* obj);
    static void BuscarPasajero(ArregloPasajeros* obj);

    static void ListarVuelos(ArregloVuelos* obj);
    static void BuscarVuelo(ArregloVuelos* obj);

    static void ListarVentas(ArregloBoletos* obj);
};

#endif 