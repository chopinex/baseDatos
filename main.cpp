#include "clases.h"
#include <iostream>

using namespace std;

int main()
{
    ListaEnlazada<int> le;
    le.agregarElemento(0,3);
    le.agregarElemento(0,5);
    le.agregarElemento(1,6);
    le.recorrerLista();
    return 0;
}
