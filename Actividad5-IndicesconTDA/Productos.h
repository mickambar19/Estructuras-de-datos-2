#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include "Indice.h"
#include <iostream>
#include "ListaDoble.h"

using namespace std;
class Producto
{
    private:
        char codigo[MAX];
        char descripcion[MAX];
        char presentacion[MAX];
        char precio[MAX];
   public:
        void capturar();
        void mostrar();
        void mostrar_ordenados_descripcion();
        void mostrar_presentacion(char tipo[MAX]);
        bool modificar(char bus[MAX]);
        bool eliminar(char bus[MAX]);
        bool buscar(char bus[MAX]);
        void mostrar_mediante_lista();
        char* getDescripcion();
        friend ostream &operator <<(ostream& a,Producto &pro);

}producto;
void quicksort(int izq, int der,Producto *elem);
ListaSimple<Indice> l;
ListaSimple<Indice> l2;
void Producto::capturar()
{
    cout<<"MENU CAPTURAR\n";
    cout<<"INGRESA:\n";
    cout<<"CODIGO de producto:\n";
    cin.getline(codigo,MAX);
    cout<<"DESCRIPCION de producto:\n";
    cin.getline(descripcion,MAX);
    cout<<"PRESENTACION de producto:\n";
    cin.getline(presentacion,MAX);
    cout<<"PRECIO de producto:\n";
    cin.getline(precio,MAX);
    strcpy(indice.llave,codigo);
    if(indice.buscar(codigo)==true)
    {
      cout<<"Ya existe un producto con este codigo\n";
    }
    else
    {
        ofstream escp("Producto.txt",ios::app);
        ofstream esci("Indice.txt",ios::app);
        escp.write((char*)&producto,sizeof(producto));
        strcpy(indice.llave,codigo);
        escp.seekp(0,escp.end);
        indice.posicion=escp.tellp();
        indice.posicion=indice.posicion-sizeof(producto);
        cout<<indice<<endl;
        l.insertOneAfter(indice,l.last());
        esci.write((char*)&indice,sizeof(indice));
        escp.close();
        esci.close();
    }
}

void Producto::mostrar()
{
    ifstream leeri("Indice.txt");

    if(!leeri.good())
    {
        cout<<"NO EXISTE ARCHIVO\n";
    }else
    {
        while(!leeri.eof())
        {

            leeri.read((char*)&indice,sizeof(indice));
            ifstream leerp("Producto.txt",ios::out);
            leerp.seekg(indice.posicion,ios::beg);
            leerp.read((char*)&producto,sizeof(producto));
            if(leeri.eof())break;
            cout<<"---------PRODUCTO------------\n";
            cout<<"CODIGO       :"<< producto.codigo<<endl;
            cout<<"DESCRIPCION  :"<< producto.descripcion<<endl;
            cout<<"TIPO         :"<< producto.presentacion<<endl;
            cout<<"PRECIO       :"<< producto.precio<<endl;
            cout<<"-----------------------------\n";

        }
    }
    leeri.close();
}

void Producto::mostrar_ordenados_descripcion()
{
    ifstream leeri("Indice.txt");
    int i=0;
    Producto *array;
    if(!leeri.good())
    {
        cout<<"NO EXISTE ARCHIVO\n";
    }else
    {
        while(!leeri.eof())
        {
            leeri.read((char*)&indice,sizeof(indice));
            if(leeri.eof())break;
            i++;
        }
    }
    leeri.close();
    array=new Producto[i];
    cout<<"1:  "<<i<<endl;
    leeri.open("Indice.txt",ios::app);
    i=0;
    if(!leeri.good())
    {
        cout<<"NO EXISTE ARCHIVO\n";
    }else
    {
        while(!leeri.eof())
        {

            leeri.read((char*)&indice,sizeof(indice));
            ifstream leerp("Producto.txt",ios::out);
            leerp.seekg(indice.posicion,ios::beg);
            leerp.read((char*)&producto,sizeof(producto));
            if(leeri.eof())break;
            array[i]=producto;
            i++;
        }
    }
    leeri.close();
    quicksort(0,i-1,array);
    for(int x=0;x<i;x++)
    {
        cout<<array[x]<<endl;
    }
}

void Producto::mostrar_presentacion(char tipo[])
{
    ifstream leeri("Indice.txt");

    if(!leeri.good())
    {
        cout<<"NO EXISTE ARCHIVO\n";
    }else
    {
        while(!leeri.eof())
        {

            leeri.read((char*)&indice,sizeof(indice));
            ifstream leerp("Producto.txt",ios::out);
            leerp.seekg(indice.posicion,ios::beg);
            leerp.read((char*)&producto,sizeof(producto));
            if(leeri.eof())break;
            if(strcmp(tipo,producto.presentacion)==0)
            {
                cout<<"---------PRODUCTO------------\n";
                cout<<"CODIGO       :"<< producto.codigo<<endl;
                cout<<"DESCRIPCION  :"<< producto.descripcion<<endl;
                cout<<"TIPO         :"<< producto.presentacion<<endl;
                cout<<"PRECIO       :"<< producto.precio<<endl;
                cout<<"-----------------------------\n";
            }
        }
    }
    leeri.close();

}



bool Producto::modificar(char bus[])
{
    bool existe=false;
    int opt;
    ifstream leeri("Indice.txt");
    ofstream escpa("Auxiliar.txt",ios::app);
    if(!leeri.good())
    {
        cout<<"NO EXISTE ARCHIVO\n";
    }else
    {
        while(!leeri.eof())
        {

            leeri.read((char*)&indice,sizeof(indice));
            ifstream leerp("Producto.txt",ios::out);
            leerp.seekg(indice.posicion,ios::beg);
            if(leeri.eof())break;
            leerp.read((char*)&producto,sizeof(producto));
            if(strcmp(producto.codigo,bus)==0){
                do {
                    cout<<"---------PRODUCTO: "<<producto.codigo<<"------------\n";
                    cout<<"1.-DESCRIPCION  :"<< producto.descripcion<<endl;
                    cout<<"2.-TIPO         :"<< producto.presentacion<<endl;
                    cout<<"3.-PRECIO       :"<< producto.precio<<endl;
                    cout<<"-----------------------------\n";
                    cout<<"4.-SALIR\n";
                    cout<<"Que deseas modificar:\n";
                    opt=leer_int();
                    switch (opt) {
                    case 1:
                        cout<<"Ingresa descripcion de producto\n";
                        cin.getline(producto.descripcion,MAX);

                        break;
                    case 2:
                        cout<<"Ingresa presentacion de producto:\n";
                        cin.getline(producto.presentacion,MAX);

                        break;
                    case 3:
                        cout<<"Ingresa precio de producto\n";
                        cin.getline(producto.precio,MAX);
                        break;
                    case 4:

                        break;
                    default:
                        cout<<"No existe esta opcion\n";
                        break;
                    }
                }while(opt!=4);
                existe=true;
            }
            escpa.write((char *)&producto,sizeof(producto));
         }
    }
    if(!existe){
        cout<<"NO EXISTE EL PRODUCTO QUE DESEASBAS MODIFICAR\n";
    }

    leeri.close();
    escpa.close();
    remove("Producto.txt");
    rename("Auxiliar.txt","Producto.txt");
return existe;
}

bool Producto::eliminar(char bus[])
{
    bool existe=false;
    ifstream leeri("Indice.txt");
    NodoDoble<Indice> *aeliminar;

    if(!leeri.good())
    {
        cout<<"NO EXISTE ARCHIVO\n";
    }else
    {
        while(!leeri.eof())
        {

            leeri.read((char*)&indice,sizeof(indice));
            ifstream leerp("Producto.txt",ios::out);
            leerp.seekg(indice.posicion,ios::beg);
            if(leeri.eof())break;
            leerp.read((char*)&producto,sizeof(producto));
            if(strcmp(producto.codigo,bus)==0)
            {
               existe=true;
            }
            else
            {
            ofstream escpa("Auxiliar.txt",ios::app);
            ofstream escia("Auxiliari.txt",ios::app);
            escpa.write((char *)&producto,sizeof(producto));
            escpa.seekp(0,escpa.end);
            indice.posicion=escpa.tellp();
            indice.posicion=indice.posicion-sizeof(producto);
            strcpy(indice.llave,producto.codigo);
            escia.write((char*)&indice,sizeof(indice));
            cout<<indice<<endl;
            cout<<producto<<endl;
            aeliminar=l.linealSearch(indice);
            l.delete_e(aeliminar);
            escpa.close();
            escia.close();
            }

         }
    }
    leeri.close();
    remove("Producto.txt");
    rename("Auxiliar.txt","Producto.txt");
    remove("Indice.txt");
    rename("Auxiliari.txt","Indice.txt");
return existe;
}

bool Producto::buscar(char bus[])
{
    bool existe=false;
    ifstream leeri("Indice.txt");
    if(!leeri.good())
    {
        cout<<"NO EXISTE ARCHIVO\n";
    }else
    {
        while(!leeri.eof())
        {

            leeri.read((char*)&indice,sizeof(indice));
            ifstream leerp("Producto.txt",ios::out);
            leerp.seekg(indice.posicion,ios::beg);
            if(leeri.eof())break;
            leerp.read((char*)&producto,sizeof(producto));
            if(strcmp(producto.codigo,bus)==0)
            {
               cout<<producto<<endl;
               existe=true;
            }
         }
    }
    leeri.close();
return existe;
}

char* Producto::getDescripcion()
{
    return descripcion;
}

ostream &operator <<(ostream &a, Producto &pro)
{
    a<<"---------PRODUCTO------------\n";
    a<<"CODIGO       :"<< pro.codigo<<endl;
    a<<"DESCRIPCION  :"<< pro.descripcion<<endl;
    a<<"TIPO         :"<< pro.presentacion<<endl;
    a<<"PRECIO       :"<< pro.precio<<endl;
    a<<"-----------------------------\n";
        return a;
}

void quicksort(int izq, int der,Producto *elem){
    int g,h,medio;
    Producto  pivote, aux;
    medio=(izq+der)/2;
    pivote=elem[medio];
    g=izq;
    h=der;
    while(g<=h){
        while( strcmp(elem[g].getDescripcion(),pivote.getDescripcion())==-1)g++;
        while( strcmp(pivote.getDescripcion(),elem[h].getDescripcion())==-1)h--;
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
void Producto::mostrar_mediante_lista()
{
    NodoDoble<Indice>* nodo;
    nodo=l2.first();
    if(l2.isEmpty())
    {
        cout<<"NO EXISTEN ELEMENTOS\n";
    }else
    {
        while(nodo!=NULL)
        {
            indice=nodo->getData();
            ifstream leerp("Producto.txt",ios::out);
            leerp.seekg(indice.posicion,ios::beg);
            leerp.read((char*)&producto,sizeof(producto));

            cout<<"---------PRODUCTO------------\n";
            cout<<"CODIGO       :"<< producto.codigo<<endl;
            cout<<"DESCRIPCION  :"<< producto.descripcion<<endl;
            cout<<"TIPO         :"<< producto.presentacion<<endl;
            cout<<"PRECIO       :"<< producto.precio<<endl;
            cout<<"-----------------------------\n";
            nodo=nodo->getNext();
        }
    }
}


#endif // PRODUCTOS_H
