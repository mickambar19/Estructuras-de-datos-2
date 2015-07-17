#include "contacto.h"

Contacto::Contacto()
{

}

void Contacto::capturar()
{
    int a;
    ofstream esc("Contactos.txt",ios::app);
    cout<<"NUEVA CAPTURA\n";
    cout<<"Ingresa el nombre del estudiante:\n";
    cin.getline(nombre,MAX);
    a=strlen(nombre);
    //Se escribe el tamaño de la cadena que se guardara
    esc.write((char *)&a,sizeof(int));
    //Escritura de la cadena
    esc.write((char*)&nombre,a);

    cout<<"Ingresa el grado:\n";
    cin.getline(grado,MAX);
    a=strlen(grado);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&grado, a);

    cout<<"Ingresa el grupo:\n";
    cin.getline(grupo,MAX);
    a=strlen(grupo);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&grupo, a);

    cout<<"Ingresa el nombre de la maestra\n";
    cin.getline(maestra,MAX);
    a=strlen(maestra);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&maestra, a);

    cout<<"Ingresa el nombre de la mamá\n";
    cin.getline(mama,MAX);
    a=strlen(mama);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&mama, a);

    cout<<"Ingresar el celuar de la mamá\n";
    cin.getline(cel_ma,MAX);
    a=strlen(cel_ma);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&cel_ma, a);

    cout<<"Ingresa el nombre de papá\n";
    cin.getline(papa,MAX);
    a=strlen(papa);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&papa, a);

    cout<<"Ingresa el celular de papa\n";
    cin.getline(cel_pa,MAX);
    a=strlen(cel_pa);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&cel_pa, a);

    cout<<"Ingresa el telefono\n";
    cin.getline(tel,MAX);
    a=strlen(tel);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&tel, a);

    cout<<"Ingresar el trabajo\n";
    cin.getline(trabajo,MAX);
    a=strlen(trabajo);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&trabajo, a);

    cout<<"Ingresar email\n";
    cin.getline( email,MAX);
    a=strlen(email);
    esc.write((char *)&a, sizeof(int));
    esc.write((char *)&email, a);
    //Se debe de cerrar el archivo que se habia abierto
    esc.close();
}

void Contacto::mostrar()
{
    int x = 0;
    int a;
    ifstream lee("Contactos.txt");
    //Bandera para saber si se creo el archivo o exista por lo menos
    if(!lee.good())
    {
        cout<<"NO EXISTE EL ARCHIVO!!!\n";
    }
    else
    {

        while(!lee.eof())
        {
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&nombre,a);
            nombre[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&grado,a);
            grado[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&grupo,a);
            grupo[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&maestra,a);
            maestra[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&mama,a);
            mama[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&cel_ma,a);
            cel_ma[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&papa,a);
            papa[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&cel_pa,a);
            cel_pa[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&tel,a);
            tel[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&trabajo,a);
            trabajo[a]='\0';
            lee.read((char *)&a,sizeof(int));
            lee.read((char *)&email,a);
            email[a]='\0';
            if(lee.eof())break;
            cout<<"REGISTRO NO."<<x+1<<endl;
                       x++;
                       cout<< "\n Nombre ni"<<char(164)<<"o  :"  <<nombre<<"\n";
                       cout<< " Grado    :"  <<grado<<"\n";
                       cout<< " Grupo    :"  <<grupo<<"\n";
                       cout<< " Maestra  :"  <<maestra<<"\n";
                       cout<< " Mama     :"  <<mama<<"\n";
                       cout<< " Cel mama :"  <<cel_ma<<"\n";
                       cout<< " Papa     :"  <<papa<<"\n";
                       cout<< " Cel papa :"  <<cel_pa<<"\n";
                       cout<< " Telefono :"  <<tel<<"\n";
                       cout<< " Trabajo  :"  <<trabajo<<"\n";
                       cout<< " Email    :"  <<email<<"\n";
                       if(lee.eof())break;

        }
     }
     lee.close();

}

bool Contacto::buscar(char abus[])
{
    int a;
    bool located=false;
    ifstream lee("Contactos.txt");
    if(!lee.good())
    {
        cout<<"NO exste el archivo\n";
    }else
    {
       while(!lee.eof())
       {
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&nombre,a);
           nombre[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grado,a);
           grado[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grupo,a);
           grupo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&maestra,a);
           maestra[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&mama,a);
           mama[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_ma,a);
           cel_ma[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&papa,a);
           papa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_pa,a);
           cel_pa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&tel,a);
           tel[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&trabajo,a);
           trabajo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&email,a);
           email[a]='\0';
           if(lee.eof())break;
           if(strcmp(abus,nombre)==0){

                      cout<< "\n Nombre ni"<<char(164)<<"o  :"  <<nombre<<"\n";
                      cout<< " Grado    :"  <<grado<<"\n";
                      cout<< " Grupo    :"  <<grupo<<"\n";
                      cout<< " Maestra  :"  <<maestra<<"\n";
                      cout<< " Mama     :"  <<mama<<"\n";
                      cout<< " Cel mama :"  <<cel_ma<<"\n";
                      cout<< " Papa     :"  <<papa<<"\n";
                      cout<< " Cel papa :"  <<cel_pa<<"\n";
                      cout<< " Telefono :"  <<tel<<"\n";
                      cout<< " Trabajo  :"  <<trabajo<<"\n";
                      cout<< " Email    :"  <<email<<"\n";
                      located=true;


           }
       }
    }
    lee.close();
    return located;
}

bool Contacto::eliminar(char abus[])
{
    int a;
    bool located=false;
    ofstream escA("Auxiliar.txt", ios::app);
    ifstream lee("Contactos.txt");
    if(!lee.good())
    {
        cout<<"NO exste el archivo\n";
    }else
    {
       while(!lee.eof())
       {
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&nombre,a);
           nombre[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grado,a);
           grado[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grupo,a);
           grupo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&maestra,a);
           maestra[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&mama,a);
           mama[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_ma,a);
           cel_ma[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&papa,a);
           papa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_pa,a);
           cel_pa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&tel,a);
           tel[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&trabajo,a);
           trabajo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&email,a);
           email[a]='\0';
           if(lee.eof())break;
           if(strcmp(abus,nombre)==0){

                      cout<< "\n Se eliminara el ni"<<char(164)<<"o  :"  <<nombre<<"\n";
                      located=true;


           } else
           {  //guardar todos los diferentes al eliminado
               a=strlen(nombre);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&nombre, a);
               a=strlen(grado);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&grado, a);
               a=strlen(grupo);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&grupo, a);
               a=strlen(maestra);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&maestra, a);
               a=strlen(mama);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&mama, a);
               a=strlen(cel_ma);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&cel_ma, a);
               a=strlen(papa);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&papa, a);
               a=strlen(cel_pa);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&cel_pa, a);
               a=strlen(tel);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&tel, a);
               a=strlen(trabajo);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&trabajo, a);
               a=strlen(email);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&email, a);

           }
              if(lee.eof())break;
       }
    }
    lee.close();
    escA.close();
    remove("Contactos.txt");
    rename("Auxiliar.txt", "Contactos.txt");
    return located;
}

bool Contacto::modificar(char abus[])
{
    int a;
    int opc=0;
    bool located=false;
    ofstream escA("Auxiliar.txt", ios::app);
    ifstream lee("Contactos.txt");
    if(!lee.good())
    {
        cout<<"NO exste el archivo\n";
    }else
    {
       while(!lee.eof())
       {
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&nombre,a);
           nombre[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grado,a);
           grado[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grupo,a);
           grupo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&maestra,a);
           maestra[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&mama,a);
           mama[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_ma,a);
           cel_ma[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&papa,a);
           papa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_pa,a);
           cel_pa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&tel,a);
           tel[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&trabajo,a);
           trabajo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&email,a);
           email[a]='\0';
           if(lee.eof())break;
           if(strcmp(abus,nombre)==0){
                       located=true;
                       cout<<"MENU DE MODIFICACIONES\n";
                       cout<<"1.-Grado\n";
                       cout<<"2.-Grupo\n";
                       cout<<"3.-Maestra\n";
                       cout<<"4.-Mama\n";
                       cout<<"5.-Celular de mama\n";
                       cout<<"6.-Papa\n";
                       cout<<"7.-Celular de papa\n";
                       cout<<"8.-Telefono\n";
                       cout<<"9.-Trabajo\n";
                       cout<<"10.-Email\n";
                       cout<<"0.-Salir\n";
                       cout<<"Elige una opcion:\n";
                       opc=leer_int();
                       switch (opc) {
                       case 1:
                           cout<<"Ingresa el grado:\n";
                          cin.getline(grado,MAX);
                          break;
                       case 2:
                           cout<<"Ingresa el grupo:\n";
                           cin.getline(grupo,MAX);

                           break;
                       case 3:
                           cout<<"Ingresa el nombre de la maestra\n";
                           cin.getline(maestra,MAX);

                           break;
                       case 4:
                           cout<<"Ingresa el nombre de la mamá\n";
                           cin.getline(mama,MAX);

                           break;
                       case 5:
                           cout<<"Ingresar el celuar de la mamá\n";
                           cin.getline(cel_ma,MAX);

                           break;
                       case 6:
                           cout<<"Ingresa el nombre de papá\n";
                           cin.getline(papa,MAX);

                           break;
                       case 7:
                           cout<<"Ingresa el celular de papa\n";
                           cin.getline(cel_pa,MAX);

                           break;
                       case 8:
                           cout<<"Ingresa el telefono\n";
                           cin.getline(tel,MAX);

                           break;
                       case 9:
                           cout<<"Ingresar el trabajo\n";
                           cin.getline(trabajo,MAX);

                           break;
                       case 10:
                           cout<<"Ingresar email\n";
                           cin.getline( email,MAX);

                           break;
                       default:
                           break;
                       }

                       cout<<"\nMODIFICACIONES APLICADAS\n";
                      cout<< "\n Nombre ni"<<char(164)<<"o  :"  <<nombre<<"\n";
                      cout<< " Grado    :"  <<grado<<"\n";
                      cout<< " Grupo    :"  <<grupo<<"\n";
                      cout<< " Maestra  :"  <<maestra<<"\n";
                      cout<< " Mama     :"  <<mama<<"\n";
                      cout<< " Cel mama :"  <<cel_ma<<"\n";
                      cout<< " Papa     :"  <<papa<<"\n";
                      cout<< " Cel papa :"  <<cel_pa<<"\n";
                      cout<< " Telefono :"  <<tel<<"\n";
                      cout<< " Trabajo  :"  <<trabajo<<"\n";
                      cout<< " Email    :"  <<email<<"\n";
                      located=true;
                      a=strlen(nombre);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&nombre, a);
                      a=strlen(grado);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&grado, a);
                      a=strlen(grupo);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&grupo, a);
                      a=strlen(maestra);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&maestra, a);
                      escA.write((char *)&a, sizeof(int));
                      a=strlen(mama);
                      escA.write((char *)&mama, a);
                      a=strlen(cel_ma);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&cel_ma, a);
                      a=strlen(papa);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&papa, a);
                      a=strlen(cel_pa);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&cel_pa, a);
                      a=strlen(tel);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&tel, a);
                      a=strlen(trabajo);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&trabajo, a);
                      a=strlen(email);
                      escA.write((char *)&a, sizeof(int));
                      escA.write((char *)&email, a);


           }
           else
           {
               //guardar todos los diferentes al eliminado
               a=strlen(nombre);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&nombre, a);
               a=strlen(grado);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&grado, a);
               a=strlen(grupo);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&grupo, a);
               a=strlen(maestra);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&maestra, a);
               a=strlen(mama);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&mama, a);
               a=strlen(cel_ma);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&cel_ma, a);
               a=strlen(papa);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&papa, a);
               a=strlen(cel_pa);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&cel_pa, a);
               a=strlen(tel);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&tel, a);
               a=strlen(trabajo);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&trabajo, a);
               a=strlen(email);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&email, a);

           }
           if(lee.eof())break;
       }
    }
    lee.close();
    escA.close();
    remove("Contactos.txt");
    rename("Auxiliar.txt", "Contactos.txt");
    return located;
}
void Contacto::mostrar_grado_grupo(char gradoBus[],char grupoBus[])
{

    int a;
    ifstream lee("Contactos.txt");
    if(!lee.good())
    {
        cout<<"NO exste el archivo\n";
    }else
    {
       while(!lee.eof())
       {
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&nombre,a);
           nombre[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grado,a);
           grado[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&grupo,a);
           grupo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&maestra,a);
           maestra[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&mama,a);
           mama[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_ma,a);
           cel_ma[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&papa,a);
           papa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&cel_pa,a);
           cel_pa[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&tel,a);
           tel[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&trabajo,a);
           trabajo[a]='\0';
           lee.read((char *)&a,sizeof(int));
           lee.read((char *)&email,a);
           email[a]='\0';

           if(lee.eof())break;

           if(strcmp(gradoBus,grado)==0 && strcmp(grupoBus,grupo)==0){


                      cout<< "\n Nombre ni"<<char(164)<<"o  :"  <<nombre<<"\n";

                      cout<< " Maestra  :"  <<maestra<<"\n";
                      cout<< " Mama     :"  <<mama<<"\n";
                      cout<< " Cel mama :"  <<cel_ma<<"\n";
                      cout<< " Papa     :"  <<papa<<"\n";
                      cout<< " Cel papa :"  <<cel_pa<<"\n";
                      cout<< " Telefono :"  <<tel<<"\n";
                      cout<< " Trabajo  :"  <<trabajo<<"\n";
                      cout<< " Email    :"  <<email<<"\n";
           }

             if(lee.eof())break;

            }

    }
    lee.close();
}
