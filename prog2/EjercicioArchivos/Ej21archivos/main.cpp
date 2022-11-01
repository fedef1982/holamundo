/*
Ej. 21: Una empresa de aviación realiza 500 vuelos semanales a distintos puntos del país y requiere
desarrollar un programa para la venta de pasajes.

Para ello dispone de un archivo “Vuelos.dat”, con un registro por cada uno de los 500 vuelos que
realiza, sin ningún orden, con el siguiente diseño de registro:
a.1) código de vuelo (6 caracteres) 
a.2) cantidad de pasajes disponibles (3 dígitos) 

También se dispone
de otro archivo “Compradores.dat”, con los potenciales compradores y con el siguiente diseño de registro:
b.1) código de vuelo 
b.2) cantidad de pasajes solicitados (3 dígitos)
b.3) DNI del solicitante (8 dígitos) 
b.4) apellido y nombre del solicitante (25 caracteres)

Se pide:
1) Para los solicitantes a los cuales se les venden pasajes, emitir el siguiente listado:
DNI         Apellido y Nombre        Cantidad de pasajes    Código de Vuelo
99999999    xxxxxxxxxxxxxxxxxxxxxxxx 999                    999
99999999    xxxxxxxxxxxxxxxxxxxxxxxx 999                    999

2) Al final del proceso emitir el siguiente listado ordenado por código de vuelo
Código de Vuelo Pasajes disponibles Pasajes no vendidos
BUE999          999                 999
XXX999          999                 999

Nota: Se le vende al solicitante si la cantidad de pasajes que solicita está disponible, 
en caso contrario se computa como pasajes no vendidos. 

Desarrolle el ejercicio utilizando la siguiente estructura de datos:
Array de registro: VECTOR : array [1..500] of treg. Bytes que ocupa = (7 + 2 + 2) *500 = 5500 bytes

CODIGOV             PASAJESDISP     PASAJESNOV
char[7] (7 bytes)   short (2 bytes) short (2 bytes)
*/


#include <iostream>
#include <string.h>
using namespace std;
#define MAX_BUFFER 255
#define MAX_VECTOR 500

struct Vuelo{
    char cod[7]; //a.1) código de vuelo (6 caracteres) 
    short pasajeDisp; // a.2) cantidad de pasajes disponibles (3 dígitos) 
};

struct Comprador{
    char cod[7]; //b.1) código de vuelo 
    short pasajeComp; //b.2) cantidad de pasajes solicitados (3 dígitos)
    int dni; //b.3) DNI del solicitante (8 dígitos) 
    char nombre[25]; //b.4) apellido y nombre del solicitante (25 caracteres)
};

struct VueloAct
{
    char cod[7];
    short pasajesDisp;
    short pasajesNoV;
};


void leerVuelo(Vuelo &vuelo,FILE *vuelos);
void leerComprador(Comprador &comprador,FILE *compradores);
int busquedaBinariaVector(VueloAct vector[], int tamano, char cod[7]);
void ordenarVector(VueloAct arreglo[], int tamano);
void intercambiar(VueloAct &a, VueloAct &b);

int main()
{
    FILE *vuelos= fopen("VUELOS.TXT","r");
    FILE *compradores= fopen("COMPRADORES.TXT","r");
    
    Vuelo regVuelo;
    Comprador regComp;
    VueloAct vuelosAct[MAX_VECTOR];

    leerVuelo(regVuelo,vuelos);
    int i=0;

    while (!feof(vuelos))
    {
        strcpy(vuelosAct[i].cod,regVuelo.cod);
        vuelosAct[i].pasajesDisp = regVuelo.pasajeDisp;
        vuelosAct[i].pasajesDisp = 0;
        i++;
        leerVuelo(regVuelo,vuelos);
    }
    fclose (vuelos);

    ordenarVector(vuelosAct,MAX_VECTOR);

    leerComprador(regComp,compradores);
    while (!feof(compradores))
    {
        if (busquedaBinariaVector(vuelosAct,MAX_VECTOR,regComp.cod)!=-1)
        {
            
        }
        leerComprador(regComp,compradores);
    }

    // Imprimir listado desde Vector vuelosAct

    fclose (compradores);
    getchar();
    return 0;
}

void leerVuelo(Vuelo &vuelo,FILE *vuelos)
{
    char buffer[MAX_BUFFER];
    if (fgets (buffer, MAX_BUFFER, vuelos)!=NULL)
    {
        strcpy(vuelo.cod,strtok(buffer, ","));
        vuelo.pasajeDisp = atoi(strtok(NULL,","));
    }  
    return;
}

void leerComprador(Comprador &comprador,FILE *compradores)
{
    char buffer[MAX_BUFFER];
    if (fgets (buffer, MAX_BUFFER, compradores)!=NULL)
    {
        strcpy(comprador.cod,strtok(buffer, ","));
        comprador.pasajeComp = atoi(strtok(NULL,","));
        comprador.dni = atoi(strtok(NULL,","));
        strcpy(comprador.cod,strtok(NULL, ",\n"));
    }  
    return;
}

int busquedaBinariaVector(VueloAct arreglo[], int tamano, char cod[7])
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (strcmp(arreglo[Icentro].cod,cod)>=0)
 return Icentro;
      else
 if (strcmp(arreglo[Icentro].cod,cod)<0)
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}
void ordenarVector(VueloAct arreglo[], int tamano)
{
  for (int i = 0; i< tamano -1 ; i++)
  {
    for (int j = 0; j< tamano -1 ; j++)
    {
      if (strcmp(arreglo[j].cod,arreglo[j+1].cod)>0)
      {
        intercambiar(arreglo[j],arreglo[j+1]);
      }
    }
  }
}

void intercambiar(VueloAct &a, VueloAct &b)
{
  VueloAct tmp = b;
  b = a;
  a = tmp;
}