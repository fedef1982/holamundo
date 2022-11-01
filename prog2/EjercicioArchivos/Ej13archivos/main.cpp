/*Ej. 13: 
Se dispone un archivo binario de inscripción de alumnos a exámenes finales
MAESTROFINALES.DAT y otro con las inscripciones del día de hoy DIAFINALES.DAT, ambos
ordenados ascendente por código de materia y con el siguiente diseño:
a.1 Nro de legajo (8 dígitos) 
a.2 Código de materia (6 dígitos) 
a.3 ApellidoNombre(25caract)

Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales
FINALESACT.DAT resultante del apareo de los dos archivos anteriores, con el mismo orden y diseño.

Estrategia:
 Asignar y abrir archivos
 Leer registro archivo maestro con control de EOF
 Leer registro archivo finales del día con control de EOF
 Mientras no sea fin de archivo de ninguno de los dos archivos
    o Si el código de materia del registro del maestro es menor al código de materia del registro
del archivo del día
         Grabar registro archivo maestro en archivo de finales actualizado
         Leer registro archivo maestro con control de EOF
    o De lo contrario
         Grabar registro archivo finales del día en archivo de finales actualizado
         Leer registro archivo finales del día con control de EOF
 Por fin de archivo del maestro mientras no sea fin de archivo de finales del día
    o Grabar registro archivo finales del día en archivo de finales actualizado
    o Leer registro archivo finales del día con control de EOF
 Por fin de archivo finales del día mientras no sea fin de archivo maestro
    o Grabar registro archivo maestro en archivo de finales actualizado
    o Leer registro archivo maestro con control de EOF
 Cerrar archivos */
#include <iostream>

struct finales
{
    int legajo;
    int codMat;
    char nombre[26];
};


int main()
{
    FILE* maestroFinales = fopen("MAESTROFINALES.DAT","rb");
    FILE* diaFinales = fopen("DIAFINALES.DAT","rb");
    FILE* finalesAct = fopen("FINALESACT.DAT","wb");

    finales regFinales;
    finales regDiaFinales;

    fread(&regFinales, sizeof(regFinales), 1 , maestroFinales);
    fread(&regDiaFinales, sizeof(regDiaFinales), 1 , diaFinales);

    while (!feof(maestroFinales)&& !feof(diaFinales))
    {
        if (regFinales.codMat < regDiaFinales.codMat)
        {
            fwrite(&regFinales,sizeof(regFinales),1,finalesAct);
            fread(&regFinales, sizeof(regFinales), 1 , maestroFinales);
        }else
        {
            fwrite(&regDiaFinales,sizeof(regDiaFinales),1,finalesAct);
            fread(&regDiaFinales, sizeof(regDiaFinales), 1 , diaFinales);
        }
    }

    while (!feof(maestroFinales))
    {
        fwrite(&regFinales,sizeof(regFinales),1,finalesAct);
        fread(&regFinales, sizeof(regFinales), 1 , maestroFinales);
    }

    while (!feof(diaFinales))
    {
        fwrite(&regDiaFinales,sizeof(regDiaFinales),1,finalesAct);
        fread(&regDiaFinales, sizeof(regDiaFinales), 1 , diaFinales);
    }

    fclose(maestroFinales);
    fclose(diaFinales);
    fclose(finalesAct);

    finalesAct = fopen("FINALESACT.DAT","rb");

   // fseek(finalesAct,0,SEEK_SET);
    
    FILE* finalesActTxt = fopen("FINALESACT.TXT", "wt+");

    fread(&regFinales, sizeof(regFinales), 1, finalesAct);
    fprintf(finalesActTxt,"nombre\t\tlegajo\t\tcodigoMat\n\n");
    while (!feof(finalesAct))
    {
        fprintf(finalesActTxt,"%s\t\t%d\t\t%d\n", regFinales.nombre, regFinales.legajo, regFinales.codMat);
        fread(&regFinales, sizeof(regFinales), 1, finalesAct);
    }
    fclose (finalesAct);
    fclose (finalesActTxt);


    getchar();
    return 0;
}