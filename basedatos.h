#ifndef BASEDATOS_H_INCLUDED
#define BASEDATOS_H_INCLUDED

#include "tabla.h"
#include "lista.h"

using namespace std;

class BaseDatos{
    const char *nombreArchivo;
    ListaEnlazada<Tabla*> tablas;
    Tabla* tablaActual;

public:
    BaseDatos(const char*);
    ~BaseDatos();
    string nombreTabla() const;
    string crearTabla(string);
    void eliminarTabla(string);
    bool setTabla(string nombre);
    ListaEnlazada<string>& getNombreTablas(ListaEnlazada<string>&) const;

    ListaEnlazada<string>& verCamposTabla(ListaEnlazada<string>&) const;
    string agregarCamposTabla(string, string, string);
    string eliminarCampoTabla(string);
    ListaEnlazada<string>& verRegistrosTabla(ListaEnlazada<string>&) const;
};

#endif // BASEDATOS_H_INCLUDED
