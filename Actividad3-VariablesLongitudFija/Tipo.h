#ifndef TIPO_H
#define TIPO_H
#define MAX 50
#include <fstream>
#include <iostream>
#include <cstring>
#include "leerentero.h"
using namespace std;
class Tipo
{
  private:
    char tipo[MAX];
  public:
    void capturar();
    void mostrar();
    bool buscar(char abus[MAX]);
}objeto;

void Tipo::capturar()
{
    cout<<"Ingresa el nuevo tipo:\n";
    cin.getline(tipo,MAX);
    ofstream esc("Tipos.txt",ios::app);
    esc.write((char *)&objeto,sizeof(objeto));
    esc.close();
}
void Tipo::mostrar()
{
    ifstream lee("Tipos.txt");
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof()){
        lee.read((char *)&objeto,sizeof(objeto));
        if(lee.eof()) break;
        cout<<"Tipo: "<<tipo<<endl;
        }
    }

    lee.close();
}
bool Tipo::buscar(char abus[MAX])
{   bool existe=false;
    ifstream lee("Tipos.txt");
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof()){
        lee.read((char *)&objeto,sizeof(objeto));
        if(lee.eof()) break;
        if(strcmp(abus,tipo)==0)
        {

            existe=true;

        };

        }
    }

    lee.close();

    return existe;
}


#endif // TIPO_H



