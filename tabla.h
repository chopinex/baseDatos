#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED

#include "lista.h"
#include "campo.h"
#include <string>

using namespace std;

class Tabla{
    const char* nombreTabla;
    ListaEnlazada<Campo> camposTabla;
public:
    Tabla(const char*);
    void insertarCampo(Campo);
    void eliminarCampo(string);
    void verCampos();
    void insertarRegistro(ListaEnlazada<string>);
    ListaEnlazada<string> leerRegistro(int);
};
#endif // TABLA_H_INCLUDED
