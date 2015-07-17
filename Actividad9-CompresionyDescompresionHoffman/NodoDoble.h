#ifndef NODODOBLE_H
#define NODODOBLE_H
#include "NodoArbol.h"
template <class T>
class NodoDoble{
private:
   NodoArbol<T>* elemento;
   NodoDoble<T>* anterior;
   NodoDoble<T>* siguiente;
   int posn;
public:
    NodoDoble(NodoArbol<T>* elemento);
    NodoDoble(NodoDoble<T>* a,NodoArbol<T>* elemento,NodoDoble<T>* d);
    void setData(NodoArbol<T>* a);
    void setPrev(NodoDoble<T>* a);
    void setNext(NodoDoble<T>* a);
    NodoArbol<T>* getData();
    NodoDoble<T>* getPrev();
    NodoDoble<T>* getNext();
    int getPosn();
    void setposn(int value);
};

template <class T>
int NodoDoble<T>::getPosn()
{
    return posn;
}
template <class T>
void NodoDoble<T>::setposn(int value)
{
    posn = value;
}

template <class T>
NodoDoble<T>::NodoDoble(NodoArbol<T> *elemento){
   this->elemento=elemento;
  siguiente=anterior=NULL;}

template <class T>
NodoDoble<T>::NodoDoble(NodoDoble<T>* a, NodoArbol<T> *elemento, NodoDoble<T>* d){
   this->elemento=elemento;
   siguiente=d;
   anterior=a;
}

template <class T>
NodoArbol<T> *NodoDoble<T>::getData(){
    return elemento;}
template <class T>
void NodoDoble<T>::setData(NodoArbol<T> *e){
    elemento=e;}

template <class T>
NodoDoble<T>* NodoDoble<T>::getNext(){
    return siguiente;
}

template <class T>
NodoDoble<T>* NodoDoble<T>::getPrev(){
    return anterior;}

template <class T>
void NodoDoble<T>::setNext(NodoDoble<T>* a){
     siguiente=a;}

template <class T>
void NodoDoble<T>::setPrev(NodoDoble<T>* a){
     anterior=a;}

#endif // NODODOBLE_H
