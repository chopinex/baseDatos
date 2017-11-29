#ifndef BASEDATOSCONTROL_H_INCLUDED
#define BASEDATOSCONTROL_H_INCLUDED

#include <string>
#include "baseDatosVista.h"
#include "basedatos.h"

class BaseDatosControl{
    int opcion;
public:
    void setOpcion(BaseDatos&,BaseDatosVista&,bool&,bool&);
    void ejecutar(BaseDatos&,BaseDatosVista&,bool&,bool&);
};


#endif // BASEDATOSCONTROL_H_INCLUDED
