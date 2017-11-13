#ifndef CAMPO_H_INCLUDED
#define CAMPO_H_INCLUDED

#include <string>
#include <iostream>
#include "lista.h"

using namespace std;
class Campo{
    string nombre,tipo;
    bool indexado,obligatorio;

public:
    Campo(){nombre="";tipo="";indexado=false;obligatorio=false;};
    Campo(string n,string t,bool i,bool o) : nombre(n), tipo(t), indexado(i), obligatorio(i){};
    string getNombre(){return nombre;};
    string getTipo(){return tipo;};
    bool esIndexado(){return indexado;};
    bool esObligatorio(){return obligatorio;};

    void setNombre(string nn){nombre=nn;};
    virtual void agregarDato(string){return;};
    virtual int numeroDatos(){return 0;};

    bool operator==(Campo);

    friend ostream& operator<<(ostream &os, const Campo &c){
        os<<c.nombre<<" ("<<c.tipo<<")";
        return os;
    }
};

class CampoEntero : public Campo{
    ListaEnlazada<int> datos;

public:
    CampoEntero(string n,bool i,bool o):Campo(n,"entero",i,o){};
    void cambiarDato(int,int);
    int verDato(int);
    void agregarDato(string);
    int numeroDatos();
};

class CampoDecimal : public Campo{
    ListaEnlazada<float> datos;

public:
    CampoDecimal(string n,bool i,bool o):Campo(n,"decimal",i,o){};
    void cambiarDato(int,float);
    float verDato(int);
    void agregarDato(string);
    int numeroDatos();
};

class CampoCadena : public Campo{
    ListaEnlazada<string> datos;

public:
    CampoCadena(string n,bool i,bool o):Campo(n,"cadena",i,o){};
    void cambiarDato(int,string);
    string verDato(int);
    void agregarDato(string);
    int numeroDatos();
};

#endif // CAMPO_H_INCLUDED
