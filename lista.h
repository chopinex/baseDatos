#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <class T>
class Elemento{
    T dato;
    Elemento *siguiente;

public:
    Elemento(T);
    T getElemento();
    Elemento* getSiguiente();
    void setSiguiente(Elemento*);
};

template <class T>
class ListaEnlazada{
    Elemento<T> *cabeza;
    Elemento<T> *actual;
    int tamanyo;

public:
    ListaEnlazada();
    ~ListaEnlazada();
    void agregarElemento(int,T);
    T obtenerElemento(int);
    void eliminarElemento(T);
    void recorrerLista();
    int getTamanyo();
    void agregarElementoInicio(T);
    void agregarElementoFin(T);
};

#endif // LISTA_H_INCLUDED
