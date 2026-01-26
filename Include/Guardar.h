#ifndef GUARDAR_H
#define GUARDAR_H

#include "ArregloPasajeros.h"
#include "ArregloVuelos.h"
#include "ArregloBoletos.h"

class Guardar {
public:
    static void GuardarTodo(ArregloPasajeros* pasajeros, ArregloVuelos* vuelos, ArregloBoletos* boletos);
};

#endif 