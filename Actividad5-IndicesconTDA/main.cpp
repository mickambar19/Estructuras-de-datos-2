/*
 * Nombre:Jimenez Olivares Alexis Miguel
 * Materia:Estructura de Datos II
 * Compilador: Qt Creator
 * Tema:
  Indices con TDA
  Practica:
  05
*/
#include <iostream>
#include "Productos.h"
using namespace std;
void Cargar_lista()
{
    ifstream leerind("Indice.txt");
    if(!leerind.good()){
        cout<<"Tu archivo no existe\n";
    }else{
        while(!leerind.eof()){
            leerind.read((char *)&indice, sizeof(indice));
            if(leerind.eof())break;
            l.insertOneAfter(indice,l.last());
          }
    }
    leerind.close();
}
void copiarlista(){
    NodoDoble<Indice> *aux;
    Indice indice2;
    aux=l.first();
    while(aux!=NULL){
        indice2=aux->getData();
        l2.insertOneAfter(indice2,l2.first());
        aux=aux->getNext();
    }
}

void Guardar_lista()
{
    ofstream escind("Indice.txt",ios::app);
    NodoDoble<Indice> *aux;
    aux=l.first();
    if(!l.isEmpty()){
        while(aux!=NULL){
            indice=aux->getData();
            escind.write((char *)&indice, sizeof(indice));
            aux=aux->getNext();
        }
    }else
    {
        cout<<"la lista esta vacia\n";
    }
}
int main()
{
    char x[MAX];
    int menu;
    do
    {
        cout<<"MENU PRINCIPAL\n";
        cout<<"Que deseas hacer:\n";
        cout<<"1.-Capturar\n";
        cout<<"2.-Mostrar\n";
        cout<<"3.-Buscar\n";
        cout<<"4.-Modificar\n";
        cout<<"5.-Eliminar\n";
        cout<<"6.-Ordenados por descripcion\n";
        cout<<"7.-Mostrar por Tipo\n";
        cout<<"8.-Cargar Lista indices\n";
        cout<<"9.-Mostrar Lista de indices\n";
        cout<<"10.-Ordenamiento quicksort ascendente\n";
        cout<<"11.-Ordenamiento merge descendente\n";
        cout<<"0.-Salir\n";
        menu=leer_int();
        switch (menu) {
        case 1:
            cout<<"Capturar producto\n";
            producto.capturar();
            break;
        case 2:
            producto.mostrar();
            break;
        case 3:
            cout<<"Ingresa el CODIGO de producto a buscar:\n";
            cin.getline(x,MAX);
            producto.buscar(x);
            break;
        case 4:
            cout<<"Ingresa el CODIGO de producto a modificar:\n";
            cin.getline(x,MAX);
            producto.modificar(x);
            break;
        case 5:
            cout<<"Ingresa el CODIGO de producto a eliminar:\n";
            cin.getline(x,MAX);
            producto.eliminar(x);
            break;
        case 6:
            producto.mostrar_ordenados_descripcion();
            break;
        case 7:
            cout<<"Ingresa el TIPO de producto a eliminar:\n";
            cin.getline(x,MAX);
            producto.mostrar_presentacion(x);
            break;
        case 8:
            cout<<"Cargando lista\n";
            Cargar_lista();
            l.printAll();
            break;
        case 9:
            cout<<"9.-Mostrar Lista de indices\n";
            l.printAll();
            break;
        case 10:
            cout<<"10.-Ordenamiento quicksort ascendente\n";
            copiarlista();
            l2.order();
            producto.mostrar_mediante_lista();
            break;
        case 11:
            cout<<"11.-Ordenamiento merge descendente\n";
            copiarlista();
            l2.orderMerge();
            producto.mostrar_mediante_lista();
            cout<<"Asi se encontraba la lista secundaria temporal:\n";
            l2.printAll();
            break;
        case  0:
            break;
        default:
            cout<<"NO EXISTE LA OPCION ELEGIDA\n";
            break;
        }
    }while(menu!=0);


    return 0;
}

