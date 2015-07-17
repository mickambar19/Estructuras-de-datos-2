/*
 * Nombre:Jimenez Olivares Alexis Miguel
 * Materia:Estructura de Datos II
 * Compilador: Qt Creator
 * Tema:
  Registros de Longitud Fija
  Practica:
  03
*/
#include <iostream>
#include "Muebles.h"
using namespace std;

int main()
{   int men;
    int mentip;
    int menmu;
    char aux[MAX];
    bool existe;
   cout<<"MENU PRINCIPAL\n";
   cout<<"1.-Tipo de Muebles\n";
   cout<<"2.-Muebles\n";
   cout<<"3.-Ninguna de las anteriores\n";
   men=leer_int();
   switch (men) {
   case 1:
       do{
       cout<<"MENU DE TIPOS DE MUEBLES\n";
       cout<<"1.-Agregar\n";
       cout<<"2.-Buscar\n";
       cout<<"3.-Mostrar\n";
       cout<<"0.-Salir\n";
       mentip=leer_int();
       switch (mentip) {
       case 1:
           objeto.capturar();
           break;
       case 2:
           cout<<"Ingresa el tipo que buscas:\n";
           cin.getline(aux,50);
           existe=objeto.buscar(aux);
           if(existe){cout<<"SI EXISTE EL TIPO\n";}
           else{ cout<<"NO EXISTE EL TIPO\n";}
           break;
       case 3:
           cout<<"\nTODOS LOS TIPOS\n";
           objeto.mostrar();
           break;
       default:
           break;
       }}while(mentip!=0);

       break;
   case 2:
       do{
       cout<<"MENU DE MUEBLES\n";
       cout<<"1.-Agregar\n";
       cout<<"2.-Buscar\n";
       cout<<"3.-Mostrar\n";
       cout<<"4.-Mostrar los de tipo\n";
       cout<<"5.-Mostrar todos por tipo\n";
       cout<<"6.-Modificar\n";
       cout<<"7.-Eliminar\n";
       cout<<"0.-Salir\n";
       menmu=leer_int();
       switch (menmu) {
       case 1:
           mueble.capturar();
           break;
       case 2:
           cout<<"Ingresa el codigo del mueble que buscas:\n";
           cin.getline(aux,50);
           existe=mueble.buscar(aux);
           if(existe){cout<<"SI EXISTE EL MUEBLE\n";}
           else{ cout<<"NO EXISTE EL MUEBLE\n";}
           break;
       case 3:
           cout<<"\nTODOS LOS MUEBLES\n";
           mueble.mostrar();
           break;
       case 4:
           cout<<"Ingresa el TIPO de mueble :\n";
           cin.getline(aux,50);
           cout<<"\nTODOS LOS MUEBLES DE TIPO\n";
           existe=mueble.mostrar_tipo(aux);
           if(!existe)
           {
               cout<<"No existe ningun mueble con ese codigo\n";
           }
           break;
       case 5:
           cout<<"\nTODOS LOS MUEBLES ORDENADOS\n";
          mueble.ordenar_tipo();
           break;
       case 6:
           cout<<"\nMODIFICAR\n";
           cout<<"Ingresa el codigo del mueble que deseas modificar:\n";
           cin.getline(aux,50);
          mueble.modificar(aux);
           break;
       case 7:
           cout<<"\nELIMINAR\n";
           cout<<"Ingresa el codigo del mueble que deseas eliminar:\n";
           cin.getline(aux,50);
          mueble.eliminar(aux);
           break;
       default:
           break;
       }}while(menmu!=0);

       break;
   default:
       break;
   }
    return 0;
}

