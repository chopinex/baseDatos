#include "campo.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

bool Campo::operator==(Campo c){
    if(nombre==c.getNombre()&&tipo==c.getTipo())
        return true;
    return false;
}

void CampoEntero::cambiarDato(int pos,string nuevoDato){
    datos.cambiarElemento(pos,atoi(nuevoDato.c_str()));
}

string CampoEntero::verDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return "";
    }
    else{
        char intStr[33];
        int dato=datos.obtenerElemento(pos);
        sprintf(intStr,"%d",dato);
        return string(intStr);
    }
}

void CampoEntero::agregarDato(string entrada){
    int nuevoDato;
    if((nuevoDato=atoi(entrada.c_str()))){
        //cout<<"Dato agregado"<<endl;
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
    datos.cambiarElemento(pos,atof(nuevoDato.c_str()));
}

string CampoDecimal::verDato(int pos){
    if(pos>=datos.getTamanyo()){
        cerr<<"Valor fuera de rango";
        return "";
    }
    else{
        char intStr[33];
        float dato=datos.obtenerElemento(pos);
        sprintf(intStr,"%f",dato);
        return string(intStr);
    }
}

void CampoDecimal::agregarDato(string entrada){
    float nuevoDato;
    if((nuevoDato=atof(entrada.c_str()))){
        //cout<<"Dato agregado"<<endl;
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
    //cout<<"Dato agregado"<<endl;
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
