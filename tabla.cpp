#include <string>
#include "tabla.h"

using namespace std;

Tabla::Tabla(const char* nt){
    nombreTabla=nt;
    campoIndexado=-1;
}

Tabla::~Tabla(){
    for(int i=0;i<camposTabla.getTamanyo();i++)
        delete camposTabla.obtenerElemento(i);
}

void Tabla::insertarCampo(string nombre,string tipo,bool indice,bool obligatorio){
    if(tipo=="entero"){
        camposTabla.agregarElementoFin(new CampoEntero(nombre,indice,obligatorio));
        if (indice){
            ind = new IndiceEntero;
            campoIndexado=camposTabla.getTamanyo()-1;
        }

    }
    else{
        if(tipo=="decimal")
        {
            camposTabla.agregarElementoFin(new CampoDecimal(nombre,indice,obligatorio));
            if (indice){
                ind = new IndiceDecimal;
                campoIndexado=camposTabla.getTamanyo()-1;
            }

        }

        else{
            if(tipo=="cadena"){
                camposTabla.agregarElementoFin(new CampoCadena(nombre,indice,obligatorio));
                if (indice){
                    ind = new IndiceCadena;
                    campoIndexado=camposTabla.getTamanyo()-1;
                }
            }

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
            if(pos==campoIndexado){
                delete ind;
                campoIndexado=-1;
            }

            camposTabla.eliminarElementoPos(pos);
        }
    }
}

void Tabla::verCampos(){
    for(int i=0;i<camposTabla.getTamanyo();i++)
        cout<<*camposTabla.obtenerElemento(i)<<" - ";
    cout<<endl;
}

void Tabla::insertarRegistro(ListaEnlazada<string> entradas){
    if (entradas.getTamanyo()<camposTabla.getTamanyo()){
        cerr<<"Datos insuficientes"<<endl;
        return;
    }
    for (int i=0;i<entradas.getTamanyo();i++){
        camposTabla.obtenerElemento(i)->agregarDato(entradas.obtenerElemento(i));
        if(i==campoIndexado)
            ind->agregarAlIndice(entradas.obtenerElemento(i),i);
    }
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
    for (int i=0;i<camposTabla.getTamanyo();i++){
        if(i==campoIndexado)
            ind->eliminarDelIndice(i);
        camposTabla.obtenerElemento(i)->eliminarDato(pos);
    }
}

ListaEnlazada<string> Tabla::buscarRegistro(string busqueda){
    ListaEnlazada<string> salida;
    int reg;
    reg=ind->buscar(busqueda);
    for(int i=0;i<camposTabla.getTamanyo();i++)
        salida.agregarElementoFin(camposTabla.obtenerElemento(i)->verDato(reg));
    return salida;
}
