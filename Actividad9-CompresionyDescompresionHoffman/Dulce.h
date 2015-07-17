#ifndef DULCE_H
#define DULCE_H
#include <fstream>
#include <cstring>
#include <iostream>
#include "leerentero.h"
#define MAX 40
using namespace std;

class Dulce
{
public:
    char codigo[MAX],descripcion[MAX],presentacion[MAX];
    char marca[MAX],precio[MAX];
    char proveedor[MAX];

public:
    void capturar();
    void mostrar();
    bool buscar(char bus[MAX]);
    void eliminar(char bus[MAX]);
    void modificar(char bus[MAX]);

}dulce,x;
int veces;
void Dulce::capturar()
{

    FILE *archivo=fopen("Dulce.txt","a");
    cout<<"MENU NUEVO Dulce\n";
    cout<<"Ingresa el codigo:\n";
    cin.getline(codigo,MAX);
    cout<<"Ingresa la descripcion:\n";
    cin.getline(descripcion,MAX);
    cout<<"Ingresa el presentacion:\n";
    cin.getline(presentacion,MAX);
    cout<<"Ingresa la marca que existen:\n";
    cin.getline(marca,MAX);
    cout<<"Ingresa el precio:\n";
    cin.getline(precio,MAX);
    cout<<"Ingresa el proveedor Dulce:\n";
    cin.getline(proveedor,MAX);
    if(!buscar(codigo)){
        fwrite(&dulce,sizeof(Dulce),1,archivo);
    }else
    {
        cout<<"YA EXISTE ESE DULCE con ese codigo\n";
    }
    fclose(archivo);
}

void Dulce::mostrar()
{
    FILE *archivo=fopen("Dulce.txt","r");
    if(!archivo)
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!feof(archivo))
        {
            fread(&dulce,sizeof(Dulce),1,archivo);
            if(feof(archivo)) break;
            cout<<"Codigo        : "<<codigo<<endl;
            cout<<"Descripcion   : "<<descripcion<<endl;
            cout<<"presentacion  : "<<presentacion<<endl;
            cout<<"marca         : "<<marca<<endl;
            cout<<"precio        : "<<precio<<endl;
            cout<<"proveedor     : "<<proveedor<<endl<<endl;
            cout<<" __________________________\n";
        }
    }

    fclose(archivo);
}
bool Dulce::buscar(char bus[])
{
    veces=0;
    char aux[MAX];
    strcpy(aux,bus);
    bool existe=false;
    FILE *archivo=fopen("Dulce.txt","r");
    if(!archivo)
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!feof(archivo))
        {
            fread(&x,sizeof(Dulce),1,archivo);
            if(feof(archivo)) break;
            if(strcmp(aux,x.codigo)==0){
                cout<<"Codigo        : "<<x.codigo<<endl;
                cout<<"Descripcion   : "<<x.descripcion<<endl;
                cout<<"presentacion  : "<<x.presentacion<<endl;
                cout<<"marca         : "<<x.marca<<endl;
                cout<<"precio        : "<<x.precio<<endl;
                cout<<"proveedor     : "<<x.proveedor<<endl<<endl;
                cout<<" __________________________\n";
                veces++;
                existe=true;
            }

        }
    }

    fclose(archivo);
    return existe;
}
void Dulce::eliminar(char bus[])
{
    FILE *archivo=fopen("Dulce.txt","r");
    FILE *archivo2=fopen("AuxDulce.txt","a");
    if(!archivo)
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!feof(archivo))
        {
            fread(&dulce,sizeof(Dulce),1,archivo);
            if(feof(archivo)) break;
            if(strcmp(bus,codigo)==0){
                cout<<"Codigo        : "<<codigo<<endl;
                cout<<"Descripcion   : "<<descripcion<<endl;
                cout<<"presentacion  : "<<presentacion<<endl;
                cout<<"marca         : "<<marca<<endl;
                cout<<"precio        : "<<precio<<endl;
                cout<<"proveedor     : "<<proveedor<<endl<<endl;
                cout<<" __________________________\n";
            }else{

                fwrite(&dulce,sizeof(Dulce),1,archivo2);
            }
        }
    }
    fclose(archivo2);
    fclose(archivo);
    remove("Dulce.txt");
    rename("AuxDulce.txt","Dulce.txt");
}
void Dulce::modificar(char bus[])
{
    FILE *archivo=fopen("Dulce.txt","r");
    FILE *archivo2=fopen("AuxDulce.txt","a");
    int opt;
    if(!archivo)
    {
        cout<<"NO EXISTE EL ARCHIVO\n";
    }else{
        while(!feof(archivo))
        {
            fread(&dulce,sizeof(Dulce),1,archivo);
            if(feof(archivo)) break;
            if(strcmp(bus,dulce.codigo)==0){
                cout<<"Que deseas modificar:\n";
                cout<<"1.-Codigo        : "<<codigo<<endl;
                cout<<"2.-Descripcion   : "<<descripcion<<endl;
                cout<<"3.-presentacion  : "<<presentacion<<endl;
                cout<<"4.-marca         : "<<marca<<endl;
                cout<<"5.-precio        : "<<precio<<endl;
                cout<<"6.-proveedor     : "<<proveedor<<endl<<endl;
                cout<<" __________________________\n";
                opt= leer_int();
                switch (opt) {
                case 1:
                    do{
                    cout<<"Ingresa codigo\n";
                    cin.getline(codigo,MAX);
                    buscar(codigo);
                       if(veces>0)cout<<"Ya existe ese codigo\n";
                    }while(veces>0);
                    break;
                case 2:
                    cout<<"Ingresa descripcion\n";
                    cin.getline(descripcion,MAX);
                    break;
                case 3:
                    cout<<"Ingresa presentacion\n";
                    cin.getline(presentacion,MAX);
                    break;
                case 4:
                    cout<<"Ingresa marca\n";
                    cin.getline(marca,MAX);
                    break;
                case 5:
                    cout<<"Ingresa precio\n";
                    cin.getline(precio,MAX);
                    break;
                case 6:
                    cout<<"Ingresa proveedor\n";
                    cin.getline(proveedor,MAX);
                    break;
                default:
                    break;
                }
                fwrite(&dulce,sizeof(Dulce),1,archivo2);
            }else{

                fwrite(&dulce,sizeof(Dulce),1,archivo2);
            }
        }
    }
    fclose(archivo2);
    fclose(archivo);
    remove("Dulce.txt");
    rename("AuxDulce.txt","Dulce.txt");
}
#endif // DULCE_H
