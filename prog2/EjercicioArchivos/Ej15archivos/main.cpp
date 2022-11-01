/*
Ej. 15: El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el
depósito, para realizar las compras del mes.
Para ello cuenta con dos archivos:
a) StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el local, con el siguiente diseño:
a.1) Código de libro ( 4 dígitos )
a.3) Autor (20 caracteres)
a.6) Stock en el local (char)
a.2) Título del libro (30 caracteres)
a.4) Editorial (20 caracteres)
a.7) Genero ( 10 caracteres)
b) StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el depósito, con el siguiente diseño:
b.1) Código de libro ( 4 dígitos ) b.2) Stock en depósito (unsigned char)
Se pide desarrollar la metodología necesaria para escribir un algoritmo que emita un listado ordenado por
código de libro, con un renglón por cada libro que tenga faltante en stock sea en depósito, local o en
ambos lugares, con el siguiente formato:
*/
#include <iostream>
#include <string.h>

struct libroLocal
{
    int cod;
    char autor[21];
    char stock;
    char titulo[31];
    char editorial[21];
    char genero[11];
};

struct libroDepo
{
    int cod;
    unsigned char stock;
};



int main()
{
    FILE* stockLocal = fopen("StockEnLocal.dat","rb");
    FILE* stockDepo = fopen("StockEnDeposito.dat","rb");
    FILE* faltantes = fopen("faltantes.dat","wb+");

    libroLocal rLibroL;
    libroDepo rLibroD;

    fread( &rLibroL, sizeof(libroLocal), 1 , stockLocal);
    fread( &rLibroD, sizeof(libroDepo), 1 , stockDepo);

    printf("\t\t\tLibros Faltantes\n");
    printf("Codigo\t\tObservaciones\n");

    while (!feof(stockLocal) && !feof(stockDepo))
    {
        if (rLibroL.cod == rLibroD.cod)
        {
            if (rLibroL.stock == 0 && rLibroD.stock==0)
            {
                //printf falta en Local y en Deposito
                printf ("%d\t\tFalta en Local y deposito", rLibroL.cod);
            }else
            {
                if (rLibroL.stock == 0 && rLibroD.stock>0)
                {
                    //printf falta en local
                    printf ("%d\t\tFalta en Local", rLibroL.cod);
                }else
                {
                    if (rLibroL.stock > 0 && rLibroD.stock == 0)
                    {
                        //printf falta en deposito
                        printf ("%d\t\tFalta en Deposito", rLibroD.cod);
                    }
                }
            }
            fread( &rLibroL, sizeof(libroLocal), 1 , stockLocal);
            fread( &rLibroD, sizeof(libroDepo), 1 , stockDepo);
        }else
        {
            if (rLibroL.cod < rLibroD.cod)
            {
                if (rLibroL.stock == 0 )
                {
                    //printf falta en local
                    printf ("%d\t\tFalta en Local", rLibroL.cod);
                }
                fread( &rLibroL, sizeof(libroLocal), 1 , stockLocal);
            }
            else
            {
                if (rLibroD.stock == 0 )
                {
                    //printf falta en deposito
                    printf ("%d\t\tFalta en deposito", rLibroD.cod);
                }
                fread( &rLibroD, sizeof(libroDepo), 1 , stockDepo);
            }
        }
    }

    while (!feof(stockLocal))
    {
        if (rLibroL.stock == 0 )
        {
            //prinf falta en local
            printf ("%d\t\tFalta en Local", rLibroL.cod);
        }
        fread( &rLibroL, sizeof(libroLocal), 1 , stockLocal);
    }

    while (!feof(stockDepo))
    {
        if (rLibroD.stock ==0 )
        {
            //printf falta en deposito
            printf ("%d\t\tFalta en deposito", rLibroD.cod);
        }
        fread( &rLibroD, sizeof(libroDepo), 1 , stockDepo);
    }

    fclose(stockLocal);
    fclose(stockDepo);
    fclose(faltantes);


    getchar();
    return 0;
}