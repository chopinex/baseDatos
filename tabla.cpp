#include <string>
#include <fstream>
#include <sstream>
#include "tabla.h"

using namespace std;

Tabla::Tabla(string nt){
    nombreTabla=nt;
    campoIndexado=-1;
    nombreArchivoTabla=nombreTabla+".tab";
    ifstream entrada(nombreArchivoTabla.c_str());
    if (!entrada){
        ofstream archivo(nombreArchivoTabla);
        archivo.close();
        cerr << "Archivo creado" << endl;
    }
    int numCampos;
    string nombreCampo;
    string tipoCampo;
    string entradaIndexCampo;
    bool indexCampo;
    if(entrada>>numCampos){
        for(int i=0;i<numCampos;i++){
            entrada>>nombreCampo;
            entrada>>tipoCampo;
            entrada>>entradaIndexCampo;
            istringstream(entradaIndexCampo)>>indexCampo;
            insertarCampo(nombreCampo,tipoCampo,indexCampo);
        }
        string datoCampo;
        ListaEnlazada<string> registroCampo;
        while(entrada>>datoCampo)
            registroCampo.agregarElementoFin(datoCampo);
        while(registroCampo.getTamanyo()>0){
            insertarRegistro(registroCampo);
            for(int i=0;i<numCampos;i++)
                registroCampo.eliminarElementoPos(0);
        }
    }
}

Tabla::~Tabla(){
    for(int i=0;i<camposTabla.getTamanyo();i++)
        delete camposTabla.obtenerElemento(i);
}

string Tabla::getNombre() const{
    return nombreTabla;
}

void Tabla::insertarCampo(string nombre,string tipo,bool indice){
    if(tipo=="entero"){
        camposTabla.agregarElementoFin(new CampoEntero(nombre,indice));
        if (indice){
            ind = new IndiceEntero;
            campoIndexado=camposTabla.getTamanyo()-1;
        }
    }
    else{
        if(tipo=="decimal")
        {
            camposTabla.agregarElementoFin(new CampoDecimal(nombre,indice));
            if (indice){
                ind = new IndiceDecimal;
                campoIndexado=camposTabla.getTamanyo()-1;
            }
        }
        else{
            if(tipo=="cadena"){
                camposTabla.agregarElementoFin(new CampoCadena(nombre,indice));
                if (indice){
                    ind = new IndiceCadena;
                    campoIndexado=camposTabla.getTamanyo()-1;
                }
            }
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

bool Tabla::hayCampo(string nombre){
    for(int i=0;i<camposTabla.getTamanyo();i++)
        if(camposTabla.obtenerElemento(i)->getNombre()==nombre)
            return true;
    return false;
}

ListaEnlazada<string>& Tabla::getCampos(ListaEnlazada<string> &entrada) const{
    for(int i=0;i<camposTabla.getTamanyo();i++)
        entrada.agregarElementoFin(camposTabla.obtenerElemento(i)->getNombre()+"("+camposTabla.obtenerElemento(i)->getNombre()+")");
    return entrada;
}

void Tabla::insertarRegistro(ListaEnlazada<string> &entradas){
    if (entradas.getTamanyo()<camposTabla.getTamanyo()){
        cerr<<"Datos insuficientes"<<endl;
        return;
    }
    for (int i=0;i<camposTabla.getTamanyo();i++){
        camposTabla.obtenerElemento(i)->agregarDato(entradas.obtenerElemento(i));
        if(i==campoIndexado)
            ind->agregarAlIndice(entradas.obtenerElemento(i),i);
    }
}

ListaEnlazada<string> Tabla::leerRegistro(int pos) const{
    ListaEnlazada<string> salida;
    if(pos>=camposTabla.obtenerElemento(0)->numeroDatos())
        cerr<<"Valor fuera de rango"<<endl;
    else
        for(int i=0;i<camposTabla.getTamanyo();i++)
            salida.agregarElementoFin(camposTabla.obtenerElemento(i)->verDato(pos));
    return salida;
}

ListaEnlazada<string>& Tabla::leerTabla(ListaEnlazada<string> &entradas) const{
    ListaEnlazada<string> datos;
    for(int i=0;i<camposTabla.obtenerElemento(0)->numeroDatos();i++){
        datos=leerRegistro(i);
        string registro;
        for(int j=0;j<datos.getTamanyo();j++)
            registro+=datos.obtenerElemento(j)+"|";
        entradas.agregarElementoFin(registro);
    }
    return entradas;
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
