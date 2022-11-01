/*
Ej. 6: Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el mes de mayo.
Cada boleta tiene los siguientes datos: nombre y apellido, número de legajo, código de materia,
día, mes y año del examen. Los datos finalizan con un nombre y apellido nulo.
Desarrollar un programa que a partir del ingreso de las boletas mencionadas, por teclado, genere
un archivo binario de inscripción de alumnos a exámenes finales DIAFINALES.DAT, según el siguiente
diseño:
a.1Nro. de legajo (8 dígitos) a.2 Código de materia (6 dígitos)
a.3Día del examen (1..31) a.4 Mes del examen (1..12)
a.5Año del examen (4 dígitos) a.6 Nombre-Apellido (25caract)
*/
#include <iostream>
#include <string.h>
using namespace std;

struct Inscripcion
{
    char nombre[26];
    int legajo;
    int codigoMat;
    int dia,mes,anio;
};


int main()
{
    FILE *pDiasFinalesD = NULL;
   
    pDiasFinalesD = fopen("DIASFINALES.DAT","wb");
    if(pDiasFinalesD == NULL) {
        exit(EXIT_FAILURE);
    }

    Inscripcion inscripcion;

    printf("\nIngrese Nombre: ");
    scanf("%s", &inscripcion.nombre);

    while (strcmp(inscripcion.nombre,"fin") != 0)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &inscripcion.legajo);
        printf("Ingrese materia: ");
        scanf("%d", &inscripcion.codigoMat);
        
        printf("Ingrese fecha inscripcion DD MM AAAA: ");
        scanf("%d %d %d", &inscripcion.dia,&inscripcion.mes,&inscripcion.anio);

        fwrite(&inscripcion, sizeof(inscripcion),1,pDiasFinalesD);

        printf("\nIngrese nombre: ");
        scanf("%s", &inscripcion.nombre);
    }

    fclose(pDiasFinalesD);



    pDiasFinalesD = fopen("DIASFINALES.DAT","rb+");
    FILE *pDiasFinalesT = fopen("DIASFINALES.TXT", "wt+");

    fread(&inscripcion, sizeof(inscripcion), 1, pDiasFinalesD);
    fprintf(pDiasFinalesT,"nombre\t\tlegajo\t\tcodigoMat\tFecha inscripcion\n\n");
    while (!feof(pDiasFinalesD))
    {
        fprintf(pDiasFinalesT,"%s\t\t%d\t\t%d\t\t%d-%d-%d\n", inscripcion.nombre, inscripcion.legajo, inscripcion.codigoMat, inscripcion.dia, inscripcion.mes, inscripcion.anio);
        fread(&inscripcion, sizeof(inscripcion), 1, pDiasFinalesD);
    }
    fclose (pDiasFinalesD);
    fclose (pDiasFinalesT);


    getchar();

    return 0;
} 
