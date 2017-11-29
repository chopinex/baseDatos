#include "basedatos.h"
#include <fstream>
#include <iostream>
#include <string>
#include "lista.h"
#include "tabla.h"

using namespace std;

BaseDatos::BaseDatos(const char* na){
    nombreArchivo=na;
    ifstream entrada(nombreArchivo);
    if (!entrada){
        ofstream archivo(nombreArchivo);
        archivo.close();
    }
    string nombreTabla;
    while(entrada>>nombreTabla)
        tablas.agregarElementoFin(new Tabla(nombreTabla));
    entrada.close();
}

BaseDatos::~BaseDatos(){
    ofstream salida(nombreArchivo);
    for(int i=0;i<tablas.getTamanyo();i++){
        salida<<*tablas.obtenerElemento(i)<<endl;
        delete tablas.obtenerElemento(i);
    }
    salida.close();
}

string BaseDatos::nombreTabla() const{
    return tablaActual->getNombre();
}

string BaseDatos::crearTabla(string tabla){
    for(int i=0;i<tablas.getTamanyo();i++)
        if(tablas.obtenerElemento(i)->getNombre()==tabla)
            return "Tabla ya existe";
    tablas.agregarElementoFin(new Tabla(tabla));
    return "Tabla agregada";
}

void BaseDatos::eliminarTabla(string tabla){
    for(int i=0;i<tablas.getTamanyo();i++)
        if (tablas.obtenerElemento(i)->getNombre()==tabla){
            tablas.eliminarElemento(tablas.obtenerElemento(i));
            break;
        }
}

bool BaseDatos::setTabla(string nombre){
    for (int i=0;i<tablas.getTamanyo();i++)
        if(tablas.obtenerElemento(i)->getNombre()==nombre){
            tablaActual=tablas.obtenerElemento(i);
            return true;
        }
    return false;
}

ListaEnlazada<string>& BaseDatos::getNombreTablas(ListaEnlazada<string> &le) const{
    for (int i=0;i<tablas.getTamanyo();i++)
        le.agregarElementoFin(tablas.obtenerElemento(i)->getNombre());
    return le;
}

ListaEnlazada<string>& BaseDatos::verCamposTabla(ListaEnlazada<string>& campos) const{
    campos=tablaActual->getCampos(campos);
    return campos;
}

string BaseDatos::agregarCamposTabla(string nombre, string tipo, string siNo){
    if(!tablaActual->hayCampo(nombre)){
        if(tipo=="entero"||tipo=="decimal"||tipo=="cadena"){
            if(siNo=="s"||siNo=="S"){
                tablaActual->insertarCampo(nombre,tipo,true);
                return "Campo agregado";
            }
            else{
                if(siNo=="n"||siNo=="N"){
                    tablaActual->insertarCampo(nombre,tipo,false);
                    return "Campo agregado";
                }
                else
                    return "Opcion de eleccion no valida (solo s/n).";
            }
        }
        else
            return "Tipo no valido.";
    }
    else
        return "Campo ya existe.";
}

string BaseDatos::eliminarCampoTabla(string nombre){
    if(tablaActual->hayCampo(nombre)){
        tablaActual->eliminarCampo(nombre);
        return "Campo eliminado";
    }
    else
        return "Campo no existe";
}

ListaEnlazada<string>& BaseDatos::verRegistrosTabla(ListaEnlazada<string>& registros) const{
    registros=tablaActual->leerTabla(registros);
    return registros;
}

