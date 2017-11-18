#include <string>
#include "tabla.h"

using namespace std;

Tabla::Tabla(const char* nt){
    nombreTabla=nt;
}

Tabla::~Tabla(){
    for(int i=0;i<camposTabla.getTamanyo();i++)
        delete camposTabla.obtenerElemento(i);
}

void Tabla::insertarCampo(string nombre,string tipo,bool indice,bool obligatorio){
    if(tipo=="entero")
        camposTabla.agregarElementoFin(new CampoEntero(nombre,indice,obligatorio));
    else{
        if(tipo=="decimal")
            camposTabla.agregarElementoFin(new CampoDecimal(nombre,indice,obligatorio));
        else{
            if(tipo=="cadena")
                camposTabla.agregarElementoFin(new CampoCadena(nombre,indice,obligatorio));
            else
                cout<<"Tipo de datos no válido"<<endl;
        }
    }
}

void Tabla::eliminarCampo(string nombreCampo){
    int pos=0;
    while(pos<camposTabla.getTamanyo()){
        if(camposTabla.obtenerElemento(pos)->getNombre()!=nombreCampo)
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
        camposTabla.obtenerElemento(i)->agregarDato(entradas.obtenerElemento(i));
}

ListaEnlazada<string> Tabla::leerRegistro(int pos){
    ListaEnlazada<string> salida;
    if(pos>=camposTabla.obtenerElemento(0)->numeroDatos())
        cerr<<"Valor fuera de rango"<<endl;
    else
        for(int i=0;i<camposTabla.getTamanyo();i++)
            salida.agregarElementoFin(camposTabla.obtenerElemento(i)->verDato(pos));
    return salida;
}

void Tabla::eliminarRegistro(int pos){
    if (pos>=camposTabla.getTamanyo()){
        cerr<<"Valor fuera de rango"<<endl;
        return;
    }
    for (int i=0;i<camposTabla.getTamanyo();i++)
        camposTabla.obtenerElemento(i)->eliminarDato(pos);
}
