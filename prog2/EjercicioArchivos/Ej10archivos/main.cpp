
/*
Ej. 10: Dado el archivo binario generado en el ejercicio 6, desarrolle un programa que genere un archivo
ordenado por número de legajo (cada registro debe tener los campos legajo y apellido y nombre) para
todos los alumnos que se inscribieron una o más veces. Cada legajo debe ocupar una posición única y
predecible en el archivo. El intervalo de los legajos es 80001 a 110000. Pueden no presentarse todos los
legajos
Ej. 11: Dado el archivo binario generado en el ejercicio 10, desarrolle un programa que elimine, si los
hubiese, los registros que no contengan datos válidos de la siguiente manera:
a) Genere un nuevo archivo, elimine el archivo original y renombre al archivo actual
b) Compacte en el mismo archivo
*/

#include <iostream>
#include <string.h>
using namespace std;

#define LEGAJO_INICIAL 100

struct Inscripcion
{
    char nombre[26];
    int legajo;
    int codigoMat;
    int dia,mes,anio;
};

struct Alumno
{
    char nombre [26];
    int legajo;
};

int main()
{
    FILE *diaFinales = NULL;
    FILE *alumnos = NULL;
   
    diaFinales = fopen("DIASFINALES.DAT","rb");
    if(diaFinales == NULL) {
        exit(EXIT_FAILURE);
    }

    alumnos = fopen("ALUMNOS.DAT","wb+");
    if(diaFinales == NULL) {
        exit(EXIT_FAILURE);
    }

    Inscripcion inscripcion;
    Alumno alumno;

   fread(&inscripcion, sizeof(inscripcion), 1, diaFinales);

    while (!feof(diaFinales))
    {
        
        strcpy(alumno.nombre,inscripcion.nombre);
        alumno.legajo = inscripcion.legajo;

        fseek(alumnos,sizeof(alumno)*(alumno.legajo-LEGAJO_INICIAL),SEEK_SET);
        fwrite(alumnos,sizeof(alumno),1,alumnos);

        fread(&inscripcion, sizeof(inscripcion), 1, diaFinales);
    }


    fflush(alumnos);
    fseek(alumnos,0,SEEK_SET);

    
    fread(&alumno, sizeof(alumno), 1, alumnos);
    while (!feof(alumnos))
    {
        printf("%d\t%s\n",alumno.legajo,alumno.nombre);
        fread(&alumno, sizeof(alumno), 1, alumnos);
    }
    



    fclose(diaFinales);
    fclose(alumnos);



    getchar();

    return 0;
} 
