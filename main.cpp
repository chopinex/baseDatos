#include "lista.h"
#include "basedatos.h"
#include "campo.h"
#include "tabla.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*ListaEnlazada<string> le;
    le.agregarElementoFin("hola");
    le.agregarElementoInicio("mundo");
    le.agregarElemento(1,"c++");
    le.recorrerLista();
    cout<<le.obtenerElemento(2)<<endl;
    le.eliminarElemento("mundo");
    le.agregarElementoFin("Stroustrup");
    le.recorrerLista();
    le.cambiarElemento(0,"inicio");
    le.recorrerLista();*/
    BaseDatos bd("estudiantes.bd");
    bd.mostrarTablas();
    //string entrada,numero,flotante;
    //cout<<"un nombre,numero, flotante:";
    //cin>>entrada>>numero>>flotante;
    //nombre.agregarDato(entrada);
    //sueldo.agregarDato(flotante);
    Tabla persona("Persona");
    persona.insertarCampo("nombre","cadena",false,false);
    persona.insertarCampo("edad","entero",false,false);
    persona.insertarCampo("sueldo","decimal",false,false);
    persona.verCampos();
    ListaEnlazada<string> le;
    le.agregarElementoFin("Jose");
    le.agregarElementoInicio("33");
    le.agregarElemento(1,"0.4");
    persona.insertarRegistro(le);
    //persona.camposTabla.obtenerElemento(0);
    persona.leerRegistro(0).recorrerLista();
    return 0;
}
