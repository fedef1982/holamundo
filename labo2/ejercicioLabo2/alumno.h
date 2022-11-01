struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Alumno 
{
    char nombre[20]={};
    float promedio;
    Fecha fechaInicio;
};

Alumno cargarAlumno (char nombre[],float,Fecha);
Alumno mejorPromedio (Alumno, Alumno, Alumno);