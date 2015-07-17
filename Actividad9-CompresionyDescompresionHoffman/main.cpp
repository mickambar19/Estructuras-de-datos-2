/*
 * Nombre:Jimenez Olivares Alexis Miguel
 * Materia:Estructura de Datos II
 * Compilador: Qt Creator
 * Tema:
  Compresión y Descompresión de archivos
  Practica:
  09
*/
#include <iostream>
#include "Dulce.h"
#include "Ahoffman.h"
using namespace std;

int main()
{
    remove("HoffmandeDulce.txt");
    remove("Resultados.txt");
   int mentip;
   char aux[MAX];
   do{
   cout<<"MENU DE TIPOS DE DULCES\n";
   cout<<"1.-Agregar\n";
   cout<<"2.-Buscar\n";
   cout<<"3.-Mostrar\n";
   cout<<"4.-Modificar\n";
   cout<<"5.-Eliminar\n";
   cout<<"6.-Comprimir o Descomprimir\n";
   cout<<"0.-Salir\n";
   mentip=leer_int();
   switch (mentip) {
   case 1:
       dulce.capturar();
       break;
   case 2:
       cout<<"Ingresa el codigo de dulce:\n";
       cin.getline(aux,MAX);
       dulce.buscar(aux);
       break;
   case 3:
       cout<<"Ingresa el codigo de dulce:\n";
       dulce.mostrar();
       break;
   case 4:
       cout<<"Ingresa el codigo de dulce:\n";
       cin.getline(aux,MAX);
       dulce.modificar(aux);
       break;
   case 5:
       cout<<"Ingresa el codigo de dulce:\n";
       cin.getline(aux,MAX);
       dulce.eliminar(aux);
       break;
   case 6:
       ahoffman();
       break;
   default:
       break;
   }}while(mentip!=0);
    return 0;
}
