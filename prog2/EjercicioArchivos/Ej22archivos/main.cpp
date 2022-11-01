/*
Ej. 22: Una empresa que distribuye mercadería hacia distintas localidades del interior dispone de los
siguientes archivos:
Un archivo “Destinos.dat”, con información de la distancia a cada uno de los destinos y con
el siguiente diseño de registro:
a.1) número de destino (3 dígitos) a.2) distancia en kilómetros (float)
También se dispone de otro archivo “Viajes.dat”, con los viajes realizados por cada camión y con el
siguiente diseño de registro:
b.1) patente del camión (6 caracteres, no son más de 200 camiones) b.2) número de destino b.3) número
de chofer (1..150)
Se pide desarrollar la metodología necesaria para realizar un programa que informe:
1. Cantidad de viajes realizados a cada destino
2. Número de chofer con menor cantidad de km recorridos
3. Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.
*/
#include<iostream>
#include<string.h>
using namespace std;

struct Destino
{
    int id; 
    float distancia;
};

struct Viaje
{
    char patente[6]; 
    int idDestino;
    int chofer; 
};


void cargarDestinos(FILE* destinos);
void cargarViajes(FILE* viajes);

int main()
{
    FILE* destinos = fopen("destinos.dat", "wb");
    FILE* viajes = fopen("viajes.dat", "wb");

    cargarDestinos(destinos);
    fclose(destinos);
    cargarViajes(viajes);
    fclose(viajes);

    destinos = fopen("destinos.dat", "rb");

    float kmXdestinos[1000]={};
    int viajesXdestinos[1000]={};
    float kmXchofer[150]={};
    char patentes116[1200]={};

    // cargo vector Kilometros x destino
    Destino rDestino;
   
    fread(&rDestino,sizeof(Destino),1,destinos);
    while (!feof(destinos))
    {        
       kmXdestinos[rDestino.id-1] = rDestino.distancia;
       fread(&rDestino,sizeof(Destino),1,destinos); 
    }


    // recorroViajes y completo kmXChofer y pantentes destino 116
    viajes = fopen("viajes.dat", "rb");
    Viaje rViaje;

    fread(&rViaje,sizeof(Viaje),1,viajes);
    int i=0;
    while (!feof(viajes))
    {  
       viajesXdestinos[rViaje.idDestino-1]++;      
       kmXchofer[rViaje.chofer-1] += kmXdestinos[rViaje.idDestino-1];
       if (rViaje.idDestino==116);
       {
            for (int j=0;j<6;j++)
            {
                patentes116[i*6+j] = rViaje.patente[j];
            }       
            i++;
       }
       fread(&rViaje,sizeof(Viaje),1,viajes); 
    }

    // 1 imprimo cant viajes a cada destio con viajes
    printf("\nViajes por destino\n");

    for (int i = 0; i < 1000; i++)
    {
        if (viajesXdestinos[i] > 0)
        {
            printf("Cantidad de viajes al destino %d fue de %d\n", i+1, viajesXdestinos[i]);
        }
    }

    // 2 imprimo kilometros por chofer

    printf("\nKilometros por chofer\n");
    
    for (int i = 0; i < 150; i++)
    {
        if (kmXchofer[i] > 0)
        {
            printf("Cantidad de kilometros del chofer %d fue de %.2f\n", i+1, kmXchofer[i]);
        }
    }

    //3 patentes destino 116

    printf("\nPatentes que fueron al destino 116\n");
    i=0;
    while ( patentes116[i]>='A' && patentes116[i]<='Z' )
    {
            printf("Patente ");
            for (int j=0; j<6 ; j++)
            {
                printf("%c",patentes116[i*6+j]);
            }
            printf("\n");                                    
        i+=6;
    }


    fclose(destinos);
    fclose(viajes);    
    getchar();
    return 0;
}

void cargarDestinos(FILE* destinos)
{
    for (int i = 1; i<1000; i++)
    {
        if (i%4==0)
        {
            Destino rDestino;
            rDestino.id=i;
            rDestino.distancia=i*3.14;
            printf("rDestino.id: %d, rDestin.distancia %.2f\n",rDestino.id,rDestino.distancia);
            fwrite(&rDestino,sizeof(Destino),1,destinos);
        }
    }
    return;
}

void cargarViajes(FILE* viajes)
{
    char p1='A';
    char p2='B';
    char p3='C';
    char p4='D';
    char p5='E';
    char p6='F';

    for (int i = 1; i<150; i++)
    {
        if (i%3==0)
        {
            Viaje rViaje;
            rViaje.idDestino=4*i;
            if (i%9==0) rViaje.idDestino=116;
            rViaje.chofer=i;
            
            rViaje.patente[0]= p1;   
            rViaje.patente[1]= p2;
            rViaje.patente[2]= p3;
            rViaje.patente[3]= p4;
            rViaje.patente[4]= p5;
            rViaje.patente[5]= p6;
            p1++; p2++;p3++; p4++; p5++; p6++;
            if(p1++>'T')
            {
                p1='A';p2='B'; p3='C'; p4='D'; p5='E'; p6='F';
            }
            printf("rViaje.Destino %d, rViaje.chofer %d, rViaje.patente %c%c%c %c%c%c\n",
                                                        rViaje.idDestino, rViaje.chofer, 
                                                        rViaje.patente[0],rViaje.patente[1],
                                                        rViaje.patente[2], rViaje.patente[3],
                                                        rViaje.patente[4], rViaje.patente[5]);
            fwrite(&rViaje,sizeof(Viaje),1,viajes);
        }
    }
    for ( int i = 1; i<150; i++)
    {
        if (i%5==0)
        {
            Viaje rViaje;
            rViaje.idDestino=4*i;
            if (i%15==0) rViaje.idDestino=116;

            rViaje.chofer=i;
            
            rViaje.patente[0]= p1;   
            rViaje.patente[1]= p2;
            rViaje.patente[2]= p3;
            rViaje.patente[3]= p4;
            rViaje.patente[4]= p5;
            rViaje.patente[5]= p6;
            p1++; p2++;p3++; p4++; p5++; p6++;
            if(p1++>'T')
            {
                p1='A';p2='B'; p3='C'; p4='D'; p5='E'; p6='F';
            }

            printf("rViaje.Destino %d, rViaje.chofer %d, rViaje.patente %c%c%c %c%c%c\n",
                                                        rViaje.idDestino, rViaje.chofer, 
                                                        rViaje.patente[0],rViaje.patente[1],
                                                        rViaje.patente[2], rViaje.patente[3],
                                                        rViaje.patente[4], rViaje.patente[5]);

            fwrite(&rViaje,sizeof(Viaje),1,viajes);
        }
    }

    for ( int i = 1; i<150; i++)
    {
        if (i%7==0)
        {
            Viaje rViaje;
            rViaje.idDestino=4*i;
            if (i%21==0) rViaje.idDestino=116;

            rViaje.chofer=i;
            
            rViaje.patente[0]= p1;   
            rViaje.patente[1]= p2;
            rViaje.patente[2]= p3;
            rViaje.patente[3]= p4;
            rViaje.patente[4]= p5;
            rViaje.patente[5]= p6;
            p1++; p2++;p3++; p4++; p5++; p6++;
            if(p1++>'T')
            {
                p1='A';p2='B'; p3='C'; p4='D'; p5='E'; p6='F';
            }
            printf("rViaje.Destino %d, rViaje.chofer %d, rViaje.patente %c%c%c %c%c%c\n",
                                                        rViaje.idDestino, rViaje.chofer, 
                                                        rViaje.patente[0],rViaje.patente[1],
                                                        rViaje.patente[2], rViaje.patente[3],
                                                        rViaje.patente[4], rViaje.patente[5]);
            fwrite(&rViaje,sizeof(Viaje),1,viajes);
        }
    }



}