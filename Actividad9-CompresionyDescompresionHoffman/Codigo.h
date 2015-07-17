#ifndef CODIGO_H
#define CODIGO_H
#include <iostream>
#include <string>
#include "Letra.h"
using namespace std;

class Codigo{
private:
 string cod;
 Letra letra;
public:
 string getCod() const;
 void setCod(string value);
 Letra getLetra() const;
 void setLetra(Letra value);
};

Letra Codigo::getLetra() const
{
    return letra;
}

void Codigo::setLetra(Letra value)
{
    letra = value;
}
string Codigo::getCod() const
{
    return cod;
}

void Codigo::setCod(string value)
{
    cod = value;
}
bool operator<(const Codigo &a,const Codigo &b){
    return (a.getLetra()<b.getLetra());
}

bool operator>(const Codigo &a,const Codigo &b){
        return (a.getLetra()>b.getLetra());
}
bool operator==(const Codigo &a,const Codigo &b){
        return (a.getLetra()==b.getLetra());
}
bool operator!=(const Codigo &a,const Codigo &b){
        return (a.getCod()==b.getCod());
}
ostream& operator << (ostream &o,const Codigo &p){
    o<<"LETRA :\n"<<p.getLetra();
    o<<"Codigo:"<<p.getCod()<<"\n";
    o<<"...............\n";
    return o;
}
#endif // CODIGO_H
