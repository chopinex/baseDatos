#include "lista.h"
#include <iostream>
#include <string>
using namespace std;

template<class T>
Elemento<T>::Elemento(T d){
    dato=d;
    siguiente=0;
}
template Elemento<int>::Elemento(int);
template Elemento<string>::Elemento(string);

template<class T>
T Elemento<T>::getElemento(){
    return dato;
}
template int Elemento<int>::getElemento();
template string Elemento<string>::getElemento();

template<class T>
Elemento<T>* Elemento<T>::getSiguiente(){
    return siguiente;
}
template Elemento<int>* Elemento<int>::getSiguiente();
template Elemento<string>* Elemento<string>::getSiguiente();

template<class T>
void Elemento<T>::setSiguiente(Elemento<T> *elem){
    siguiente=elem;
}
template void Elemento<int>::setSiguiente(Elemento*);
template void Elemento<string>::setSiguiente(Elemento*);

//----------------------------Lista------------------------------------
template<class T>
ListaEnlazada<T>::ListaEnlazada(){
    cabeza=0;
    actual=cabeza;
    tamanyo=0;
}
template ListaEnlazada<int>::ListaEnlazada();
template ListaEnlazada<string>::ListaEnlazada();

template<class T>
ListaEnlazada<T>::~ListaEnlazada(){
    while(cabeza){
        actual=cabeza;
        cabeza=cabeza->getSiguiente();
        delete actual;
    }
    actual=0;
}
template ListaEnlazada<int>::~ListaEnlazada();
template ListaEnlazada<string>::~ListaEnlazada();

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
    tamanyo++;
}
template void ListaEnlazada<int>::agregarElemento(int,int);
template void ListaEnlazada<string>::agregarElemento(int,string);

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
template string ListaEnlazada<string>::obtenerElemento(int);

template<class T>
void ListaEnlazada<T>::eliminarElemento(T elem){
    if(cabeza==0)
        return;
    actual=cabeza;
    if(actual->getElemento()==elem){
        cabeza=actual->getSiguiente();
        delete actual;
        actual=cabeza;
        tamanyo--;
        return;
    }
    Elemento<T> *aux;
    aux=actual->getSiguiente();
    while(aux!=0){
        if(aux->getElemento()==elem){
            actual->setSiguiente(aux->getSiguiente());
            delete aux;
            tamanyo--;
            return;
        }
        else{
            actual=aux;
            aux=aux->getSiguiente();
        }
    }
}
template void ListaEnlazada<int>::eliminarElemento(int);
template void ListaEnlazada<string>::eliminarElemento(string);

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
template void ListaEnlazada<string>::recorrerLista();

template<class T>
int ListaEnlazada<T>::getTamanyo(){
    return tamanyo;
}
template int ListaEnlazada<int>::getTamanyo();
template int ListaEnlazada<string>::getTamanyo();

template<class T>
void ListaEnlazada<T>::agregarElementoInicio(T elem){
    agregarElemento(0,elem);
}
template void ListaEnlazada<int>::agregarElementoInicio(int);
template void ListaEnlazada<string>::agregarElementoInicio(string);

template<class T>
void ListaEnlazada<T>::agregarElementoFin(T elem){
    agregarElemento(tamanyo,elem);
}
template void ListaEnlazada<int>::agregarElementoFin(int);
template void ListaEnlazada<string>::agregarElementoFin(string);
