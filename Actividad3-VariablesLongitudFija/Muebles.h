#ifndef MUEBLES_H
#define MUEBLES_H
#include "Tipo.h"

class Mueble
{
  public:
    char codigo[MAX],descripcion[MAX],precio[MAX];
    char existencia[MAX],color[MAX];
    char tipo[MAX];

  public:
    void capturar();
    void mostrar();
    bool buscar(char abus[MAX]);
    bool eliminar(char abus[MAX]);
    bool modificar(char abus[MAX]);
    bool mostrar_tipo(char abus[MAX]);
    bool ordenar_tipo();
}mueble;
void quicksort(int izq, int der,Mueble *elem);
void Mueble::capturar()
{

 ofstream esc("Muebles.txt",ios::app);
    cout<<"MENU NUEVO MUEBLE\n";
    cout<<"Ingresa el codigo:\n";
    cin.getline(codigo,MAX);
    cout<<"Ingresa la descripcion:\n";
    cin.getline(descripcion,MAX);
    cout<<"Ingresa el precio:\n";
    cin.getline(precio,MAX);
    cout<<"Ingresa la cantidad que existen:\n";
    cin.getline(existencia,MAX);
    cout<<"Ingresa el color:\n";
    cin.getline(color,MAX);
    cout<<"    Opciones para tipo de muebles:\n";
    objeto.mostrar();
    cout<<"Ingresa el tipo Mueble:\n";
    cin.getline(tipo,MAX);
    if(objeto.buscar(tipo)){
        esc.write((char *)&mueble,sizeof(mueble));
    }
    else
    {
        cout<<"No existe este tipo de mueble \n REGISTRA EL TIPO PRIMERO POR FAVOR :) \n\n";
    }
    esc.close();
}
void Mueble::mostrar()
{
    ifstream lee("Muebles.txt");
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof())
        {
        lee.read((char *)&mueble,sizeof(mueble));
        if(lee.eof()) break;
        cout<<"\nCodigo     : "<<codigo<<endl;
        cout<<"Descripcion: "<<descripcion<<endl;
        cout<<"Precio     : "<<precio<<endl;
        cout<<"Existencia : "<<existencia<<endl;
        cout<<"Color      : "<<color<<endl;
        cout<<"Tipo       : "<<tipo<<endl<<endl;
        }
    }

    lee.close();
}

bool Mueble::buscar(char abus[MAX])
{   bool existe=false;
    ifstream lee("Muebles.txt");
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof()){
        lee.read((char *)&mueble,sizeof(mueble));
        if(lee.eof()) break;
        if(strcmp(abus,codigo)==0)
        {
            cout<<"Codigo     : "<<codigo<<endl;
            cout<<"Descripcion: "<<descripcion<<endl;
            cout<<"Precio     : "<<precio<<endl;
            cout<<"Existencia : "<<existencia<<endl;
            cout<<"Color      : "<<color<<endl;
            cout<<"Tipo       : "<<tipo<<endl;

            existe=true;

        }

        }
    }

    lee.close();

    return existe;
}

bool Mueble::eliminar(char abus[MAX])
{
    bool existe=false;
    ifstream lee("Muebles.txt");
     ofstream esc("AuxM.txt",ios::app);
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof()){
        lee.read((char *)&mueble,sizeof(mueble));
        if(lee.eof()) break;
        if(strcmp(abus,codigo)==0)
        {
           existe=true;

        }else
        {

            esc.write((char *)&mueble,sizeof(mueble));

        }

        }
    }

    lee.close();
    esc.close();
    remove("Muebles.txt");
    rename("AuxM.txt","Muebles.txt");
    return existe;
}

bool Mueble::modificar(char abus[MAX])
{
    bool existe=false;
    ifstream lee("Muebles.txt");
    ofstream esc("AuxM.txt",ios::app);
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof()){
        lee.read((char *)&mueble,sizeof(mueble));
        if(lee.eof()) break;
        if(strcmp(abus,codigo)==0)
        {
             Tipo tipoBus;
             int opt;
             cout<<"MENU MODIFICACIONES MUEBLE\n";
             cout<<"1.-Codigo     \n ";
             cout<<"2.-Descripcion\n ";
             cout<<"3.-Precio     \n ";
             cout<<"4.-Existencia \n";
             cout<<"5.-Color      \n";
             cout<<"6.-Tipo       \n";
             opt=leer_int();
             switch (opt) {
             case 1:
                 cout<<"Ingresa el codigo\n";
                 cin.getline(codigo,MAX);
                 break;
             case 2:
                 cout<<"Ingresa la descripcion:\n";
                 cin.getline(descripcion,MAX);
                 break;
             case 3:
                 cout<<"Ingresa el precio:\n";
                 cin.getline(precio,MAX);
                 break;
             case 4:
                 cout<<"Ingresa la cantidad que existen:\n";
                 cin.getline(existencia,MAX);
                 break;
             case 5:

                 cout<<"Ingresa el color:\n";
                 cin.getline(color,MAX);
                 break;
             case 6:
                 do{
                     cout<<"Tipos de muebles:\n";
                     tipoBus.mostrar();
                     cout<<"Ingresa el tipo Mueble :\n";
                 cin.getline(tipo,MAX);
                 }while(!tipoBus.buscar(tipo));
                 break;
             default:
                 break;
             }

             esc.write((char *)&mueble,sizeof(mueble));


            existe=true;

        }else
        {
            esc.write((char *)&mueble,sizeof(mueble));
        }

        }
    }

    lee.close();
    esc.close();
    remove("Muebles.txt");
    rename("AuxM.txt","Muebles.txt");


    return existe;
}

bool Mueble::mostrar_tipo(char abus[MAX])
{   bool existe=false;
    ifstream lee("Muebles.txt");
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof()){
        lee.read((char *)&mueble,sizeof(mueble));
        if(lee.eof()) break;
        if(strcmp(abus,tipo)==0)
        {
            cout<<"\nCodigo     : "<<codigo<<endl;
            cout<<"Descripcion: "<<descripcion<<endl;
            cout<<"Precio     : "<<precio<<endl;
            cout<<"Existencia : "<<existencia<<endl;
            cout<<"Color      : "<<color<<endl;
            cout<<"Tipo       : "<<tipo<<endl<<endl;

            existe=true;

        }

        }
    }

    lee.close();

    return existe;
}
bool Mueble::ordenar_tipo()
{   Mueble *arr;
    int i=0;
    bool existe=false;
    ifstream lee("Muebles.txt");
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee.eof()){
        lee.read((char *)&mueble,sizeof(mueble));
        i++;
        if(lee.eof()) break;
         }
        }
    lee.close();
    arr=new Mueble[i];
    ifstream lee2("Muebles.txt");
    i=0;
    if(!lee2.good())
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!lee2.eof()){
        lee2.read((char *)&mueble,sizeof(mueble));
       if(lee2.eof()) break;
       arr[i]=mueble;
       i++;
         }
        }
    lee2.close();
    cout<<"Esta cantidad de elementos:  "<<i-1<<endl;
    quicksort(0,i-1,arr);
    for(int con=0;con<i-1;con++){
        cout<<"\nCodigo     : "<<arr[con].codigo<<endl;
        cout<<"Descripcion: "<<arr[con].descripcion<<endl;
        cout<<"Precio     : "<<arr[con].precio<<endl;
        cout<<"Existencia : "<<arr[con].existencia<<endl;
        cout<<"Color      : "<<arr[con].color<<endl;
        cout<<"Tipo       : "<<arr[con].tipo<<endl<<endl;
        }
    delete arr;
    return existe;
}

void quicksort(int izq, int der,Mueble *elem){
    int g,h,medio;
    Mueble  pivote, aux;
    medio=(izq+der)/2;
    pivote=elem[medio];
    g=izq;
    h=der;
    while(g<=h){
        while( strcmp(elem[g].tipo,pivote.tipo)==-1)g++;
        while( strcmp(pivote.tipo,elem[h].tipo)==-1)h--;
        if(g<=h){
            aux=elem[g];
            elem[g]=elem[h];
            elem[h]=aux;
            g++;
            h--;
        }
    }
    if(izq<h)quicksort(izq,h,elem);
    if(g<der)quicksort(g,der,elem);
}

#endif // MUEBLES_H
