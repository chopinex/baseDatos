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
    persona.insertarCampo("nombre","cadena",true,false);
    persona.insertarCampo("edad","entero",false,false);
    persona.insertarCampo("sueldo","decimal",false,false);
    persona.verCampos();
    ListaEnlazada<string> le;
    le.agregarElementoFin("Jose");
    le.agregarElementoFin("33");
    le.agregarElementoFin("0.4");
    persona.insertarRegistro(le);

    ListaEnlazada<string> le2;
    le2.agregarElementoFin("Juan");
    le2.agregarElementoFin("20");
    le2.agregarElementoFin("2.4");
    persona.insertarRegistro(le2);

    ListaEnlazada<string> le3;
    le3.agregarElementoFin("Pedro");
    le3.agregarElementoFin("45");
    le3.agregarElementoFin("4.6");
    persona.insertarRegistro(le3);
    //persona.camposTabla.obtenerElemento(0);
    persona.leerRegistro(1).recorrerLista();
    string buscar;
    cout<<"buscar nombre: ";
    cin>>buscar;
    ListaEnlazada<string> resultado;
    resultado=persona.buscarRegistro(buscar);
    resultado.recorrerLista();
    return 0;
}
