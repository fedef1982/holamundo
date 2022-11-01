/*15. Dado un archivo de registros de alumnos, donde cada registro contiene: a) Apellido y
Nombre del alumno (35 caracteres) b) Número de legajo (7 dígitos) c) División
asignada (1 a 100) ordenado por número de legajo, desarrollar el algoritmo y
codificación del programa que imprima el listado de alumnos por división, ordenado
por división y número de legajo crecientes, a razón de 55 alumnos por hoja.*/
#include <iostream>
#include <string.h>

struct Alumno
{
    char nombre[35];
    int legajo;
    char division;
};


struct STR_NODO
{
    Alumno alumno;
    STR_NODO* ste;    
};


int main()
{
    FILE * fileAlumnos = fopen("Alumnos.dat", "rb");
    STR_NODO * listAlumnos = NULL;

    Alumno regAlumno;

    fread(&regAlumno, sizeof(Alumno),1, fileAlumnos);

    while (!feof(fileAlumnos))
    {
        InsertOrderd(&listAlumnos,regAlumno);
    }

    printList(&listAlumnos);
}
