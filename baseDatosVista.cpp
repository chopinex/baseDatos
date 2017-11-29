#include <iostream>
#include <string>
#include "baseDatosVista.h"
#include "lista.h"

using namespace std;

void BaseDatosVista::mostrarTablas(const BaseDatos &bd){
    vistaTablas.vaciarLista();
    vistaTablas=bd.getNombreTablas(vistaTablas);
    cout<<"=========================================================="<<endl;
    cout<<"|                       TABLAS                           |"<<endl;
    cout<<"=========================================================="<<endl;
    for(int i=0;i<vistaTablas.getTamanyo();i++){
        cout<<"|      ";
        cout<<vistaTablas.obtenerElemento(i);
        cout<<"      |"<<endl;
    }
    cout<<"=========================================================="<<endl;
}

void BaseDatosVista::mostrarComandos() const{
    cout<<"1. Ver Tablas"<<endl<<"2. Usar Tabla"<<endl<<"3. Agregar Tabla"<<endl<<"4. Eliminar Tabla"<<endl<<"0. Salir"<<endl;
    cout<<endl<<"Escoger opcion: ";
    return;
}

void BaseDatosVista::mensajeConfirmacion(const string &msg) const{
    cerr<<"BASE DATOS DICE: "<<msg<<endl;
}

void BaseDatosVista::mensajeEntrada(const string &msg) const{
    cout<<msg<<": ";
}
