/*
 * Nombre:Jimenez Olivares Alexis Miguel
 * Materia:Estructura de Datos II
 * Compilador: Qt Creator
 * Tema:
  Encriptacion y desencriptacion
  Practica:
  08
*/
#include <iostream>
#include "Cotizacion.h"
using namespace std;

int main()
{
    Cotizacion cotizacion;
    int op;
    char folio[MAX];
    do{
    cout<<"    MENU PRINCIPAL   \n";
    cout<<"Elige una opcion:\n";
    cout<<" 1.- Agregar \n";
    cout<<" 2.- Mostrar \n";
    cout<<" 3.- Modificar \n";
    cout<<" 4.- Cancelar \n";
    cout<<" 5.- Eliminar \n";
    cout<<" 6.- Buscar \n";
    cout<<" 0.- Salir \n";
     op=leer_int();
 switch(op){
   case 1:
       cotizacion.agregar();
       break;
   case 2:
       cotizacion.mostrar();
       break;
   case 3:
     cout<<"Ingresa el numero de folio:\n";
       cin.getline(folio,MAX);
       cotizacion.modificar(folio);
       break;
   case 4:
     cout<<"Ingresa el numero de folio:\n";
      cin.getline(folio,MAX);
       cotizacion.cancelar(folio);
       break;
   case 5:
     cout<<"Ingresa el numero de folio:\n";
       cin.getline(folio,MAX);
       cotizacion.eliminar(folio);
       break;
   case 6:
     cout<<"Ingresa el numero de folio:\n";
       cin.getline(folio,MAX);
       cotizacion.buscar(folio);
       break;
   case 0:
       break;
    default:
     cout<<"No existe la opcion\n";
    }
   }while(op!=0);
    return 0;
}

