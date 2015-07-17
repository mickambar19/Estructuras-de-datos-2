#ifndef AHOFFMAN_H
#define AHOFFMAN_H
#include "Pila.h"
#include "ABinario.h"
#include <fstream>
#include "leerentero.h"
#include <iostream>
#include <string>
using namespace std;
void contar_letras(int a);
string cambiaracodigo(char a);
void cambiaraletra(string a);
NodoArbol<Letra>* creacion_de_Arbol(Pila<Letra> a);
Letra arreglo[37]={};
string filename="Dulce.txt";
string newfilename="HoffmandeDulce.txt";

void ahoffman()
{
    for(int i=0;i<37;i++){
        arreglo[i].setNum(0);
    }
    int a;
    char letra;
    int i=0;
    int antes=0;
    int totalbits=0;
    Codigo codo;
    string cadena;
    string codificado;
    ABB<Letra> hoff;
    Pila<Letra> pila;
    NodoArbol<Letra>* raiz;
    NodoArbol<Letra>* nodo;
    NodoCodigo<Codigo>* ncodo;
    cout<<"Escriba el nombre del archivo a leer: "<<endl;
    ifstream leer(filename.c_str());
    if(!leer.good())
    {
        cout << "Error no se puede abrir el archivo: " << filename << endl;

    }
    else{
        string linea="";
        while(getline(leer, linea))
            cadena += linea;
        cout<<"ESTE ES EL CONTENIDO DEL TEXTO:\n"<<cadena<<endl;
        int longitud=cadena.length();
        cout<<longitud<<endl<<endl;
        while(i<longitud){
            a=cadena[i];
            contar_letras(a);
            i++;
        }
        for(i=0;i<26;i++)
        {
            letra=i+97;
            if(arreglo[i].getNum()!=0){
                arreglo[i].setLetra(letra);
                nodo=new NodoArbol<Letra>(arreglo[i]);
                pila.push(nodo);
            }

        }
        for(i=26;i<36;i++)
        {
            letra=i+22;
            if(arreglo[i].getNum()!=0){
                arreglo[i].setLetra(letra);
                nodo=new NodoArbol<Letra>(arreglo[i]);
                pila.push(nodo);
            }

        }
        if(arreglo[36].getNum()!=0)
        {
            arreglo[36].setLetra('_');
            nodo=new NodoArbol<Letra>(arreglo[36]);
            pila.push(nodo);
        }
        pila.order();
        raiz=creacion_de_Arbol(pila);
        hoff.setRaiz(raiz);
        hoff.enOrden();

        for(i=0;i<26;i++)
        {
            letra=i+97;
            if(arreglo[i].getNum()!=0){
                antes+=arreglo[i].getNum();
                codo.setLetra(arreglo[i]);
                ncodo=lcodigos.linealSearch(codo);
                cout<<"letra:"<<codo.getLetra().getLetra()<<endl;
                cout<<"veces:"<<codo.getLetra().getNum()<<endl;
                cout<<"codigo:"<<ncodo->getData().getCod()<<endl;
                cout<<"Totbits antes:"<<arreglo[i].getNum()<<endl;
                cout<<"totbits:"<<((ncodo->getData().getCod().length())*(codo.getLetra().getNum()))<<endl;
                cout<<"______________\n";
                totalbits+=((ncodo->getData().getCod().length())*(codo.getLetra().getNum()));
            }

        }
        for(i=26;i<36;i++)
        {
            letra=i+22;
            if(arreglo[i].getNum()!=0){
                antes+=arreglo[i].getNum();
                codo.setLetra(arreglo[i]);
                ncodo=lcodigos.linealSearch(codo);
                cout<<"letra:"<<codo.getLetra().getLetra()<<endl;
                cout<<"veces:"<<codo.getLetra().getNum()<<endl;
                cout<<"codigo:"<<ncodo->getData().getCod()<<endl;
                cout<<"Totbits antes:"<<arreglo[i].getNum()<<endl;
                cout<<"totbits:"<<((ncodo->getData().getCod().length())*(codo.getLetra().getNum()))<<endl;
                cout<<"______________\n";
                totalbits+=((ncodo->getData().getCod().length())*(codo.getLetra().getNum()));
            }

        }
        if(arreglo[36].getNum()!=0)
        {
            antes+=arreglo[i].getNum();
            codo.setLetra(arreglo[36]);
            ncodo=lcodigos.linealSearch(codo);
            cout<<"letra:"<<codo.getLetra().getLetra()<<endl;
            cout<<"veces:"<<codo.getLetra().getNum()<<endl;
            cout<<"codigo:"<<ncodo->getData().getCod()<<endl;
            cout<<"Totbits antes:"<<arreglo[i].getNum()<<endl;
            cout<<"totbits:"<<((ncodo->getData().getCod().length())*(codo.getLetra().getNum()))<<endl;
            cout<<"______________\n";
            totalbits+=((ncodo->getData().getCod().length())*(codo.getLetra().getNum()));
        }
        antes=antes*8;
        cout<<"TOTAL BITS DOCUMENTO(ANTES): "<<antes<<endl;
        cout<<"TOTAL BITS DOCUMENTO(DESPUES): "<<totalbits<<endl;
        cout<<"REDUCCION DE:"<<100-((totalbits*100)/antes)<<"%"<<endl;
        ofstream resultados("Resultados.txt",ios::app);
        resultados<<filename<<endl<<"TOTAL BITS DOCUMENTO(ANTES): "<<antes<<endl
                 <<"TOTAL BITS DOCUMENTO(DESPUES): "<<totalbits<<endl
                <<"REDUCCION DE:"<<100-((totalbits*100)/antes)<<"%"<<endl
               <<"_______________________\n";
        resultados.close();
        int menuhoffman;
        //cambiar a codigo o decodificar
        cout<<"Elige opcion:\n";
        cout<<"1.-Deseas codificar\n";
        cout<<"2.-Deseas decodificar\n";
        menuhoffman=leer_int();
        switch (menuhoffman) {
        case 1:{
            i=0;
            while(i<longitud){
                if(cadena[i]!=' '){
                    codificado=cambiaracodigo(cadena[i]);
                }else{
                    codificado=cambiaracodigo('_');
                }
                i++;
            }
            cout<<endl;
        }
            break;
        case 2:{
            string cd;
            char aux;
            ifstream ades("Descomprimir.txt");
            if(!ades.good()){
                cout<<"tu archivo a descomprimir no existe\n";
            }else{
                while(!ades.eof()){
                    cd="";
                    do
                    {
                        ades.read((char *)&aux,sizeof(char));
                        if(aux!='|') {
                            cd+=aux;
                        }
                    }while(aux!='|');
                    cambiaraletra(cd);

                    if(ades.eof())break;
                }
            }
            ades.close();
        }
            break;
        default:
            break;
        }
        cout<<endl;
        lcodigos.deleteAll();
    }

}

void contar_letras(int a){
    int i=0;
    int numveces;
    int aux=' ';
    if(a==aux){
        numveces=arreglo[36].getNum();
        numveces+=1;
        arreglo[36].setNum(numveces);
    }
    else{
        for(int x=97;x<123;x++){
            if(a==x){
                numveces=arreglo[i].getNum();
                numveces+=1;
                arreglo[i].setNum(numveces);
            }
            i++;
        }
        for(int x=48;x<58;x++){
            if(a==x){
                numveces=arreglo[i].getNum();
                numveces+=1;
                arreglo[i].setNum(numveces);
            }
            i++;
        }
    }
}

NodoArbol<Letra>* creacion_de_Arbol(Pila<Letra> a){
    NodoArbol<Letra>* x;
    NodoArbol<Letra>* y;
    NodoArbol<Letra>* res;
    NodoArbol<Letra>* raiz;
    int s;
    Letra suma;
    if(a.isEmpty()){
        cout<<"Tu pila esta vacia\n";
        return NULL;
    }else if(a.first()->getNext()==NULL){
        return a.first()->getData();
    }else{
        x=a.pop();
        y=a.pop();
        s=x->getElemento().getNum()+y->getElemento().getNum();
        suma.setNum((s));
        suma.setLetra('!');
        res=new NodoArbol<Letra>(x,suma,y);
        a.push(res);
        a.order();
        if(a.isEmpty())return res;
        raiz=creacion_de_Arbol(a);
    }
    return raiz;
}

string cambiaracodigo(char a){
    Codigo cod;
    string b;
    Letra letra;
    letra.setLetra(a);
    cod.setLetra(letra);
    if(lcodigos.linealSearch(cod)!=NULL){
        cout<<lcodigos.linealSearch(cod)->getData().getCod();
        b=lcodigos.linealSearch(cod)->getData().getCod();
    }
    ofstream esc(newfilename.c_str(),ios::app);
    ofstream escD("Descomprimir.txt",ios::app);
    esc<<b;
    escD<<b<<'|';
    esc.close();
    escD.close();

    return b;
}

void cambiaraletra(string a){
    NodoCodigo<Codigo>* cnodo;
    cnodo=lcodigos.first();
    while(cnodo!=NULL){
        if(cnodo->getData().getCod()==a){
            if(cnodo->getData().getLetra().getLetra()=='_'){
                cout<<" ";}
            else{
                  cout<<cnodo->getData().getLetra().getLetra();
            }
        }
        if(cnodo->getNext()==NULL){break;}
        cnodo=cnodo->getNext();
    }
    /*if(lcodigos.linealSearch(cod)!=NULL){
        cout<<lcodigos.linealSearch2(cod)->getData()<<endl;
    }*/

}
#endif // AHOFFMAN_H
