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
    FILE* series = fopen("Series.dat","wb");
    FILE* novSeries = fopen("NovSeries.dat","wb");

    serie rSerie;
    
    printf("Carga Series.dat\n\n");
    printf("ingese ID Serie (con 0 termina carga) ");
    scanf("%d",&rSerie.id);

    while (rSerie.id > 0)
    {
        printf("ingese Titulo serie ");
        scanf("%s",&rSerie.titulo);
        printf("ingese Genero serie ");
        scanf("%s",&rSerie.genero);
        fwrite(&rSerie,sizeof(serie), 1 , series);
        printf("ingese ID Serie (con 0 termina carga) ");
        scanf("%d",&rSerie.id);
    }

    printf("\nCarga NovSeries.dat\n\n");
    printf("ingese ID Serie (con 0 termina carga) ");
    scanf("%d",&rSerie.id);

    while (rSerie.id > 0)
    {
        printf("ingese Titulo serie ");
        scanf("%s",&rSerie.titulo);
        printf("ingese Genero serie ");
        scanf("%s",&rSerie.genero);
        fwrite(&rSerie,sizeof(serie), 1 , novSeries);
        printf("ingese ID Serie (con 0 termina carga) ");
        scanf("%d",&rSerie.id);
    }

    fclose(series);
    fclose(novSeries);

    getchar();
    return 0;

}