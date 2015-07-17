#ifndef LISTACODIGOS_H
#define LISTACODIGOS_H
#include "NodoCodigo.h"
#include <cstdlib>
template <class T>
class ListaCodigos{
    private:
        NodoCodigo<T>* primero;
        void quickSort(NodoCodigo<T> **arr, int izq, int der);
    public:
        ListaCodigos();
        void initialize();
        bool isEmpty();
        void printAll();
        NodoCodigo<T>* first();
        NodoCodigo<T>* last();
        NodoCodigo<T>* getPrev(NodoCodigo<T>* a);
        NodoCodigo<T>* getNext(NodoCodigo<T>* a);
        NodoCodigo<T>* linealSearch(T elem);
        NodoCodigo<T>* linealSearch2(T elem);
        void order();
        void insertOneBefore(T elem, NodoCodigo<T>* a);
        void delete_e(NodoCodigo<T>* a);
        void deleteAll();//anula

        };

template <class T>
ListaCodigos<T>::ListaCodigos(){
    initialize();}

    template <class T>
void ListaCodigos<T>::initialize(){
    primero=NULL;
    }

    template <class T>
bool ListaCodigos<T>::isEmpty(){
    NodoCodigo<T>* n;
    n=primero;
    if(n==NULL){
    return true;
    }else return false;
    }

    template <class T>
void ListaCodigos<T>::printAll(){
    int i=1;
    T e;
    NodoCodigo<T>* n;
    n=primero;
    while(n!=NULL){
    e=n->getData();
    cout<<e<<endl;
    n=n->getNext();
    i++;
    }
    }


    template <class T>
NodoCodigo<T>* ListaCodigos<T>::linealSearch(T elem){
    NodoCodigo<T>* p;
    T e;
    p=primero;
    while(p!=NULL){
    if(elem==p->getData()){
    e=p->getData();
    return p;
    }
    p=p->getNext();
    }
    return NULL;
    }
template <class T>
NodoCodigo<T>* ListaCodigos<T>::linealSearch2(T elem){
    NodoCodigo<T>* p;
    T e;
    p=primero;
    while(p!=NULL){
        if(elem!=p->getData()){
            e=p->getData();
            cout<<e<<endl;
            return p;
        }
        p=p->getNext();
    }
    return NULL;
}

    template <class T>
void ListaCodigos<T>::delete_e(NodoCodigo<T>* a){
    NodoCodigo<T> *actual=a;
    NodoCodigo<T> *anterior,*siguiente;
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
void ListaCodigos<T>::deleteAll(){
    NodoCodigo<T> *anterior;
    if(!isEmpty()){
    while(primero!=NULL){
    anterior=primero;
    primero=primero->getNext();
    delete anterior;
       }
     }
    }

    template <class T>
NodoCodigo<T>* ListaCodigos<T>::first(){
    return primero;
    }

    template <class T>
NodoCodigo<T>* ListaCodigos<T>::last(){
    NodoCodigo<T>* n;
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
NodoCodigo<T>* ListaCodigos<T>::getPrev(NodoCodigo<T>* a){
     if(a==first()){
        return NULL;
     }else
        return a->getPrev();}

    template <class T>
NodoCodigo<T>* ListaCodigos<T>::getNext(NodoCodigo<T>* a){
       if(a==last()){return NULL;}else
        return a->getNext();
    }

    template <class T>
void ListaCodigos<T>::insertOneBefore(T elem, NodoCodigo<T>* a){
    NodoCodigo<T>* nuevo,*aux;
    nuevo=new NodoCodigo<T>(elem);
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
void ListaCodigos<T>::order(){
    NodoCodigo<T> **arr;
    NodoCodigo<T> *p;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) return; // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new NodoCodigo<T> *[contador];
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
void ListaCodigos<T>::quickSort(NodoCodigo<T> **arr, int izq, int der){
    int g,h,medio;
    NodoCodigo<T> *pivote,*aux;
    medio=(izq+der)/2;
    pivote=arr[medio];
    g=izq;
    h=der;
    while(g<=h){
    while(arr[g]->getData()<pivote->getData())g++;
    while(pivote->getData()<arr[h]->getData())h--;
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
#endif // LISTACODIGOS_H
