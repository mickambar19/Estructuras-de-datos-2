#ifndef INDICE_H
#define INDICE_H
#define MAX 20
#include <fstream>
#include <iostream>
#include <cstring>
#include "leerentero.h"
using namespace std;

class Indice
{
  public:
    char llave[MAX];
    char codigo[MAX];
    long int posicion;
 public:
    bool buscar(char bus[MAX]);
    bool operator==(const Indice &a);
    bool operator<(const Indice &a);
    bool operator>(const Indice &a);
    bool operator<=(const Indice &a);
    friend ostream&operator<<(ostream& os,Indice &a);
}indice;
bool Indice::buscar(char bus[])
{
    bool existe=false;
    ifstream leer("Indice.txt");
    if(!leer.good())
    {
        cout<<"EL DOCUMENTO DE INDICE ESTA VACIO\n";
    }
    else
    {
        while(!leer.eof())
        {
            leer.read((char *)&indice,sizeof(indice));
            if(strcmp(indice.llave,bus)==0)
            {
                existe=true;
            }
            if(leer.eof())break;
        }
    }
    leer.close();
    return existe;
}

bool Indice::operator==(const Indice &a){
    string obj1,obj2;
    obj1=llave;
    obj2=a.llave;
     return obj1==obj2;
    }
bool Indice::operator<(const Indice &a){
    string obj1,obj2;
    obj1=llave;
     obj2=a.llave;
    return obj1<obj2;
    }
bool Indice::operator>(const Indice &a){
    string obj1,obj2;
    obj1=llave;
     obj2=a.llave;
    return obj1>obj2;
    }
bool Indice::operator<=(const Indice &a){
    string obj1,obj2;
    obj1=llave;
     obj2=a.llave;
    return obj1<=obj2;
    }
ostream& operator<<(ostream& os,Indice &a){
       os<<"-----------------\n";
       os<<"Posicion    :"<<a.posicion<<endl;
       os<<"Llave    :"<<a.llave<<endl;
       os<<"-----------------\n\n";
    return os;
    }

#endif // INDICE_H

