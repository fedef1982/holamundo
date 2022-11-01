#include "alumno.h"

/*Alumno cargarAlumno (char nombre[],float promedio,Fecha fechaInicio)
{
    Alumno alumno;
    alumno.nombre = nombre;
    alumno.promedio = promedio;
    alumno.fechaInicio = fechaInicio;
    return alumno;
}*/
Alumno mejorPromedio (Alumno alumno1, Alumno alumno2, Alumno alumno3)
{
    if (alumno1.promedio>=alumno2.promedio && alumno1.promedio>=alumno3.promedio)
        return alumno1;
    else
    {
        if (alumno2.promedio> alumno1.promedio && alumno2.promedio>=alumno3.promedio)
            return alumno2;
        else
            return alumno3;
    }

}
