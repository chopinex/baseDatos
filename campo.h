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
    virtual void verDato(int){return;};
};

class CampoEntero : public Campo{
    ListaEnlazada<int> datos;

public:
    CampoEntero(string n,bool i,bool o):Campo(n,"entero",i,o){};
    void cambiarDato(int,int);
    void verDato(int);
};

class CampoDecimal : public Campo{
    ListaEnlazada<float> datos;

public:
    CampoDecimal(string n,bool i,bool o):Campo(n,"decimal",i,o){};
    void cambiarDato(int,float);
    void verDato(float);
};

class CampoCadena : public Campo{
    ListaEnlazada<string> datos;

public:
    CampoCadena(string n,bool i,bool o):Campo(n,"cadena",i,o){};
    void cambiarDato(int,string);
    void verDato(string);
};

#endif // CAMPO_H_INCLUDED
