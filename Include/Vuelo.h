#ifndef VUELO_H
#define VUELO_H

class Vuelo {
    private:
        int cod_vuelo; 
        char aerolinea[30]; 
        char origen[20]; 
        char destino[20]; 
        char fecha[15];    
        float precio_base; 

    public:
        Vuelo();
        Vuelo(int Cod, char Aero[30], char Ori[20], char Des[20], char Fec[15], float Pre);

        void SetVuelo(int Cod, char Aero[30], char Ori[20], char Des[20], char Fec[15], float Pre);
        
        int GetCodigo();
        char* GetAerolinea();
        char* GetOrigen();
        char* GetDestino();
        char* GetFecha();
        float GetPrecioBase();

        void Mostrar();
};

#endif