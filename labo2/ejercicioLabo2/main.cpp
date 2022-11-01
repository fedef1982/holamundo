/*
- Cargar 3 Alumnos.
- Alumno tiene: Nombre, promedio, fecha Inicio.
- Llamando a una funcion, (mejor promedio) muestre que alumno tiene el mejor promedio.
*/
#include <iostream>
#include "alumno.h"


int main()
{
    Alumno alumno1, alumno2, alumno3, alumnoMP;
    //carga alumno1
    printf("\nIngrese Alumno 1\n");
    printf("Nombre ");
    scanf("%s", &alumno1.nombre);
    printf("Promedio ");
    scanf("%f", &alumno1.promedio);
    printf("Fecha DD-MM-AAAA ");
    scanf("%d-%d-%d", &alumno1.fechaInicio.dia, &alumno1.fechaInicio.mes, &alumno1.fechaInicio.anio);
    //carga alumno2
    printf("\nIngrese Alumno 2\n");
    printf("Nombre ");
    scanf("%s", &alumno2.nombre);
    printf("Promedio ");
    scanf("%4.2f", &alumno2.promedio);
    printf("Fecha DD-MM-AAAA ");
    scanf("%d-%d-%d", &alumno2.fechaInicio.dia, &alumno2.fechaInicio.mes, &alumno2.fechaInicio.anio);
    //carga alumno3
    printf("\nIngrese Alumno 3\n");
    printf("Nombre ");
    scanf("%s", &alumno3.nombre);
    printf("Promedio ");
    scanf("%f", &alumno3.promedio);
    printf("Fecha DD-MM-AAAA ");
    scanf("%d-%d-%d", &alumno3.fechaInicio.dia, &alumno3.fechaInicio.mes, &alumno3.fechaInicio.anio);

    //calculo mejor promedio
    alumnoMP= mejorPromedio(alumno1,alumno2,alumno3);

    //Impremier mejor promedio
    printf("\nAlumno Mejor promedio\n");
    printf("Nomre: %s\n", alumnoMP.nombre);
    printf("Promedio: %f\n", alumnoMP.promedio);
    printf("Fecha Inicio: %d-%d-%d\n", alumnoMP.fechaInicio.dia, alumnoMP.fechaInicio.mes, alumnoMP.fechaInicio.anio);    
    
    return 0;

}