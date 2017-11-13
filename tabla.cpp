#include <string>
#include "tabla.h"

using namespace std;

Tabla::Tabla(const char* nt){
    nombreTabla=nt;
}

void Tabla::insertarCampo(Campo cmp){
    camposTabla.agregarElementoFin(cmp);
}

void Tabla::eliminarCampo(string nombreCampo){
    int pos=0;
    while(pos<camposTabla.getTamanyo()){
        if(camposTabla.obtenerElemento(pos).getNombre()!=nombreCampo)
            pos++;
        else{
            camposTabla.eliminarElementoPos(pos);
        }
    }
}

void Tabla::verCampos(){
    camposTabla.recorrerLista();
}

void Tabla::insertarRegistro(ListaEnlazada<string> entradas){
    if (entradas.getTamanyo()<camposTabla.getTamanyo()){
        cerr<<"Datos insuficientes"<<endl;
        return;
    }
    for (int i=0;i<entradas.getTamanyo();i++)
        camposTabla.obtenerElemento(i).agregarDato(entradas.obtenerElemento(i));
}

ListaEnlazada<string> Tabla::leerRegistro(int pos){
    ListaEnlazada<string> salida;
    if(pos>=camposTabla.obtenerElemento(0).numeroDatos())
        cerr<<"Valor fuera de rango"<<endl;
    else{
        for(int i=0;i<camposTabla.getTamanyo();i++)
            camposTabla.obtenerElemento(i);
    }
}
