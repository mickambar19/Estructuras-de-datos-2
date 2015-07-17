/*
 * Nombre:Jimenez Olivares Alexis Miguel
 * Materia:Estructura de Datos II
 * Compilador: Qt Creator
 * Tema:
  Acceso aleatorio
  Practica:
  06
*/
#include <iostream>
#include "Vino.h"
using namespace std;

int main(){
    int opt;
    char aux[MAX];
    ifstream leer("dispersion.txt");
    if(!leer.good())
    {
        x.genera();
    }else{
        cout<<"TU TABLA ESTA LISTA\n";
    }
    do
    {
        cout<<"MENU PRINCIPAL\n";
        cout<<"1.-Capturar\n";
        cout<<"2.-Mostrar\n";
        cout<<"3.-Eliminar\n";
        cout<<"4.-Modificar\n";
        cout<<"5.-Mostrar por anio\n";
        cout<<"6.-Mostrar por casa\n";
        opt=leer_int();
        switch(opt){
        case 1:
            x.capturar();
            break;
        case 2:
            x.mostrar();
            break;
        case 3:
            cout<<"Ingresa el codigo\n";
            cin.getline(aux,MAX);
            x.eliminar(aux);
            break;
        case 4:
            cout<<"Ingresa el codigo\n";
            cin.getline(aux,MAX);
            x.modificar(aux);
            break;
        case 5:
            cout<<"Ingresa el anio\n";
            cin.getline(aux,MAX);
            x.mostrar_poranio(aux);
            break;
        case 6:
            cout<<"Ingresa la casa\n";
            cin.getline(aux,MAX);
            x.mostrar_porcasa(aux);
            break;
        default:
            break;
        }
    }while(opt!=0);
    return 0;
}

