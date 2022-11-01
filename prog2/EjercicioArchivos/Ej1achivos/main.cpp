#include <iostream>
#include <string.h>
using namespace std;

struct Alumno
{
    int legajo;
    int nota1;
    int nota2; 
};



int main()
{
    FILE *pCursoT=NULL;
    Alumno alumno;
    float promedio;

    pCursoT = fopen("curso.txt","w");

    printf("Ingrese Legajo: ");
    scanf("%d", &alumno.legajo);

    while (alumno.legajo > 0)
    {
        printf("Ingrese Nota 1: ");
        scanf("%d", &alumno.nota1);
        printf("Ingrese Nota 2: ");
        scanf("%d", &alumno.nota2);

        promedio = (double)(alumno.nota1+alumno.nota2)/2;
        
        fprintf(pCursoT,"%d\t%.2f\n",alumno.legajo,promedio);
        
        printf("Ingrese Legajo: ");
        scanf("%d", &alumno.legajo);
    }

    fclose(pCursoT);

    getchar();
    return 0;
}