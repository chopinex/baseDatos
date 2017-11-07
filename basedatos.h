#ifndef BASEDATOS_H_INCLUDED
#define BASEDATOS_H_INCLUDED

#include <fstream>
#include "lista.h"

using namespace std;

class BaseDatos{
    const char *nombreArchivo;
    ListaEnlazada<string> tablas;

public:
    BaseDatos(const char*);
    // ~BaseDatos();
    void mostrarTablas();
    void crearTabla(string);
    void eliminarTabla(string);
};

#endif // BASEDATOS_H_INCLUDED
