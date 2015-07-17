#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "NodoDoble.h"
#include <cstdlib>
template <class T>
class ListaSimple{
    private:
        NodoDoble<T>* primero;
        void quickSort(NodoDoble<T> **arr, int izq, int der);
    public:
        ListaSimple();
        void initialize();
        bool isEmpty();
        void printAll();
        NodoDoble<T>* first();
        NodoDoble<T>* last();
        NodoDoble<T>* getPrev(NodoDoble<T>* a);
        NodoDoble<T>* getNext(NodoDoble<T>* a);
        NodoDoble<T>* linealSearch(T elem);
        void order();
        void insertOneBefore(NodoArbol<T> *elem, NodoDoble<T>* a);
        void delete_e(NodoDoble<T>* a);
        void deleteAll();//anula

        };

template <class T>
ListaSimple<T>::ListaSimple(){
    initialize();}

    template <class T>
void ListaSimple<T>::initialize(){
    primero=NULL;
    }

    template <class T>
bool ListaSimple<T>::isEmpty(){
    NodoDoble<T>* n;
    n=primero;
    if(n==NULL){
    return true;
    }else return false;
    }

    template <class T>
void ListaSimple<T>::printAll(){
    int i=1;
    T e;
    NodoDoble<T>* n;
    n=primero;
    while(n!=NULL){
    e=n->getData()->getElemento();
    cout<<e<<endl;
    n=n->getNext();
    i++;
    }
    }


    template <class T>
NodoDoble<T>* ListaSimple<T>::linealSearch(T elem){
    NodoDoble<T>* p;
    T e;
    p=primero;
    while(p!=NULL){
    if(elem==p->getData()->getElemento()){
    e=p->getData()->getElemento();
    cout<<"te quedaste ciclado\n";
    return p;
    }
    p=p->getNext();
    }
    return NULL;
    }

    template <class T>
void ListaSimple<T>::delete_e(NodoDoble<T>* a){
    NodoDoble<T> *actual=a;
    NodoDoble<T> *anterior,*siguiente;
   if(!isEmpty()){
   if(actual==NULL){}
   else if(actual->getNext()==NULL && actual->getPrev()==NULL){
       delete a;
       primero=NULL;
   }else{
        siguiente=actual->getNext();
        anterior=actual->getPrev();
        if(siguiente!=NULL)siguiente->setPrev(anterior);
        if(anterior!=NULL) anterior->setNext(siguiente);
        if(actual==primero)primero=siguiente;
        delete actual;
        }}

    }

    template <class T>
void ListaSimple<T>::deleteAll(){
    NodoDoble<T> *anterior;
    if(!isEmpty()){
    while(primero!=NULL){
    anterior=primero;
    primero=primero->getNext();
    delete anterior->getData();
    delete anterior;
       }
     }
    }

    template <class T>
NodoDoble<T>* ListaSimple<T>::first(){
    return primero;
    }

    template <class T>
NodoDoble<T>* ListaSimple<T>::last(){
    NodoDoble<T>* n;
    n=primero;
    if(n==NULL){

    }
    else
    {
        while(n->getNext()!=NULL){
            n=n->getNext();
        }
    }
    return n;
    }

    template <class T>
NodoDoble<T>* ListaSimple<T>::getPrev(NodoDoble<T>* a){
     if(a==first()){
        return NULL;
     }else
        return a->getPrev();}

    template <class T>
NodoDoble<T>* ListaSimple<T>::getNext(NodoDoble<T>* a){
       if(a==last()){return NULL;}else
        return a->getNext();
    }

    template <class T>
void ListaSimple<T>::insertOneBefore(NodoArbol<T>* elem, NodoDoble<T>* a){
    NodoDoble<T>* nuevo,*aux;
    nuevo=new NodoDoble<T>(elem);
    if(a==NULL){
        primero=nuevo;
    }else if(a==primero){
        nuevo->setNext(primero);
        primero->setPrev(nuevo);
        primero=nuevo;
    }else{
    aux=getPrev(a);
    nuevo->setNext(a);
    a->setPrev(nuevo);
    if(aux!=NULL){
    aux->setNext(nuevo);}
    nuevo->setPrev(aux);
    }
    }

template <class T>
void ListaSimple<T>::order(){
    NodoDoble<T> **arr;
    NodoDoble<T> *p;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) return; // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new NodoDoble<T> *[contador];
    p=primero;
    contador=0;
    while(p!=NULL){
    arr[contador++]=p;
    p=p->getNext();
    }
    quickSort(arr,0,contador-1);
    primero=arr[0];
    for(g=0;g<=contador-1;g++){
        if(g==0){
            arr[g]->setPrev(NULL);
            arr[g]->setNext(arr[g+1]);
        }else if(g==contador-1){
            arr[g]->setNext(NULL);
            arr[g]->setPrev(arr[g-1]);
        }else{
            arr[g]->setNext(arr[g+1]);
            arr[g]->setPrev(arr[g-1]);
        }
    }
    delete arr;
    }

    template <class T>
void ListaSimple<T>::quickSort(NodoDoble<T> **arr, int izq, int der){
    int g,h,medio;
    NodoDoble<T> *pivote,*aux;
    medio=(izq+der)/2;
    pivote=arr[medio];
    g=izq;
    h=der;
    while(g<=h){
    while(arr[g]->getData()->getElemento()<pivote->getData()->getElemento())g++;
    while(pivote->getData()->getElemento()<arr[h]->getData()->getElemento())h--;
    if(g<=h){
    aux=arr[g];
    arr[g]=arr[h];
    arr[h]=aux;
    g++;
    h--;
    }
    }
    if(izq<h)quickSort(arr,izq,h);
    if(g<der)quickSort(arr,g,der);
    }

#endif // LISTALIGADA_H
