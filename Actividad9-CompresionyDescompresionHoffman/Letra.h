#ifndef LETRA_H
#define LETRA_H
#define LETRA_H
#include <iostream>
using namespace std;
class Letra{
private:
    char letra;
    int num;
public:

    char getLetra() const;
    void setLetra(char value);
    int getNum() const;
    void setNum(int value);

};

int Letra::getNum() const
{
    return num;
}

void Letra::setNum(int value)
{
    num = value;
}
char Letra::getLetra() const
{
    return letra;
}

void Letra::setLetra(char value)
{
    letra = value;
}
bool operator<(const Letra &a,const Letra &b){
    if (a.getNum()==b.getNum()){
        return (a.getLetra()<b.getLetra());
    }else
        return a.getNum()<b.getNum();}
bool operator==(const Letra &a,const Letra &b){
    return (a.getLetra()==b.getLetra());}

bool operator>(const Letra &a,const Letra &b){
    if (a.getNum()==b.getNum()){
        return (a.getLetra()>b.getLetra());
    }else
        return a.getNum()>b.getNum();
}

ostream& operator << (ostream &o,const Letra &p){
    o<<"letra:"<<p.getLetra()<<"\n";
    o<<"veces:"<<p.getNum()<<"\n";
    o<<"_________\n";
    return o;
}
#endif // LETRA_H
