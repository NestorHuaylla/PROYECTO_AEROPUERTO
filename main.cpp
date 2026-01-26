#include <iostream>
#include <cstdlib> 
#include <cstdio>  

#include "include/Consultar.h"
#include "include/Guardar.h"
#include "include/ArregloPasajeros.h"
#include "include/ArregloVuelos.h"
#include "include/ArregloBoletos.h"

using namespace std;

ArregloPasajeros* objPasajeros;
ArregloVuelos* objVuelos;
ArregloBoletos* objBoletos;

void limpiar() {
    system("cls"); 
}
void pausar() {
    system("pause");
}

void menuPasajeros() {
    int opcion;
    do {
        limpiar();
        cout << "=== GESTION DE PASAJEROS ===" << endl;
        cout << "1. Registrar Pasajero" << endl;
        cout << "2. Listar Pasajeros" << endl;
        cout << "3. Buscar Pasajero (DNI)" << endl;
        cout << "4. Volver al Menu Principal" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            char dni[10], nom[50], tel[15], nac[20];
            
            cout << "\n--- Nuevo Pasajero ---" << endl;
            cout << "DNI: "; cin >> dni;
            cin.ignore();
            cout << "Nombre Completo: "; cin.getline(nom, 50);
            cout << "Telefono: "; cin >> tel;
            cout << "Nacionalidad: "; cin >> nac;

            Pasajero* nuevo = new Pasajero(dni, nom, tel, nac);
            objPasajeros->Agregar(nuevo);
            cout << "Pasajero registrado con exito!" << endl;
            pausar();
        }
        else if (opcion == 2) {
            Consultar::ListarPasajeros(objPasajeros);
            pausar();
        }
        else if (opcion == 3) {
            Consultar::BuscarPasajero(objPasajeros);
            pausar();
        }

    } while (opcion != 4);
}

void menuVuelos() {
    int opcion;
    do {
        limpiar();
        cout << "=== GESTION DE VUELOS ===" << endl;
        cout << "1. Registrar Vuelo" << endl;
        cout << "2. Listar Vuelos" << endl;
        cout << "3. Buscar Vuelo (Codigo)" << endl; // Agregué opción de búsqueda
        cout << "4. Volver" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int cod = objVuelos->GenerarCodigoCorrelativo();
            char aero[30], ori[20], des[20], fecha[15];
            float precio;

            cin.ignore();
            cout << "\n--- Nuevo Vuelo (Codigo Auto: " << cod << ") ---" << endl;
            cout << "Aerolinea: "; cin.getline(aero, 30);
            cout << "Origen: "; cin >> ori;
            cout << "Destino: "; cin >> des;
            cout << "Fecha (DD/MM/AAAA): "; cin >> fecha;
            cout << "Precio Base: "; cin >> precio;

            Vuelo* nuevo = new Vuelo(cod, aero, ori, des, fecha, precio);
            objVuelos->Agregar(nuevo);
            cout << "Vuelo registrado correctamente!" << endl;
            pausar();
        }
        else if (opcion == 2) {
            Consultar::ListarVuelos(objVuelos);
            pausar();
        }
        else if (opcion == 3) {
            Consultar::BuscarVuelo(objVuelos);
            pausar();
        }

    } while (opcion != 4);
}

void menuBoletos() {
    int opcion;
    do {
        limpiar();
        cout << "=== GESTION DE BOLETOS (VENTA) ===" << endl;
        cout << "1. Vender Boleto" << endl;
        cout << "2. Listar Boletos Vendidos" << endl;
        cout << "3. Volver" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            char dniBusqueda[10];
            int codigoVueloBusqueda;
            
            cout << "\nIngrese DNI del Pasajero: ";
            cin >> dniBusqueda;
            
            Pasajero* pas = objPasajeros->BuscarPorDni(dniBusqueda);
            if (pas == nullptr) {
                cout << "Error: El pasajero no existe. Registrelo primero." << endl;
                pausar();
                continue;
            }
            cout << "-> Pasajero: " << pas->GetNombres() << endl;

            cout << "Ingrese Codigo del Vuelo: ";
            cin >> codigoVueloBusqueda;

            Vuelo* vue = objVuelos->BuscarPorCodigo(codigoVueloBusqueda);
            if (vue == nullptr) {
                cout << "Error: El vuelo no existe." << endl;
                pausar();
                continue;
            }
            cout << "-> Vuelo: " << vue->GetOrigen() << " - " << vue->GetDestino() << endl;

            int codBoleto = objBoletos->GenerarCodigoCorrelativo();
            char asiento[10], tipo[20], codVueloTexto[20];
            float precioFinal;

            sprintf(codVueloTexto, "%d", codigoVueloBusqueda); 

            cout << "Asiento (Ej. 14A): "; cin >> asiento;
            cout << "Tipo (Nacional/Internacional): "; cin >> tipo;
            cout << "Precio Final: "; cin >> precioFinal;

            Boleto* nuevo = new Boleto(codBoleto, precioFinal, codVueloTexto, asiento, tipo, dniBusqueda);
            objBoletos->Agregar(nuevo);

            cout << "\nVenta registrada con exito! (Boleto #" << codBoleto << ")" << endl;
            pausar();
        }
        else if (opcion == 2) {
            Consultar::ListarVentas(objBoletos);
            pausar();
        }

    } while (opcion != 3);
}

int main() {
    objPasajeros = new ArregloPasajeros();
    objVuelos = new ArregloVuelos();
    objBoletos = new ArregloBoletos();

    int opcion;
    do {
        limpiar();
        cout << "=================================" << endl;
        cout << "   SISTEMA DE AEROPUERTO v1.0    " << endl;
        cout << "=================================" << endl;
        cout << "1. Gestionar Pasajeros" << endl;
        cout << "2. Gestionar Vuelos" << endl;
        cout << "3. Gestionar Boletos (Venta)" << endl; 
        cout << "4. SALIR y GUARDAR DATOS" << endl;
        cout << "=================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuPasajeros(); break;
            case 2: menuVuelos(); break;
            case 3: menuBoletos(); break;
            case 4: break; 
        }

    } while (opcion != 4);

    Guardar::GuardarTodo(objPasajeros, objVuelos, objBoletos);

    delete objPasajeros;
    delete objVuelos;
    delete objBoletos;

    cout << "Datos guardados. Saliendo del sistema..." << endl;
    return 0;
}