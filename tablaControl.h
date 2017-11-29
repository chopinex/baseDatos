#ifndef TABLACONTROL_H_INCLUDED
#define TABLACONTROL_H_INCLUDED

#include "basedatos.h"
#include "tablaVista.h"

class TablaControl{
    int opcion;
public:
    void setOpcion(BaseDatos&,TablaVista&,bool&);
    void ejecutar(BaseDatos&,TablaVista&,bool&);
};


#endif // TABLACONTROL_H_INCLUDED
