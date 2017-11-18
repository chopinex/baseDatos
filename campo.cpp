#include "campo.h"
#include <iostream>
#include <string>

using namespace std;

bool Campo::operator==(Campo c){
    if(nombre==c.getNombre()&&tipo==c.getTipo())
        return true;
    return false;
}

void CampoEntero::cambiarDato(int pos,string nuevoDato){
    datos.cambiarElemento(pos,stoi(nuevoDato));
}

string CampoEntero::verDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return "";
    }
    else
        return to_string(datos.obtenerElemento(pos));
}

void CampoEntero::agregarDato(string entrada){
    int nuevoDato;
    if(nuevoDato=stoi(entrada)){
        cout<<"Dato agregado"<<endl;
        datos.agregarElementoFin(nuevoDato);
    }

    else
        cerr<<"Tipo de dato incorrecto"<<endl;
}

int CampoEntero::numeroDatos(){
    return datos.getTamanyo();
}

void CampoEntero::eliminarDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return;
    }
    else
        datos.eliminarElementoPos(pos);
}

void CampoDecimal::cambiarDato(int pos,string nuevoDato){
    datos.cambiarElemento(pos,stof(nuevoDato));
}

string CampoDecimal::verDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return "";
    }
    else
        return to_string(datos.obtenerElemento(pos));
}

void CampoDecimal::agregarDato(string entrada){
    float nuevoDato;
    if(nuevoDato=stof(entrada)){
        cout<<"Dato agregado"<<endl;
        datos.agregarElementoFin(nuevoDato);
    }
    else
        cerr<<"Tipo de dato incorrecto"<<endl;
}

int CampoDecimal::numeroDatos(){
    return datos.getTamanyo();
}

void CampoDecimal::eliminarDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return;
    }
    else
        datos.eliminarElementoPos(pos);
}

void CampoCadena::cambiarDato(int pos,string nuevoDato){
    datos.cambiarElemento(pos,nuevoDato);
}

string CampoCadena::verDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return "";
    }
    else
        return datos.obtenerElemento(pos);
}

int CampoCadena::numeroDatos(){
    return datos.getTamanyo();
}

void CampoCadena::agregarDato(string entrada){
    cout<<"Dato agregado"<<endl;
    datos.agregarElementoFin(entrada);
}

void CampoCadena::eliminarDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return;
    }
    else
        datos.eliminarElementoPos(pos);
}
