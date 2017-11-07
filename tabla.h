#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED

#include "lista.h"
#include <string>

using namespace std;

class Tabla{
    const char* nombreTabla;
    ListaEnlazada<string> camposindices;
};

#endif // TABLA_H_INCLUDED
