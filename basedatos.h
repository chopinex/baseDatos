#ifndef BASEDATOS_H_INCLUDED
#define BASEDATOS_H_INCLUDED



#endif // BASEDATOS_H_INCLUDED
#include <string>
#include "lista.h"

class BaseDatos{
    string nombreArchivo;
    ListaEnlazada tablas;

public:
    BaseDatos(string);
    ~BaseDatos();
    void crearTabla();
    void eliminarTabla();
};
