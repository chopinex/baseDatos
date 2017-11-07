#include "basedatos.h"
#include <fstream>
#include <iostream>
#include <string>
#include "lista.h"
using namespace std;

BaseDatos::BaseDatos(const char* na){
    nombreArchivo=na;
    ifstream salida(nombreArchivo);
    if (!salida){
        ofstream archivo(nombreArchivo);
        archivo.close();
        cerr << "Archivo creado" << endl;
    }
    string nombreTabla;
    while(salida>>nombreTabla)
        tablas.agregarElementoFin(nombreTabla);
    salida.close();
}

void BaseDatos::mostrarTablas(){
    tablas.recorrerLista();
}

void BaseDatos::crearTabla(string tabla){
    tablas.agregarElementoFin(tabla);
}

void BaseDatos::eliminarTabla(string tabla){
    tablas.eliminarElemento(tabla);
}
