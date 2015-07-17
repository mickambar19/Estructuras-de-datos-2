#ifndef NODOCODIGO_H
#define NODOCODIGO_H
#include "Codigo.h"
template <class T>
class NodoCodigo{
private:
   T elemento;
   NodoCodigo<T>* anterior;
   NodoCodigo<T>* siguiente;
   int posn;
public:
    NodoCodigo(T elemento);
    NodoCodigo(NodoCodigo<T>* a,T elemento,NodoCodigo<T>* d);
    void setData(T a);
    void setPrev(NodoCodigo<T>* a);
    void setNext(NodoCodigo<T>* a);
    T getData();
    NodoCodigo<T>* getPrev();
    NodoCodigo<T>* getNext();
    int getPosn();
    void setposn(int value);
};

template <class T>
int NodoCodigo<T>::getPosn()
{
    return posn;
}
template <class T>
void NodoCodigo<T>::setposn(int value)
{
    posn = value;
}

template <class T>
NodoCodigo<T>::NodoCodigo(T elemento){
   this->elemento=elemento;
  siguiente=anterior=NULL;}

template <class T>
NodoCodigo<T>::NodoCodigo(NodoCodigo<T>* a, T elemento, NodoCodigo<T>* d){
   this->elemento=elemento;
   siguiente=d;
   anterior=a;
}

template <class T>
T NodoCodigo<T>::getData(){
    return elemento;}
template <class T>
void NodoCodigo<T>::setData(T e){
    elemento=e;}

template <class T>
NodoCodigo<T>* NodoCodigo<T>::getNext(){
    return siguiente;
}

template <class T>
NodoCodigo<T>* NodoCodigo<T>::getPrev(){
    return anterior;}

template <class T>
void NodoCodigo<T>::setNext(NodoCodigo<T>* a){
     siguiente=a;}

template <class T>
void NodoCodigo<T>::setPrev(NodoCodigo<T>* a){
     anterior=a;}
#endif // NODOCODIGO_H
