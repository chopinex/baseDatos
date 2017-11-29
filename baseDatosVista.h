#ifndef BASEDATOSVISTA_H_INCLUDED
#define BASEDATOSVISTA_H_INCLUDED

#include "lista.h"
#include "basedatos.h"
#include <string>

using namespace std;
class BaseDatosVista{
    ListaEnlazada<string> vistaTablas;
public:
    void mostrarTablas(const BaseDatos&);
    void mostrarComandos() const;
    void mensajeConfirmacion(const string&) const;
    void mensajeEntrada(const string&) const;
};


#endif // BASEDATOSVISTA_H_INCLUDED
