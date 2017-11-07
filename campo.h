#ifndef CAMPO_H_INCLUDED
#define CAMPO_H_INCLUDED

#include <string>
#include "lista.h"

using namespace std;
class Campo{
    string nombre,tipo;
    bool indexado,obligatorio;

public:
    Campo(string n,string t,bool i,bool o) : nombre(n), tipo(t), indexado(i), obligatorio(i){};
    string getNombre(){return nombre;};
    string getTipo(){return tipo;};
    bool esIndexado(){return indexado;};
    bool esObligatorio(){return obligatorio;};

    void setNombre(string nn){nombre=nn;};
    virtual void agregarDato(){return;};
    virtual void eliminarDato(){return;};
    virtual void verDatos(){return;};
};

class CampoEntero : public Campo{
    ListaEnlazada<int> datos;

public:
    CampoEntero(string n,string t,bool i,bool o):Campo(n,t,i,o){};
};

#endif // CAMPO_H_INCLUDED
