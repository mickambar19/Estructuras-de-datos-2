#ifndef COTIZACION_H
#define COTIZACION_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "leerentero.h"
#define MAX 100
using namespace std;
void desencriptar(char *bus);
void encriptar(char *bus);
char llave='a';
class Cotizacion{
private:
    char folio[MAX];
    char fecha[MAX];
    char empleado[MAX];
    char cliente[MAX];
    char telefono[MAX];
    char entrada[MAX];
    char salida[MAX];
    char servicio[MAX];
    char personas[MAX];
    char iva[MAX];
    char total[MAX];
    char activo[MAX];
public:
    void agregar();
    void mostrar();
    void modificar(char f[MAX]);
    void cancelar(char f[MAX]);
    void eliminar(char f[MAX]);
    void buscar(char f[MAX]);
};

void Cotizacion::agregar()
{
      int ninios;
      int auxiliar;
      float auxiliar2;


    cout<<"NUEVA COTIZACION\n";
    cout<<"Ingresa fecha"<<endl;
    cin.getline(fecha,MAX);
    cout<<"Ingresa folio"<<endl;
    cin.getline(folio,MAX);
    cout<<"Ingresa empleado"<<endl;
    cin.getline(empleado,MAX);
    cout<<"Ingresa nombre cliente"<<endl;
    cin.getline(cliente,MAX);
    cout<<"Ingresa telefono"<<endl;
    cin.getline(telefono,MAX);
    cout<<"Ingresa entrada"<<endl;
    cin.getline(entrada,MAX);
    cout<<"Ingresa salida"<<endl;
    cin.getline(salida,MAX);
    cout<<"Ingresa servicio"<<endl;
    cin.getline(servicio,MAX);
    cout<<"Ingresa personas"<<endl;
    cin.getline(personas,MAX);
    int pers;
    pers=atoi(personas);
    do{
    cout<<"\xA8"<<"Cuantas de ellas son menores de 10 a\xA4os?\n";
    ninios=leer_int();
    if(ninios<0 || ninios>pers){
    cout<<"El numero de ni\xA4os debe ser acorde.\n Ingresa de nuevo.\n";
    }
    }while(ninios<0 || ninios>pers);

    auxiliar=(ninios*45)+((pers-ninios)*90);
    sprintf(iva, "%f", (auxiliar*.15));
    cout<<"total:"<<(auxiliar*.15)+auxiliar<<endl;
    auxiliar2=(auxiliar*.15)+auxiliar;
    sprintf(total, "%f", auxiliar2);
    itoa(1,activo,10);
    ofstream escribir("Cotizacion.txt",ios::app);//app -> como utilizar el puntero
    encriptar(folio);
    encriptar(fecha);
    encriptar(empleado);
    encriptar(cliente);
    encriptar(telefono);
    encriptar(entrada);
    encriptar(salida);
    encriptar(servicio);
    encriptar(personas);
    encriptar(iva);
    encriptar(total);
    encriptar(activo);
    escribir<<folio<<'|'<<fecha<<'|'<<empleado<<'|'<<cliente<<'|'<<telefono<<'|'<<entrada<<'|'<<salida<<'|'
    <<servicio<<'|'<<personas<<'|'<<iva<<'|'<<total<<'|'<<activo<<'!';
    escribir.close();

}

void Cotizacion::mostrar()
{
    int i;
    ifstream leer("Cotizacion.txt");

    if(!leer.good())
    {
        cout<<"No existe archivo";
    }
    else
    {
        while(!leer.eof())
        {
            cout<<"-----   Cotizacion  ------\n";
            i=0;
            do
            {
                leer.read((char*)& folio[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(folio[i-1]!='|');
            folio[i-1]='\0';
            //fecha
            i=0;
            do
            {
                leer.read((char*)& fecha[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(fecha[i-1]!='|');
            fecha[i-1]='\0';
            //empleado
            i=0;
            do
            {
                leer.read((char*)& empleado[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(empleado[i-1]!='|');
            empleado[i-1]='\0';
            //cliente
            i=0;
            do
            {
                leer.read((char*)& cliente[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(cliente[i-1]!='|');
            cliente[i-1]='\0';
            //telefono
            i=0;
            do
            {
                leer.read((char*)& telefono[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            //entrada
            i=0;
            do
            {
                leer.read((char*)& entrada[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(entrada[i-1]!='|');
            entrada[i-1]='\0';
            //salida
            i=0;
            do
            {
                leer.read((char*)& salida[i],1);
                if(leer.eof())break;
                i++;
            }while(salida[i-1]!='|');
            salida[i-1]='\0';
            //serrvicio
            i=0;
            do
            {
                leer.read((char*)& servicio[i],1);
                if(leer.eof())break;
                i++;
            }while(servicio[i-1]!='|');
            servicio[i-1]='\0';
            //personas
            i=0;
            do
            {
                leer.read((char*)& personas[i],1);
                if(leer.eof())break;
                i++;
            }while(personas[i-1]!='|');
            personas[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& iva[i],1);
                if(leer.eof())break;
                i++;
            }while(iva[i-1]!='|');
            iva[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& total[i],1);
                if(leer.eof())break;
                i++;
            }while(total[i-1]!='|');
            total[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& activo[i],1);
                if(leer.eof())break;
                i++;
            }while(activo[i-1]!='!');
            activo[i-1]='\0';
            desencriptar(folio);
            desencriptar(fecha);
            desencriptar(empleado);
            desencriptar(cliente);
            desencriptar(telefono);
            desencriptar(entrada);
            desencriptar(salida);
            desencriptar(servicio);
            desencriptar(personas);
            desencriptar(iva);
            desencriptar(total);
            desencriptar(activo);
            if(leer.eof())break;
            cout<<"Fecha:"<<fecha<<"\nFolio:"<<folio<<"\nEmpleado:"<<empleado;
            cout<<"\nCliente:"<<cliente<<"\nTelefono"<<telefono<<"\nEntrada:"<<entrada<<"\nSalida:"<<salida<<"\nServicios:";
            cout<<servicio<<"\nPersonas:"<<personas<<"\niva:"<<iva<<"\nTotal:"<<total<<"\nActividad:";

            if(strcmp(activo,"1")==0){
                cout<<"activo"<<endl;}
            else{
                cout<<"inactivo"<<endl;}

        }
        leer.close();
    }
}

void Cotizacion::modificar(char f[])
{

    int opcion;
    int i;

    ifstream leer("Cotizacion.txt");

    if(!leer.good())
    {
        cout<<"No existe archivo";
    }
    else
    {
        while(!leer.eof())
        {

            i=0;
            do
            {
                leer.read((char*)& folio[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(folio[i-1]!='|');
            folio[i-1]='\0';
            //fecha
            i=0;
            do
            {
                leer.read((char*)& fecha[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(fecha[i-1]!='|');
            fecha[i-1]='\0';
            //empleado
            i=0;
            do
            {
                leer.read((char*)& empleado[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(empleado[i-1]!='|');
            empleado[i-1]='\0';
            //cliente
            i=0;
            do
            {
                leer.read((char*)& cliente[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(cliente[i-1]!='|');
            cliente[i-1]='\0';
            //telefono
            i=0;
            do
            {
                leer.read((char*)& telefono[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            //entrada
            i=0;
            do
            {
                leer.read((char*)& entrada[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(entrada[i-1]!='|');
            entrada[i-1]='\0';
            //salida
            i=0;
            do
            {
                leer.read((char*)& salida[i],1);
                if(leer.eof())break;
                i++;
            }while(salida[i-1]!='|');
            salida[i-1]='\0';
            //serrvicio
            i=0;
            do
            {
                leer.read((char*)& servicio[i],1);
                if(leer.eof())break;
                i++;
            }while(servicio[i-1]!='|');
            servicio[i-1]='\0';
            //personas
            i=0;
            do
            {
                leer.read((char*)& personas[i],1);
                if(leer.eof())break;
                i++;
            }while(personas[i-1]!='|');
            personas[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& iva[i],1);
                if(leer.eof())break;
                i++;
            }while(iva[i-1]!='|');
            iva[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& total[i],1);
                if(leer.eof())break;
                i++;
            }while(total[i-1]!='|');
            total[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& activo[i],1);
                if(leer.eof())break;
                i++;
            }while(activo[i-1]!='!');
            activo[i-1]='\0';
            desencriptar(folio);
            if(leer.eof())break;
            if(strcmp(folio,f)==0){
                desencriptar(fecha);
                desencriptar(empleado);
                desencriptar(cliente);
                desencriptar(telefono);
                desencriptar(entrada);
                desencriptar(salida);
                desencriptar(servicio);
                desencriptar(personas);
                desencriptar(iva);
                desencriptar(total);
                desencriptar(activo);
                cout<<"MODIFICACIONES\n";
                cout<<"  1.-Fecha:"<<fecha<<"\n2.-Folio:"<<folio<<"\n3.-Empleado:"<<empleado;
                cout<<"\n4.-Cliente:"<<cliente<<"\n5.-Telefono"<<telefono<<"\n6.-Entrada:"<<entrada<<"\n7.-Salida:"<<salida<<"\n8.-Servicios:";
                cout<<servicio<<"\n9.-Personas:"<<personas<<endl;
                opcion=leer_int();
                switch(opcion){
                case 1:
                    cout<<"Ingresa fecha"<<endl;
                    cin.getline(fecha,MAX);
                    break;
                case 2:
                    cout<<"Ingresa folio"<<endl;
                    cin.getline(folio,MAX);
                    break;
                case 3:
                    cout<<"Ingresa empleado"<<endl;
                    cin.getline(empleado,MAX);
                    break;
                case 4:
                    cout<<"Ingresa nombre cliente"<<endl;
                    cin.getline(cliente,MAX);
                    break;
                case 5:
                    cout<<"Ingresa telefono"<<endl;
                    cin.getline(telefono,MAX);
                    break;
                case 6:
                    cout<<"Ingresa entrada"<<endl;
                    cin.getline(entrada,MAX);
                    break;
                case 7:
                    cout<<"Ingresa salida"<<endl;
                    cin.getline(salida,MAX);
                    break;
                case 8:
                    cout<<"Ingresa servicio"<<endl;
                    cin.getline(servicio,MAX);
                    break;
                case 9:{
                    int auxiliar;
                    int ninios;
                    float auxiliar2;
                    int pers;
                    pers=atoi(personas);
                    do{
                        cout<<"  \xA8"<<"Cuantas de ellas son mayores a 4 y menores de 10 a\xA4os?\n";
                        ninios=leer_int();
                        if(ninios<0 || ninios>pers){
                            cout<<"El numero de ni\xA4os debe ser acorde.\n Ingresa de nuevo.\n";
                        }
                    }while(ninios<0 || ninios>pers);
                    auxiliar=(ninios*45)+((pers-ninios)*90);
                    sprintf(iva, "%f", (auxiliar*.15));
                    auxiliar2=(auxiliar*.15)+auxiliar;
                    sprintf(total, "%f", auxiliar2);
                    break;}
                default:
                    cout<<"No existe esta opcion";
                }
                cout<<"-----   Cotizacion  ------\n";
                cout<<"Fecha:"<<fecha<<"\nFolio:"<<folio<<"\nEmpleado:"<<empleado;
                cout<<"\nCliente:"<<cliente<<"\nTelefono"<<telefono<<"\nEntrada:"<<entrada<<"\nSalida:"<<salida<<"\nServicios:";
                cout<<servicio<<"\nPersonas:"<<personas<<"\niva:"<<iva<<"\nTotal:"<<total<<endl;
                encriptar(folio);
                encriptar(fecha);
                encriptar(empleado);
                encriptar(cliente);
                encriptar(telefono);
                encriptar(entrada);
                encriptar(salida);
                encriptar(servicio);
                encriptar(personas);
                encriptar(iva);
                encriptar(total);
                encriptar(activo);
                ofstream escribir("Auxiliar.txt",ios::app);//app -> como utilizar el puntero
                escribir<<folio<<'|'<<fecha<<'|'<<empleado<<'|'<<cliente<<'|'<<telefono<<'|'<<entrada<<'|'<<salida<<'|'
                       <<servicio<<'|'<<personas<<'|'<<iva<<'|'<<total<<'|'<<activo<<'!';
                escribir.close();
            }else{
                encriptar(folio);
                ofstream escribir("Auxiliar.txt",ios::app);//app -> como utilizar el puntero
                escribir<<folio<<'|'<<fecha<<'|'<<empleado<<'|'<<cliente<<'|'<<telefono<<'|'<<entrada<<'|'<<salida<<'|'
                       <<servicio<<'|'<<personas<<'|'<<iva<<'|'<<total<<'|'<<activo<<'!';
                escribir.close();
            }

        }
        leer.close();
        remove("Cotizacion.txt");
        rename("Auxiliar.txt","Cotizacion.txt");
    }

}

void Cotizacion::cancelar(char f[])
{

    int opcion;
    int i;

    ifstream leer("Cotizacion.txt");

    if(!leer.good())
    {
        cout<<"No existe archivo";
    }
    else
    {
        while(!leer.eof())
        {
            cout<<"-----   Cotizacion  ------\n";
            i=0;
            do
            {
                leer.read((char*)& folio[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(folio[i-1]!='|');
            folio[i-1]='\0';
            //fecha
            i=0;
            do
            {
                leer.read((char*)& fecha[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(fecha[i-1]!='|');
            fecha[i-1]='\0';
            //empleado
            i=0;
            do
            {
                leer.read((char*)& empleado[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(empleado[i-1]!='|');
            empleado[i-1]='\0';
            //cliente
            i=0;
            do
            {
                leer.read((char*)& cliente[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(cliente[i-1]!='|');
            cliente[i-1]='\0';
            //telefono
            i=0;
            do
            {
                leer.read((char*)& telefono[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            //entrada
            i=0;
            do
            {
                leer.read((char*)& entrada[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(entrada[i-1]!='|');
            entrada[i-1]='\0';
            //salida
            i=0;
            do
            {
                leer.read((char*)& salida[i],1);
                if(leer.eof())break;
                i++;
            }while(salida[i-1]!='|');
            salida[i-1]='\0';
            //serrvicio
            i=0;
            do
            {
                leer.read((char*)& servicio[i],1);
                if(leer.eof())break;
                i++;
            }while(servicio[i-1]!='|');
            servicio[i-1]='\0';
            //personas
            i=0;
            do
            {
                leer.read((char*)& personas[i],1);
                if(leer.eof())break;
                i++;
            }while(personas[i-1]!='|');
            personas[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& iva[i],1);
                if(leer.eof())break;
                i++;
            }while(iva[i-1]!='|');
            iva[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& total[i],1);
                if(leer.eof())break;
                i++;
            }while(total[i-1]!='|');
            total[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& activo[i],1);
                if(leer.eof())break;
                i++;
            }while(activo[i-1]!='!');
            activo[i-1]='\0';
            desencriptar(folio);
            desencriptar(fecha);
            desencriptar(empleado);
            desencriptar(cliente);
            desencriptar(telefono);
            desencriptar(entrada);
            desencriptar(salida);
            desencriptar(servicio);
            desencriptar(personas);
            desencriptar(iva);
            desencriptar(total);
            desencriptar(activo);
            if(leer.eof())break;
            if(strcmp(folio,f)==0){
                cout<<"DESEAS CANCELAR LA COTIZACION?\n";
                cout<<"  1.-SI\n 2.-NO\n";
                opcion=leer_int();
                switch(opcion){
                case 1:
                    itoa(0,activo,10);
                    cout<<"Continuara de manera inactiva\n";
                    break;
                case 2:
                    cout<<"Continuara activa\n";
                    break;
                default:
                    cout<<"No existe esta opcion";
                }
                f=0;
            }
            encriptar(folio);
            encriptar(fecha);
            encriptar(empleado);
            encriptar(cliente);
            encriptar(telefono);
            encriptar(entrada);
            encriptar(salida);
            encriptar(servicio);
            encriptar(personas);
            encriptar(iva);
            encriptar(total);
            encriptar(activo);
            ofstream escribir("Auxiliar.txt",ios::app);//app -> como utilizar el puntero
            cout<<folio<<'|'<<fecha<<'|'<<empleado<<'|'<<cliente<<'|'<<telefono<<'|'<<entrada<<'|'<<salida<<'|'
               <<servicio<<'|'<<personas<<'|'<<iva<<'|'<<total<<'|'<<activo<<'!';
            escribir<<folio<<'|'<<fecha<<'|'<<empleado<<'|'<<cliente<<'|'<<telefono<<'|'<<entrada<<'|'<<salida<<'|'
                   <<servicio<<'|'<<personas<<'|'<<iva<<'|'<<total<<'|'<<activo<<'!';
            escribir.close();
        }
        leer.close();
        remove("Cotizacion.txt");
        rename("Auxiliar.txt","Cotizacion.txt");
    }

}

void Cotizacion::eliminar(char f[])
{
    int i;

    ifstream leer("Cotizacion.txt");

    if(!leer.good())
    {
        cout<<"No existe archivo";
    }
    else
    {
        while(!leer.eof())
        {
            cout<<"-----   Cotizacion  ------\n";
            i=0;
            do
            {
                leer.read((char*)& folio[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(folio[i-1]!='|');
            folio[i-1]='\0';
            //fecha
            i=0;
            do
            {
                leer.read((char*)& fecha[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(fecha[i-1]!='|');
            fecha[i-1]='\0';
            //empleado
            i=0;
            do
            {
                leer.read((char*)& empleado[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(empleado[i-1]!='|');
            empleado[i-1]='\0';
            //cliente
            i=0;
            do
            {
                leer.read((char*)& cliente[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(cliente[i-1]!='|');
            cliente[i-1]='\0';
            //telefono
            i=0;
            do
            {
                leer.read((char*)& telefono[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            //entrada
            i=0;
            do
            {
                leer.read((char*)& entrada[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(entrada[i-1]!='|');
            entrada[i-1]='\0';
            //salida
            i=0;
            do
            {
                leer.read((char*)& salida[i],1);
                if(leer.eof())break;
                i++;
            }while(salida[i-1]!='|');
            salida[i-1]='\0';
            //serrvicio
            i=0;
            do
            {
                leer.read((char*)& servicio[i],1);
                if(leer.eof())break;
                i++;
            }while(servicio[i-1]!='|');
            servicio[i-1]='\0';
            //personas
            i=0;
            do
            {
                leer.read((char*)& personas[i],1);
                if(leer.eof())break;
                i++;
            }while(personas[i-1]!='|');
            personas[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& iva[i],1);
                if(leer.eof())break;
                i++;
            }while(iva[i-1]!='|');
            iva[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& total[i],1);
                if(leer.eof())break;
                i++;
            }while(total[i-1]!='|');
            total[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& activo[i],1);
                if(leer.eof())break;
                i++;
            }while(activo[i-1]!='!');
            activo[i-1]='\0';
            desencriptar(folio);
            desencriptar(fecha);
            desencriptar(empleado);
            desencriptar(cliente);
            desencriptar(telefono);
            desencriptar(entrada);
            desencriptar(salida);
            desencriptar(servicio);
            desencriptar(personas);
            desencriptar(iva);
            desencriptar(total);
            desencriptar(activo);
            if(leer.eof())break;
            if(strcmp(folio,f)!=0){
                ofstream escribir("Auxiliar.txt",ios::app);//app -> como utilizar el puntero
                encriptar(folio);
                encriptar(fecha);
                encriptar(empleado);
                encriptar(cliente);
                encriptar(telefono);
                encriptar(entrada);
                encriptar(salida);
                encriptar(servicio);
                encriptar(personas);
                encriptar(iva);
                encriptar(total);
                encriptar(activo);
                escribir<<folio<<'|'<<fecha<<'|'<<empleado<<'|'<<cliente<<'|'<<telefono<<'|'<<entrada<<'|'<<salida<<'|'
                       <<servicio<<'|'<<personas<<'|'<<iva<<'|'<<total<<'|'<<activo<<'!';
                escribir.close();
            }

        }

    }
    leer.close();
    remove("Cotizacion.txt");
    rename("Auxiliar.txt","Cotizacion.txt");

}


void Cotizacion::buscar(char f[])
{
    int i;

    ifstream leer("Cotizacion.txt");

    if(!leer.good())
    {
        cout<<"No existe archivo";
    }
    else
    {
        while(!leer.eof())
        {
            cout<<"-----   Cotizacion  ------\n";
            i=0;
            do
            {
                leer.read((char*)& folio[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(folio[i-1]!='|');
            folio[i-1]='\0';
            //fecha
            i=0;
            do
            {
                leer.read((char*)& fecha[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(fecha[i-1]!='|');
            fecha[i-1]='\0';
            //empleado
            i=0;
            do
            {
                leer.read((char*)& empleado[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(empleado[i-1]!='|');
            empleado[i-1]='\0';
            //cliente
            i=0;
            do
            {
                leer.read((char*)& cliente[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(cliente[i-1]!='|');
            cliente[i-1]='\0';
            //telefono
            i=0;
            do
            {
                leer.read((char*)& telefono[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            //entrada
            i=0;
            do
            {
                leer.read((char*)& entrada[i],1);//lleva 2 parametros donde-> asignar valor y -> cuantos bytes quieres leer
                if(leer.eof())break;
                i++;
            }while(entrada[i-1]!='|');
            entrada[i-1]='\0';
            //salida
            i=0;
            do
            {
                leer.read((char*)& salida[i],1);
                if(leer.eof())break;
                i++;
            }while(salida[i-1]!='|');
            salida[i-1]='\0';
            //serrvicio
            i=0;
            do
            {
                leer.read((char*)& servicio[i],1);
                if(leer.eof())break;
                i++;
            }while(servicio[i-1]!='|');
            servicio[i-1]='\0';
            //personas
            i=0;
            do
            {
                leer.read((char*)& personas[i],1);
                if(leer.eof())break;
                i++;
            }while(personas[i-1]!='|');
            personas[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& iva[i],1);
                if(leer.eof())break;
                i++;
            }while(iva[i-1]!='|');
            iva[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& total[i],1);
                if(leer.eof())break;
                i++;
            }while(total[i-1]!='|');
            total[i-1]='\0';
            i=0;
            do
            {
                leer.read((char*)& activo[i],1);
                if(leer.eof())break;
                i++;
            }while(activo[i-1]!='!');
            activo[i-1]='\0';
            desencriptar(folio);
            desencriptar(fecha);
            desencriptar(empleado);
            desencriptar(cliente);
            desencriptar(telefono);
            desencriptar(entrada);
            desencriptar(salida);
            desencriptar(servicio);
            desencriptar(personas);
            desencriptar(iva);
            desencriptar(total);
            desencriptar(activo);
            if(leer.eof())break;
            if(strcmp(folio,f)==0){

                cout<<folio<<'|'<<fecha<<'|'<<empleado<<'|'<<cliente<<'|'<<telefono<<'|'<<entrada<<'|'<<salida<<'|'
                       <<servicio<<'|'<<personas<<'|'<<iva<<'|'<<total<<'|'<<activo<<'!';
            }

        }

    }
    leer.close();
}


void encriptar(char *bus){
    int longitud;
    int i=0;
    longitud=strlen(bus);
    while(i<longitud)
    {
        if(bus[i]=='.'){

        }else{
        bus[i]=bus[i]-1;
        bus[i]=bus[i]^llave;
        bus[i]=bus[i]+1;
        }
        i++;
    }
}
void desencriptar(char *bus){
    int longitud;
    int i=0;
    longitud=strlen(bus);
    while(i<longitud)
    {
        if(bus[i]=='.'){

        }else{
            bus[i]=bus[i]-1;
            bus[i]=bus[i]^llave;
            bus[i]=bus[i]+1;
        }
        i++;
    }
}
#endif // COTIZACION_H
