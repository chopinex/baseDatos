#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "indice.h"

using namespace std;

void IndiceEntero::agregarAlIndice(string dato,int pos){
    index.push_back(make_pair(atoi(dato.c_str()),pos));
    sort(index.begin(),index.end());
}

void IndiceEntero::eliminarDelIndice(int pos){
    for (typename vector<pair<int,int>>::iterator it = index.begin();it!=index.end();it++){
        if(it->second==pos){
            index.erase(it);
            return;
        }
    }
    cerr<<"dato no encontrado"<<endl;
}

int IndiceEntero::buscar(const string dato){
    struct comparacion{
        bool operator()(const pair<int,int> izq, const int& der)
        const { return izq.first< der; }

        bool operator()(const int& izq, const pair<int,int> der)
        const { return izq<der.first;}
    };

    typename vector<pair<int,int>>::iterator par;
    par=lower_bound(index.begin(),index.end(),atoi(dato.c_str()),comparacion());
     return par->second;
}

void IndiceDecimal::agregarAlIndice(string dato,int pos){
    index.push_back(make_pair(atof(dato.c_str()),pos));
    sort(index.begin(),index.end());
}

void IndiceDecimal::eliminarDelIndice(int pos){
    for (typename vector<pair<float,int>>::iterator it = index.begin();it!=index.end();it++){
        if(it->second==pos){
            index.erase(it);
            return;
        }
    }
    cerr<<"dato no encontrado"<<endl;
}

int IndiceDecimal::buscar(const string dato){
    struct comparacion{
        bool operator()(const pair<float,int> izq, const float& der)
        const { return izq.first< der; }

        bool operator()(const float& izq, const pair<float,int> der)
        const { return izq<der.first;}
    };

    typename vector<pair<float,int>>::iterator par;
    par=lower_bound(index.begin(),index.end(),atof(dato.c_str()),comparacion());
     return par->second;
}

void IndiceCadena::agregarAlIndice(string dato,int pos){
    index.push_back(make_pair(dato,pos));
    sort(index.begin(),index.end());
}

void IndiceCadena::eliminarDelIndice(int pos){
    for (typename vector<pair<string,int>>::iterator it = index.begin();it!=index.end();it++){
        if(it->second==pos){
            index.erase(it);
            return;
        }
    }
    cerr<<"dato no encontrado"<<endl;
}

int IndiceCadena::buscar(const string dato){
    struct comparacion{
        bool operator()(const pair<string,int> izq, const string& der)
        const { return izq.first< der; }

        bool operator()(const string& izq, const pair<string,int> der)
        const { return izq<der.first;}
    };

    typename vector<pair<string,int>>::iterator par;
    par=lower_bound(index.begin(),index.end(),dato,comparacion());
     return par->second;
}
