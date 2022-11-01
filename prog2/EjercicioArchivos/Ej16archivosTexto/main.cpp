/*
Ej. 16: Una aplicación para descargas de Series posee la información en un archivo binario,
Episodios.dat, con un registro por cada episodio, ordenado ascendente por Id_Serie y Número de
temporada, con el siguiente diseño:
1) Id_Serie ( 9 dígitos )
3) Número de temporada (1..12)
5) Cantidad de descargas (long)
2) Título del episodio (20 caracteres)
4) Número de episodio (unsigned char)
6) Fecha de última descarga (aaaammdd)
Se pide desarrollar la metodología necesaria para escribir un algoritmo emita el siguiente listado:
*/
#include <iostream>
#include <string.h>

struct Episodio
{
    // 1) Id_Serie ( 9 dígitos )
    long idSerie;
    // 3) Número de temporada (1..12)
    char temp;
    // 5) Cantidad de descargas (long)
    long descargas;
    // 2) Título del episodio (20 caracteres)
    char titulo[21];
    // 4) Número de episodio (unsigned char)
    unsigned char nro;
    // 6) Fecha de última descarga (aaaammdd)
    int fechaUD;
};

int main()
{
    FILE *Episodios = fopen("Episodios.dat", "rb");

    Episodio rEpisodio;

    int cantSeries = 0;

    fread(&rEpisodio, sizeof(Episodio), 1, Episodios);

    printf("\t\t\tListado de descaga de series\n");

    while (!feof(Episodios))
    {
        long keyIdSerie = rEpisodio.idSerie;
        printf("Serie: %d\n", rEpisodio.idSerie);
        int cantEpSerie = 0;
        long cantDeSerie = 0;
        while (!feof(Episodios) && rEpisodio.idSerie == keyIdSerie)
        {
            int cantEpTemp = 0;
            long cantDeTemp = 0;

            char keyTemp = rEpisodio.temp;
            printf("\tTemporada: %d\n", rEpisodio.temp);

            printf("\tNro Episodio\tTitulo Episodio\t\t\tCant Descargas\tFecha Ultima Descarga\n");
            while (!feof(Episodios) && rEpisodio.idSerie == keyIdSerie &&
                   rEpisodio.temp == keyTemp)
            {
                printf("\t%d\t%s\t\t\t%d\t%d/%d/%d\n", rEpisodio.nro, rEpisodio.titulo,
                       rEpisodio.descargas, (rEpisodio.fechaUD) % 100,
                       (rEpisodio.fechaUD % 1000) / 100, rEpisodio.fechaUD / 1000);
                cantEpTemp++;
                cantDeTemp += rEpisodio.descargas;
                cantEpSerie++;
                cantDeSerie += rEpisodio.descargas;
            }
            printf("\t-------------------------------------------------------------------------\n");
            printf("\t* Cant. Total de Episodios de la temporada:\t: %d", cantDeTemp);
            printf("\t* Cant. Total de descargas de la temporada:\t: %d", cantDeTemp);
        }
        printf("-------------------------------------------------------------------------\n");
        printf("** Cant. Total de Episodios de la Serie:\t: %d", cantEpSerie);
        printf("** Cant. Total de descargas de la Serie:\t: %d", cantDeSerie);
        cantSeries++;
    }
    printf("-------------------------------------------------------------------------\n");
    printf("*** Total General de series:\t: %d", cantSeries);

    fclose(Episodios);

    getchar();
    return 0;
}