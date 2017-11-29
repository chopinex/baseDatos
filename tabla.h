#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED

#include <string>
#include <iostream>

#include "lista.h"
#include "campo.h"
#include "indice.h"

using namespace std;

class Tabla{
    string nombreTabla;
    string nombreArchivoTabla;
    ListaEnlazada<Campo*> camposTabla;
    int campoIndexado;
    Indice *ind;

public:
    Tabla(string);
    ~Tabla();

    string getNombre() const;
    void insertarCampo(string,string,bool);
    void eliminarCampo(string);
    bool hayCampo(string);
    ListaEnlazada<string>& getCampos(ListaEnlazada<string>&) const;
    void insertarRegistro(ListaEnlazada<string>&);
    ListaEnlazada<string> leerRegistro(int) const;
    ListaEnlazada<string>& leerTabla(ListaEnlazada<string>&) const;
    void eliminarRegistro(int);
    ListaEnlazada<string> buscarRegistro(string);

    friend ostream& operator<<(ostream &os, const Tabla &t){
        os<<t.nombreTabla;
        return os;
    }
};
#endif // TABLA_H_INCLUDED
