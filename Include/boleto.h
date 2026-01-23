#ifndef BOLETO_H
#define BOLETO_H

class Boleto {
    private:
        int cod_boleto;
        float precio;
        char codigo_vuelo[20];
        char asiento[10];
        char tipo[20];
        char dni_pasajero[15];

    public:
        Boleto();
        Boleto(int cod, float precio, char Vuelo[20], char Asiento[10], char Tipo[20], char Dni[15]);

        void SetCodigo(int cod);
        void SetBoleto(float precio, char Vuelo[20], char Asiento[10], char Tipo[20], char Dni[15]);
        void SetBoleto(Boleto boleto); 
        void SetPrecio(float Precio);

        int GetCodigo();
        float GetPrecio();
        char* GetCodigoVuelo();
        char* GetAsiento();
        char* GetTipo();
        char* GetDniPasajero();

        void Mostrar();
        void MostrarConsulta();
        
        ~Boleto();
};

#endif