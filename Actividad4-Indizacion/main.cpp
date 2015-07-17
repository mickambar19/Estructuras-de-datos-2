/*
 * Nombre:Jimenez Olivares Alexis Miguel
 * Materia:Estructura de Datos II
 * Compilador: Qt Creator
 * Tema:
  Indizacion
  Practica:
  04
*/
#include <iostream>
#include "Productos.h"
using namespace std;

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
        case  0:
            break;
        default:
            cout<<"NO EXISTE LA OPCION ELEGIDA\n";
            break;
        }
    }while(menu!=0);


    return 0;
}

