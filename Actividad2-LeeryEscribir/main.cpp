/*
* Nombre: Jimenez Olivares Alexis Miguel
* Materia:Estructura de datos 2
* Compilador: Qt Creator
* Tema:
* Registros de longitud variable
* Nota: Abrir .pro con QtCreator
*/
#include <iostream>
#include "Contacto.h"
#include <fstream>

using namespace std;

int main()
{   bool encontrado;
    Contacto contacto;
    char a[50],gradoBus[50],grupoBus[50];
    int optMN=0;
   do{
   cout<<"MENU PRINCIPAL\n";
   cout<<"Elige una opcion:\n";
   cout<<"1.- Capturar nuevo estudiante\n";
   cout<<"2.- Mostrar todos los alumnos\n";
   cout<<"3.- Mostrar todos los alumnos por grupo\n";
   cout<<"4.- Modificar alumno\n";
   cout<<"5.- Eliminar alumno\n";
   cout<<"6.- Buscar alumno\n";
   cout<<"9.- Salir\n";
   optMN=leer_int();
   switch (optMN) {
   case 1:
       contacto.capturar();
       break;
   case 2:
       contacto.mostrar();
       break;
   case 3:
       cout<<"Ingresa el grado del grupo:\n";
       cin.getline(gradoBus,50);
       cout<<"Ingresa el grupo:\n";
       cin.getline(grupoBus,50);

       cout<<"AQUI SE MUESTRAN TODAS LAS COINCIDENCIAS\n";
       cout<<"Grupo: "<<grupoBus<<endl;
       cout<<"Grado: "<<gradoBus<<endl<<endl;
     contacto.mostrar_grado_grupo(gradoBus,grupoBus);
       break;
   case 4:
       cout<<"Ingresa el nombre del alumno a modificar:\n";
       cin.getline(a,50);
      encontrado= contacto.modificar(a);
      if(encontrado!=1) cout<<"No existe estudiante\n";
       break;
   case 5:
       cout<<"Ingresa el nombre del alumno a eliminar:\n";
       cin.getline(a,50);
       encontrado=contacto.eliminar(a);
       if(encontrado!=1) cout<<"No existe estudiante\n";
       break;
   case 6:
       cout<<"Ingresa el nombre del alumno a buscar:\n";
       cin.getline(a,50);
       encontrado=contacto.buscar(a);
       if(encontrado!=1) cout<<"No existe estudiante\n";
       break;

   case 9:
       break;
   default:
       break;
   }}while(optMN!=9);
    return 0;
}


