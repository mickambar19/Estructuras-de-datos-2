#ifndef CONTACTO_H
#define CONTACTO_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "leerentero.h"
#define MAX 50
using namespace std;

class Contacto
{
public:
    char nombre[MAX];
    char grado[MAX];
    char grupo[MAX];
    char maestra[MAX];
    char mama[MAX];
    char cel_ma[MAX];
    char papa[MAX];
    char cel_pa[MAX];
    char tel[MAX];
    char trabajo[MAX];
    char email[MAX];
public:
    Contacto();
    void capturar();
    void mostrar();
    bool modificar(char abus[MAX]);
    bool buscar(char abus[MAX]);
    bool eliminar(char abus[MAX]);
    void mostrar_grado_grupo(char gradoBus[MAX],char grupoBus[MAX]);
};

#endif // CONTACTO_H
