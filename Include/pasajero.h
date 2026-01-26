#ifndef PASAJERO_H
#define PASAJERO_H

class Pasajero {
    private:
        char dni[10]; 
        char nombres[50]; 
        char telefono[15]; 
        char nacionalidad[20];  

    public:
        Pasajero();
        Pasajero(char Dni[10], char Nom[50], char Tel[15], char Nac[20]);

        void SetPasajero(char Dni[10], char Nom[50], char Tel[15], char Nac[20]);
        
        char* GetDni();
        char* GetNombres();
        char* GetTelefono();
        char* GetNacionalidad();

        void Mostrar();
};

#endif