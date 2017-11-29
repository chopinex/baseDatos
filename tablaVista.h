#ifndef TABLAVISTA_H_INCLUDED
#define TABLAVISTA_H_INCLUDED

#include "basedatos.h"

class TablaVista{
    ListaEnlazada<string> vistaCampos;
    ListaEnlazada<string> vistaRegistros;

public:
    void verCampos(const BaseDatos&);
    void verTabla(const BaseDatos&);
    void verBusqueda(const BaseDatos&);
    void mostrarComandos();
    void mensajeConfirmacion(const string&) const;
    void mensajeEntrada(const string&) const;
};

#endif // TABLAVISTA_H_INCLUDED
