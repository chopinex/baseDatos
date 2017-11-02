#include "lista.h"
#include <iostream>

using namespace std;

int main()
{
    ListaEnlazada<int> le;
    le.agregarElementoInicio(3);
    le.agregarElementoInicio(5);
    le.agregarElemento(1,6);
    le.recorrerLista();
    cout<<le.obtenerElemento(2)<<endl;
    le.eliminarElemento(5);
    le.recorrerLista();
    return 0;
}
