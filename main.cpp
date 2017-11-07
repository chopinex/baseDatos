#include "lista.h"
#include "basedatos.h"
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
    le.recorrerLista();*/
    BaseDatos bd("estudiantes.bd");
    bd.mostrarTablas();
    return 0;
}
