#ifndef VINO2_H
#define VINO2_H
#include "leerentero.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#define MAX 35
using namespace std;
class Vino
{
   public:
    char codigo[MAX],descripcion[MAX],origen[MAX];
    char casa[MAX],color[MAX],transparencia[MAX];
    char aroma[MAX],cuerpo[MAX],anio[MAX];
    void genera();
    void dispersion();
    void capturar();
    void mostrar();
    void modificar(char bus[MAX]);
    void eliminar(char bus[MAX]);
    void mostrar_porcasa(char bus[MAX]);
    void mostrar_poranio(char bus[MAX]);
}x;
char llave[MAX];
long int d_base,pos;
int cont=0;
void Vino::dispersion()
{
    int j=0,a;
    d_base=0;
    a=strlen(llave);
    while(j<a)
    {
        d_base=d_base+(100*llave[j])+(llave[j+1]%84645);
        j=j+2;
    }
    d_base=d_base%100;
}

void Vino:: genera()
{
    int j,i;
    ofstream a("dispersa.txt",ios::app);
    for(i=0;i<100;i++)
    {
        a.write((char*)& cont,sizeof(int));
        for(j=0;j<3;j++)
        {
            a.write((char*)&x,sizeof(x));
        }
    }
    a.close();
}


void Vino::capturar()
{
    long int aux2;
   cout<<"dame el codigo\n";
   fflush(stdin);
   cin.getline(codigo,MAX);
   cout<<"dame el descripcion\n";
   cin.getline(descripcion,MAX);
   cout<<"dame el origen a asignar\n";
   cin.getline(origen,MAX);
   cout<<"dame el casa a asignar\n";
   cin.getline(casa,MAX);
   cout<<"dame el color a asignar\n";
   cin.getline(color,MAX);
   cout<<"dame el transparencia a asignar\n";
   cin.getline(transparencia,MAX);
   cout<<"dame el aroma a asignar\n";
   cin.getline(aroma,MAX);
   cout<<"dame el cuerpo a asignar\n";
   cin.getline(cuerpo,MAX);
   cout<<"dame el anio a asignar\n";
   cin.getline(anio,MAX);
   strcpy(llave,codigo);
   dispersion();
   fstream b("dispersa.txt",ios::in|ios::out);
   d_base=d_base*((sizeof(x)*3)+sizeof(int));
   b.seekg(d_base,ios::beg);
   b.read((char*)&cont,sizeof(int));
   cout<<"CONTADOR"<<cont<<endl;
   //getch();
   if(cont==3)
   {
       cout<<"NO HAY ESPACIO\n";
   }else
   {
       pos=d_base+(cont*sizeof(x))+sizeof(int);
       aux2=pos;
       b.seekp(pos,ios::beg);
       b.write((char*)&x,sizeof(x));
       cont++;
       pos=d_base;
       b.seekp(pos,ios::beg);
       b.write((char*)&cont,sizeof(int));
       cout<<"contador:"<<cont<<" de la llave, y la direccion es: "<<aux2<<endl;
       //getch();
   }
   b.close();
}
void Vino::mostrar()
{
    int i;
    pos=0;
    ifstream a("dispersa.txt");
    if(!a.good())
    {
        cout<<"NO EXISTE TU ARCHIVO\n";
    }else
    {
        while(!a.eof())
        {
            a.seekg(pos,ios::beg);
            a.read((char*)&cont,sizeof(int));
            if(cont==0)
            {
                pos=pos+(3*sizeof(x))+sizeof(int);
            }else
            {
                for(i=0;i<cont;i++)
                {
                    a.read((char*)&x,sizeof(x));
                    cout<<"codigo       :"<<x.codigo<<endl<<"descripcion  :"<<x.descripcion<<endl<<"origen       :"<<x.origen<<endl;
                    cout<<"casa         :"<<x.casa  <<endl<<"color        :"<<x.color      <<endl<<"transparencia:"<<x.transparencia<<endl;
                    cout<<"aroma        :"<<x.aroma <<endl<<"cuerpo       :"<<x.cuerpo     <<endl<<"anio         :"<<x.anio<<endl;
                }
                pos=pos+(3*sizeof(x))+sizeof(int);
            }
        }
    }
    a.close();
}

void Vino::eliminar(char bus[])
{
    long int posicion,posicion2;
    char otro_campo[MAX];
    int i;
    strcpy(llave,bus);
    dispersion();
    fstream b("dispersa.txt",ios::in|ios::out);
    d_base=d_base*((sizeof(x)*3)+sizeof(int));
    b.seekg(d_base,ios::beg);
    b.read((char*)&cont,sizeof(int));
    cout<<"CONTADOR "<<cont<<endl;
    //getch();
    if(cont==0)
    {
        cout<<"NO EXISTE UN ELEMENTO DE CON ESE codigo\n";
    }else
    {
        cout<<"Ingresa el descripcion del VINO:\n";
        cin.getline(otro_campo,MAX);
        for(i=0;i<cont;i++)
        {
            b.read((char*)&x,sizeof(x));
            if(strcmp(x.descripcion,otro_campo)==0){

                while(i<cont){
                    posicion=b.tellp();
                    posicion=posicion-sizeof(x);
                    b.read((char*)&x,sizeof(x));
                    b.seekp(posicion,ios::beg);
                    b.write((char*)&x,sizeof(x));
                    posicion2=b.tellp();
                    posicion2=posicion2+sizeof(x);
                    b.seekg(posicion2,ios::beg);
                    i++;
                }
                cont=cont-1;
            }
        }
        //getch();
    }
    b.seekp(d_base,ios::beg);
    b.write((char*)&cont,sizeof(int));
    b.close();
}

void Vino::modificar(char bus[])
{
    long int posicion,posicion2,aux2;
    char otro_campo[MAX];
    int i;
    Vino aux;
    strcpy(llave,bus);
    dispersion();
    fstream b("dispersa.txt",ios::in|ios::out);
    d_base=d_base*((sizeof(x)*3)+sizeof(int));
    b.seekg(d_base,ios::beg);
    b.read((char*)&cont,sizeof(int));
    cout<<"CONTADOR "<<cont<<endl;
    //getch();
    if(cont==0)
    {
        cout<<"NO EXISTE UN ELEMENTO DE CON ESE codigo\n";
    }else
    {
        cout<<"Ingresa el descripcion del VINO:\n";
        cin.getline(otro_campo,MAX);
        for(i=0;i<cont;i++)
        {
            b.read((char*)&x,sizeof(x));
            if(strcmp(x.descripcion,otro_campo)==0){
                aux=x;
                while(i<cont){
                    posicion=b.tellp();
                    posicion=posicion-sizeof(x);
                    b.read((char*)&x,sizeof(x));
                    b.seekp(posicion,ios::beg);
                    b.write((char*)&x,sizeof(x));
                    posicion2=b.tellp();
                    posicion2=posicion2+sizeof(x);
                    b.seekg(posicion2,ios::beg);
                    i++;
                }
                cont=cont-1;
            }
        }
        //getch();
    }
    b.seekp(d_base,ios::beg);
    b.write((char*)&cont,sizeof(int));
    cout<<"codigo       :"<<aux.codigo<<endl<<"descripcion  :"<<aux.descripcion<<endl<<"origen       :"<<aux.origen<<endl;
    cout<<"casa         :"<<aux.casa  <<endl<<"color        :"<<aux.color      <<endl<<"transparencia:"<<aux.transparencia<<endl;
    cout<<"aroma        :"<<aux.aroma <<endl<<"cuerpo       :"<<aux.cuerpo     <<endl<<"anio         :"<<aux.anio<<endl;
    cout<<"Que deseas modificar:\n";
    cout<<"1.-codigo\n";
    cout<<"2.-descripcion\n";
    cout<<"3.-origen\n";
    cout<<"4.-casa\n";
    cout<<"5.-color\n";
    cout<<"6.-transparencia\n";
    cout<<"7.-aroma\n";
    cout<<"8.-cuerpo\n";
    i=leer_int();
    switch (i) {
    case 1:
        cout<<"Escribe el codigo\n";
        cin.getline(aux.codigo,MAX);
        break;
    case 2:
        cout<<"Escribe el descripcion\n";
        cin.getline(aux.descripcion,MAX);
        break;
    case 3:
        cout<<"Escribe el origen a asignar\n";
        cin.getline(aux.origen,MAX);
        break;
    case 4:
        cout<<"Escribe el casa a asignar\n";
        cin.getline(aux.casa,MAX);
        break;
    case 5:
        cout<<"Escribe el color a asignar\n";
        cin.getline(aux.color,MAX);
        break;
    case 6:
        cout<<"Escribe el transparencia a asignar\n";
        cin.getline(aux.transparencia,MAX);
        break;
    case 7:
        cout<<"Escribe el aroma a asignar\n";
        cin.getline(aux.aroma,MAX);
        break;
    case 8:
        cout<<"Escribe el cuerpo a asignar\n";
        cin.getline(aux.cuerpo,MAX);
        break;
    case 9:
        cout<<"Escribe el anioo a asignar\n";
        cin.getline(aux.anio,MAX);
        break;
    default:
        break;
    }
    strcpy(llave,aux.codigo);
    dispersion();
    d_base=d_base*((sizeof(x)*3)+sizeof(int));
    b.seekg(d_base,ios::beg);
    b.read((char*)&cont,sizeof(int));
    cout<<"CONTADOR"<<cont<<endl;
    //getch();
    if(cont==3)
    {
        cout<<"NO HAY ESPACIO\n";
    }else
    {
        pos=d_base+(cont*sizeof(x))+sizeof(int);
        aux2=pos;
        b.seekp(pos,ios::beg);
        b.write((char*)&aux,sizeof(x));
        cont++;
        pos=d_base;
        b.seekp(pos,ios::beg);
        b.write((char*)&cont,sizeof(int));
        cout<<"contador:"<<cont<<" de la llave, y la direccion es: "<<aux2<<endl;
        //getch();
    }
    b.close();
}
void Vino::mostrar_poranio(char bus[])
{
    int i;
    pos=0;
    ifstream a("dispersa.txt");
    if(!a.good())
    {
        cout<<"NO EXISTE TU ARCHIVO\n";
    }else
    {
        while(!a.eof())
        {
            a.seekg(pos,ios::beg);
            a.read((char*)&cont,sizeof(int));
            if(cont==0)
            {
                pos=pos+(3*sizeof(x))+sizeof(int);
            }else
            {
                for(i=0;i<cont;i++)
                {
                    a.read((char*)&x,sizeof(x));
                    if(strcmp(x.anio,bus)==0){
                        cout<<"codigo       :"<<x.codigo<<endl<<"descripcion  :"<<x.descripcion<<endl<<"origen       :"<<x.origen<<endl;
                        cout<<"casa         :"<<x.casa  <<endl<<"color        :"<<x.color      <<endl<<"transparencia:"<<x.transparencia<<endl;
                        cout<<"aroma        :"<<x.aroma <<endl<<"cuerpo       :"<<x.cuerpo     <<endl<<"anio         :"<<x.anio<<endl;
                    }
                }
                pos=pos+(3*sizeof(x))+sizeof(int);
            }
        }
    }
    a.close();
}
void Vino::mostrar_porcasa(char bus[])
{
    int i;
    pos=0;
    ifstream a("dispersa.txt");
    if(!a.good())
    {
        cout<<"NO EXISTE TU ARCHIVO\n";
    }else
    {
        while(!a.eof())
        {
            a.seekg(pos,ios::beg);
            a.read((char*)&cont,sizeof(int));
            if(cont==0)
            {
                pos=pos+(3*sizeof(x))+sizeof(int);
            }else
            {
                for(i=0;i<cont;i++)
                {
                    a.read((char*)&x,sizeof(x));
                    if(strcmp(x.casa,bus)==0){
                        cout<<"codigo       :"<<x.codigo<<endl<<"descripcion  :"<<x.descripcion<<endl<<"origen       :"<<x.origen<<endl;
                        cout<<"casa         :"<<x.casa  <<endl<<"color        :"<<x.color      <<endl<<"transparencia:"<<x.transparencia<<endl;
                        cout<<"aroma        :"<<x.aroma <<endl<<"cuerpo       :"<<x.cuerpo     <<endl<<"anio         :"<<x.anio<<endl;
                    }
                }
                pos=pos+(3*sizeof(x))+sizeof(int);
            }
        }
    }
    a.close();
}
#endif // VINO2_H
