#include <iostream>
#include <string>
#include <limits>

#include "baseDatosControl.h"
#include "baseDatosVista.h"
#include "basedatos.h"

using namespace std;
void BaseDatosControl::setOpcion(BaseDatos &bd,BaseDatosVista &bdv,bool &flag, bool &view){
    while(!(cin>>opcion)||opcion<0||opcion>4){
        bdv.mensajeConfirmacion("Valor incorrecto. Debe ser un entero entre 0 y 4.");
        bdv.mostrarComandos();
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
    }
    ejecutar(bd,bdv,flag,view);
}

void BaseDatosControl::ejecutar(BaseDatos &bd, BaseDatosVista &bdv, bool &flag, bool &view){
    switch(opcion){
    case 1:
        bdv.mostrarTablas(bd);
        break;
    case 2:{
        string nTabla;
        bdv.mensajeEntrada("Introduzca el nombre de la tabla a usar");
        cin>>nTabla;
        if (bd.setTabla(nTabla))
            view=!view;
        else
            bdv.mensajeEntrada("Tabla no encontrada");
        break;
    }
    case 3:{
        string nTabla;
        bdv.mensajeEntrada("Introduzca el nombre de tabla a agregar");
        cin>>nTabla;
        bdv.mensajeConfirmacion(bd.crearTabla(nTabla));
        break;
    }
    case 4:{
        string nTabla;
        bdv.mensajeEntrada("Introduzca el nombre de tabla a eliminar");
        cin>>nTabla;
        bd.eliminarTabla(nTabla);
        break;
    }
    default:
        flag=!flag;
        break;
    }
    return;
}
