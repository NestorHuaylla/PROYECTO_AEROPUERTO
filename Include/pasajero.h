#ifndef PERSONA_H
#define PERSONA_H
#include<iostrteam>
#include<tuple>
using namespace std;
class persona{
    private:
    string nombre;
    int edad;
    int dni;
    int pasaporte;
    public:
    persona(string nom, int ed, int dni, int pas);
    tuple<string,int,int,int> getdatos();
    void mostrarDatos();
}