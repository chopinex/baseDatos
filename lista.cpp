#include "lista.h"
#include <iostream>
using namespace std;

template<class T>
Elemento<T>::Elemento(T d){
    dato=d;
    siguiente=0;
}
template Elemento<int>::Elemento(int);

template<class T>
T Elemento<T>::getElemento(){
    return dato;
}
template int Elemento<int>::getElemento();

template<class T>
Elemento<T>* Elemento<T>::getSiguiente(){
    return siguiente;
}
template Elemento<int>* Elemento<int>::getSiguiente();

template<class T>
void Elemento<T>::setSiguiente(Elemento<T> *elem){
    siguiente=elem;
}
template void Elemento<int>::setSiguiente(Elemento*);

//----------------------------Lista------------------------------------
template<class T>
ListaEnlazada<T>::ListaEnlazada(){
    cabeza=0;
    actual=cabeza;
}
template ListaEnlazada<int>::ListaEnlazada();

template<class T>
ListaEnlazada<T>::~ListaEnlazada(){
    Elemento<T> *aux;
    while(cabeza){
        aux=cabeza;
        cabeza=cabeza->getSiguiente();
        delete aux;
    }
    actual=0;
}
template ListaEnlazada<int>::~ListaEnlazada();

template <class T>
void ListaEnlazada<T>::agregarElemento(int pos,T elem){
    actual=cabeza;
    if(pos==0){
        cabeza=new Elemento<T>(elem);
        cabeza->setSiguiente(actual);
        actual=cabeza;
    }
    else{
        for(int i=0;i<pos-1;i++){
            if(actual->getSiguiente()==0)
                break;
            else
                actual=actual->getSiguiente();
        }
        Elemento<T> *aux=actual->getSiguiente();
        Elemento<T> *nuevo= new Elemento<T>(elem);
        actual->setSiguiente(nuevo);
        nuevo->setSiguiente(aux);
        actual=nuevo;
    }
}
template void ListaEnlazada<int>::agregarElemento(int,int);

template<class T>
T ListaEnlazada<T>::obtenerElemento(int pos){
    if(cabeza==0)
        return 0;
    actual=cabeza;
    for(int i=0;i<pos;i++){
        if(actual->getSiguiente()==0)
            break;
        else
            actual=actual->getSiguiente();
    }
    if(actual==0)
        return 0;
    else
        return actual->getElemento();
}
template int ListaEnlazada<int>::obtenerElemento(int);

template<class T>
void ListaEnlazada<T>::eliminarElemento(T elem){
    if(cabeza==0)
        return;
    Elemento<T> *aux;
    aux=cabeza;
    if(aux->getElemento()==elem){
        cabeza=aux->getSiguiente();
        delete aux;
        actual=cabeza;
        return;
    }
    actual=cabeza;
    aux=actual->getSiguiente();
    while(aux!=0){
        if(aux->getElemento()==elem){
            actual->setSiguiente(aux->getSiguiente());
            delete aux;
            return;
        }
        else{
            actual=aux;
            aux=aux->getSiguiente();
        }
    }
}
template void ListaEnlazada<int>::eliminarElemento(int);

template<class T>
void ListaEnlazada<T>::recorrerLista(){
    actual=cabeza;
    while(actual!=0){
        cout<<actual->getElemento()<<" - ";
        actual=actual->getSiguiente();
    }
    cout<<endl;
}
template void ListaEnlazada<int>::recorrerLista();

template<class T>
void ListaEnlazada<T>::agregarElementoInicio(T elem){
    agregarElemento(0,elem);
}
template void ListaEnlazada<int>::agregarElementoInicio(int);
