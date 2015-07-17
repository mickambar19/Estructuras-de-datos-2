#ifndef PILA_H
#define PILA_H
#include "ListaLigada.h"
template <class T>
class Pila: public ListaSimple<T>{
 public:
    Pila();
    void push(NodoArbol<T>* e);
    NodoArbol<T> *pop();
    T top();
};
template<class T>
Pila<T>::Pila()
{

}
template<class T>
void Pila<T>::push(NodoArbol<T> *e){
 this->insertOneBefore(e,this->first());
 }

 template<class T>
NodoArbol<T>* Pila<T>::pop(){
 NodoArbol<T>* cima;
 if(this->first()!=NULL){
     cima=this->first()->getData();
     this->delete_e(this->first());
 }
     return cima;
 }

template<class T>
T Pila<T>::top(){
 T cima;
 cima=this->first()->getData()->getElemento();
 return cima;
 }
#endif // PILA_H
