#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED

#include "lista.h"
#include "campo.h"
#include "indice.h"
#include <string>

using namespace std;

class Tabla{
    const char* nombreTabla;
    const char *nombreArchivoTabla;
    ListaEnlazada<Campo*> camposTabla;
    int campoIndexado;
    Indice *ind;

public:
    Tabla(const char*);
    ~Tabla();

    void insertarCampo(string,string,bool,bool);
    void eliminarCampo(string);
    void verCampos();
    void insertarRegistro(ListaEnlazada<string>);
    ListaEnlazada<string> leerRegistro(int);
    void eliminarRegistro(int);
    ListaEnlazada<string> buscarRegistro(string);
};
#endif // TABLA_H_INCLUDED
