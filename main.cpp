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
    le.recorrerLista();
    BaseDatos bd("estudiantes.bd");
    bd.mostrarTablas();*/
    string entrada,numero,flotante;
    cout<<"un nombre,numero, flotante:";
    cin>>entrada>>numero>>flotante;
    CampoCadena nombre("nombre",false,false);
    nombre.agregarDato(entrada);
    CampoEntero edad("edad",false,false);
    edad.agregarDato(numero);
    CampoDecimal sueldo("sueldo",false,false);
    sueldo.agregarDato(flotante);
    Tabla persona("Persona");
    persona.insertarCampo(nombre);
    persona.insertarCampo(edad);
    persona.insertarCampo(sueldo);
    persona.verCampos();
    return 0;
}
