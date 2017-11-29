#include<limits>

#include "tablaControl.h"
#include "tablaVista.h"
#include "tabla.h"

void TablaControl::setOpcion(BaseDatos &bd,TablaVista &tv, bool &flag){
    while(!(cin>>opcion)||opcion<0||opcion>7){
        tv.mensajeConfirmacion("Valor incorrecto. Debe ser un entero entre 0 y 7.");
        tv.mostrarComandos();
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
    }
    ejecutar(bd,tv,flag);
}

void TablaControl::ejecutar(BaseDatos &bd,TablaVista &tv, bool &flag){
    switch(opcion){
    case 1:
        tv.verCampos(bd);
        break;
    case 2:{
        string nCampo;
        string tCampo;
        string iCampo;
        tv.mensajeEntrada("Introduzca el nombre de campo:");
        cin>>nCampo;
        tv.mensajeEntrada("Introduzca el tipo de campo(entero, decimal o cadena):");
        cin>>tCampo;
        tv.mensajeEntrada("Indexado? (s/n):");
        cin>>iCampo;
        tv.mensajeConfirmacion(bd.agregarCamposTabla(nCampo,tCampo,iCampo));
        break;
    }
    case 3:{
        string nCampo;
        tv.mensajeEntrada("Nombre de campo a eliminar:");
        cin>>nCampo;
        tv.mensajeConfirmacion(bd.eliminarCampoTabla(nCampo));
        break;
    }
    case 4:
        tv.verTabla(bd);
        break;
    case 0:
        flag=!flag;
        break;
    }
    return;
}
