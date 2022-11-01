/*
Ej. 14: Una empresa de cable desea actualizar el archivo de series que emite por sus distintos canales,
con material nuevo. Para ello posee los siguientes archivos:
a) un archivo maestro de series, Series.dat, con un registro con los datos de cada series, ordenado
ascendente por Id_Serie, con el siguiente diseño:
a.1) Id_Serie a.2) Título de la serie a.3) Genero
( 9 dígitos ) (20 caracteres) ( 10 caracteres)
b) otro archivo de novedades de series, NovSeries.dat, con el mismo diseño y orden que el archivo
anterior, que contiene las novedades a incorporar.
Se pide desarrollar la metodología necesaria para escribir un algoritmo que Grabe un archivo maestro de
series actualizado, ActSeries.dat, con el mismo diseño y orden que los anteriores.
*/
#include <iostream>
#include <string.h>


struct serie
{
    int id;
    char titulo[21];
    char genero[11];    
};


int main()
{
    FILE* series = fopen("Series.dat","rb");
    FILE* novSeries = fopen("NovSeries.dat","rb");
    FILE* actSeries = fopen("ActSeries.dat","wb");

    serie rSerie;
    serie rNovSerie;

    fread( &rSerie, sizeof(serie), 1 , series);
    fread( &rNovSerie, sizeof(serie), 1 , novSeries);

    while (!feof(series) && !feof(novSeries))
    {
        if (rSerie.id < rNovSerie.id)
        {
            fwrite ( &rSerie, sizeof(serie), 1 , actSeries );
            fread ( &rSerie, sizeof(serie), 1 , series );
        }else
        {
            fwrite ( &rNovSerie,sizeof(serie), 1 , actSeries);
            fread ( &rNovSerie, sizeof(serie), 1 , novSeries);
        }
    }

    while (!feof(series))
    {
            fwrite ( &rSerie,sizeof(serie), 1 , actSeries );
            fread ( &rSerie, sizeof(serie), 1 , series );
    }

    while (!feof(novSeries))
    {
            fwrite ( &rNovSerie,sizeof(serie), 1 , actSeries );
            fread ( &rNovSerie, sizeof(serie), 1 , novSeries );
    }

    fclose(series);
    fclose(novSeries);
    fclose(actSeries);

    actSeries = fopen("ActSeries.dat","rb");

    
    FILE* actSeriesTxt = fopen("ActSeries.txt", "wt+");

    fread ( &rSerie, sizeof(serie), 1, actSeries );

    fprintf( actSeries,"ID\t\tTitulo\t\tGenero\n\n" );
    
    while (!feof(actSeries))
    {
        fprintf( actSeriesTxt,"%d\t\t%s\t\t%s\n", rSerie.id, rSerie.titulo, rSerie.genero);
        fread ( &rSerie, sizeof(serie), 1, actSeries);
    }
    fclose (actSeries);
    fclose (actSeriesTxt);


    getchar();
    return 0;
}