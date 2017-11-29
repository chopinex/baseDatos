#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <class T>
class Elemento{
    T dato;
    Elemento *siguiente;

public:
    Elemento(T);
    T getElemento();
    void setElemento(T);
    Elemento* getSiguiente();
    void setSiguiente(Elemento*);
};

template <class T>
class ListaEnlazada{
    mutable Elemento<T> *cabeza;
    mutable Elemento<T> *actual;
    int tamanyo;

public:
    ListaEnlazada();
    ~ListaEnlazada();
    void agregarElemento(int,T);
    T obtenerElemento(int) const;
    void eliminarElemento(T);
    void eliminarElementoPos(int);
    void cambiarElemento(int,T);
    void recorrerLista();
    int getTamanyo() const;
    void agregarElementoInicio(T);
    void agregarElementoFin(T);
    void vaciarLista();
};

#endif // LISTA_H_INCLUDED
