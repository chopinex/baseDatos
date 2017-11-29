#include<iostream>
#include<string>

#include "tablaVista.h"

void TablaVista::verCampos(const BaseDatos &bd){
    vistaCampos.vaciarLista();
    vistaCampos=bd.verCamposTabla(vistaCampos);
    cout<<"=========================================================="<<endl;
    cout<<"|            ESTRUCTURA TABLA "<<bd.nombreTabla()<<"                |"<<endl;
    cout<<"=========================================================="<<endl;
    for(int i=0;i<vistaCampos.getTamanyo();i++){
        cout<<"|      ";
        cout<<vistaCampos.obtenerElemento(i);
        cout<<"      |"<<endl;
    }
    cout<<"=========================================================="<<endl;
}

void TablaVista::verTabla(const BaseDatos &bd){
    vistaRegistros.vaciarLista();
    vistaRegistros=bd.verRegistrosTabla(vistaRegistros);
    cout<<"=========================================================="<<endl;
    cout<<"|                TABLA "<<bd.nombreTabla()<<"                |"<<endl;
    cout<<"=========================================================="<<endl;
    for(int i=0;i<vistaRegistros.getTamanyo();i++){
        cout<<"|      ";
        cout<<vistaRegistros.obtenerElemento(i);
        cout<<"      |"<<endl;
    }
}
void TablaVista::mostrarComandos(){
    cout<<"1. Ver Campos"<<endl<<"2. Agregar Campo"<<endl<<"3. Eliminar Campo"<<endl<<"4. Ver Tabla"<<endl<<"5. Insertar Registro"<<endl<<"6. Eliminar registro"<<endl<<"7. Buscar"<<endl<<"0. Salir"<<endl;
    cout<<endl<<"Escoger opcion: ";
    return;
}

void TablaVista::mensajeConfirmacion(const string &msg) const{
    cerr<<"TABLA DICE: "<<msg<<endl;
}

void TablaVista::mensajeEntrada(const string &msg) const{
    cout<<msg<<": ";
}
