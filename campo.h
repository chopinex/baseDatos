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
    virtual string verDato(int){return "";};
    virtual int numeroDatos(){return 0;};
    virtual void eliminarDato(int){return;};

    bool operator==(Campo);

    friend ostream& operator<<(ostream &os, const Campo &c){
        os<<c.nombre<<" ("<<c.tipo<<")";
        return os;
    }
};

class CampoEntero : public Campo{

public:
    ListaEnlazada<int> datos;
    CampoEntero(string n,bool i,bool o):Campo(n,"entero",i,o){};
    void cambiarDato(int,string);
    string verDato(int);
    void agregarDato(string);
    int numeroDatos();
    void eliminarDato(int);
};

class CampoDecimal : public Campo{

public:
    ListaEnlazada<float> datos;
    CampoDecimal(string n,bool i,bool o):Campo(n,"decimal",i,o){};
    void cambiarDato(int,string);
    string verDato(int);
    void agregarDato(string);
    int numeroDatos();
    void eliminarDato(int);
};

class CampoCadena : public Campo{

public:
    ListaEnlazada<string> datos;
    CampoCadena(string n,bool i,bool o):Campo(n,"cadena",i,o){};
    void cambiarDato(int,string);
    string verDato(int);
    void agregarDato(string);
    int numeroDatos();
    void eliminarDato(int);
};

#endif // CAMPO_H_INCLUDED
