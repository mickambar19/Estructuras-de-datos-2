#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "Letra.h"
using namespace std;
template<class T>
class NodoArbol{
public:
    T elemento;
    NodoArbol<T>* der;
    NodoArbol<T>* izq;
public:
    NodoArbol(T elemento);
    NodoArbol(NodoArbol<T>* a,T elemento,NodoArbol<T>* b);
    T getElemento() const;
    void setElemento(const T &value);
    NodoArbol<T> *getDer() const;
    void setDer(NodoArbol<T> *value);
    NodoArbol<T> *getIzq() const;
    void setIzq(NodoArbol<T> *value);
};

template <class T>
NodoArbol<T>::NodoArbol(T elemento)
{
    this->elemento=elemento;
    der=izq=NULL;
}

template <class T>
NodoArbol<T>::NodoArbol(NodoArbol<T> *a, T elemento, NodoArbol<T> *b)
{
    this->elemento=elemento;
    izq=a;
    der=b;
}

template <class T>
T NodoArbol<T>::getElemento() const
{
    return elemento;
}

template <class T>
void NodoArbol<T>::setElemento(const T &value)
{
    elemento = value;
}

template <class T>
NodoArbol<T> *NodoArbol<T>::getDer() const
{
return der;
}

template <class T>
void NodoArbol<T>::setDer(NodoArbol<T> *value)
{
der = value;
}

template <class T>
NodoArbol<T> *NodoArbol<T>::getIzq() const
{
return izq;
}

template <class T>
void NodoArbol<T>::setIzq(NodoArbol<T> *value)
{
izq = value;
}
#endif // NODOARBOL_H
