#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED
#include <vector>
#include <utility>
#include <string>

using namespace std;


class Indice{
public:
    virtual void agregarAlIndice(string,int){return;};
    virtual void eliminarDelIndice(int){return;};
    virtual int buscar(string){return 0;};
    virtual ~Indice(){};
};

class IndiceEntero : public Indice{
    vector<pair<int,int>> index;
public:
    void agregarAlIndice(string,int);
    void eliminarDelIndice(int);
    int buscar(string);
};

class IndiceDecimal : public Indice{
    vector<pair<float,int>> index;
public:
    void agregarAlIndice(string,int);
    void eliminarDelIndice(int);
    int buscar(string);
};

class IndiceCadena : public Indice{
    vector<pair<string,int>> index;
public:
    void agregarAlIndice(string,int);
    void eliminarDelIndice(int);
    int buscar(string);
};
#endif // INDICE_H_INCLUDED
