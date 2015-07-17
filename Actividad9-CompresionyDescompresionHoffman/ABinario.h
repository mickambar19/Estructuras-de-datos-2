#ifndef ABINARIO_H
#define ABINARIO_H
#include <iostream>
#include "NodoArbol.h"
#include "ListaCodigos.h"
#include <cstdlib>
#include <string>
using namespace std;
ListaCodigos<Codigo> lcodigos;
template <class T>
class ABB{
    public:
        NodoArbol<T>* raiz;
        string enOrden_real(NodoArbol<T> *donde,string b);
    public:
        ABB();
        void inicializa();
        bool es_hoja(NodoArbol<T>* pos);
        void enOrden();
        void setRaiz(NodoArbol<T> *value);
};
template <class T>
void ABB<T>::setRaiz(NodoArbol<T> *value){
    raiz=value;
}
template <class T>
ABB<T>::ABB(){
    inicializa();}

    template <class T>
void ABB<T>::inicializa(){
    raiz=NULL;
    }
    template<class T>
void ABB<T>::enOrden(){
    string a;
   enOrden_real(raiz,a);
    }

    template<class T>
string ABB<T>::enOrden_real(NodoArbol<T> *donde,string b){
if(donde!=NULL){
       b=enOrden_real(donde->getIzq(),b+"0");

       if(es_hoja(donde)){
           Codigo codigo;
           codigo.setCod(b);
           codigo.setLetra(donde->getElemento());
           lcodigos.insertOneBefore(codigo,lcodigos.first());
       }
       b=enOrden_real(donde->getDer(),b+"1");
}
if(b.length()>=1){b.erase(b.end()-1);}
return b;
}

    template<class T>
bool ABB<T>::es_hoja(NodoArbol<T>* pos){
    if(pos->getDer()==NULL && pos->getIzq()==NULL) return true;
    else return false;
}
#endif // ABINARIO_H
