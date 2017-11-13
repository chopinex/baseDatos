#include "campo.h"
#include <iostream>
#include <string>

using namespace std;

bool Campo::operator==(Campo c){
    if(nombre==c.getNombre()&&tipo==c.getTipo())
        return true;
    return false;
}

void CampoEntero::cambiarDato(int pos,int nuevoDato){
    datos.cambiarElemento(pos,nuevoDato);
}

int CampoEntero::verDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return 0;
    }
    else
        return datos.obtenerElemento(pos);
}

void CampoEntero::agregarDato(string entrada){
    int nuevoDato;
    if(nuevoDato=stoi(entrada))
        datos.agregarElementoFin(nuevoDato);
    else
        cerr<<"Tipo de dato incorrecto"<<endl;
}

int CampoEntero::numeroDatos(){
    return datos.getTamanyo();
}

void CampoDecimal::cambiarDato(int pos,float nuevoDato){
    datos.cambiarElemento(pos,nuevoDato);
}

float CampoDecimal::verDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return 0.0;
    }
    else
        return datos.obtenerElemento(pos);
}

void CampoDecimal::agregarDato(string entrada){
    float nuevoDato;
    if(nuevoDato=stof(entrada))
        datos.agregarElementoFin(nuevoDato);
    else
        cerr<<"Tipo de dato incorrecto"<<endl;
}

int CampoDecimal::numeroDatos(){
    return datos.getTamanyo();
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
    datos.agregarElementoFin(entrada);
}
