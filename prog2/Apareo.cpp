#include <iostream>
using namespace std;

struct Inscripciones
{
    int legajo;
    int codMateria;
    char ApellidoNombre[26];
};

void crearArchivos();

int main()
{

    crearArchivos();

    // Asignar y abrir archivos
    FILE *maestroFinales = nullptr;
    FILE *inscripcionesDia = nullptr;
    FILE *finalesAct = nullptr;

    maestroFinales = fopen("MAESTROFINALES.DAT", "rb");
    inscripcionesDia = fopen("DIAFINALES.DAT", "rb");
    finalesAct = fopen("FINALESACT.DAT", "wb");

    Inscripciones registroMaestro;
    Inscripciones registroDia;

    // Leer registro archivo maestro con control de EOF
    fread(&registroMaestro, sizeof(Inscripciones), 1, maestroFinales);
    // Leer registro archivo finales del día con control de EOF
    fread(&registroDia, sizeof(Inscripciones), 1, inscripcionesDia);

    //  Mientras no sea fin de archivo de ninguno de los dos archivos
    while (!feof(maestroFinales) && !feof(inscripcionesDia))
    {
        // o Si el código de materia del registro del maestro es menor al código de materia del registro
        // del archivo del día
        //  Grabar registro archivo maestro en archivo de finales actualizado
        //  Leer registro archivo maestro con control de EOF
        if (registroMaestro.legajo < registroDia.legajo)
        {
            fwrite(&registroMaestro, sizeof(Inscripciones), 1, finalesAct);
            fread(&registroMaestro, sizeof(Inscripciones), 1, maestroFinales);
        }
        // o De lo contrario
        //  Grabar registro archivo finales del día en archivo de finales actualizado
        //  Leer registro archivo finales del día con control de EOF
        else
        {
            fwrite(&registroDia, sizeof(Inscripciones), 1, finalesAct);
            fread(&registroDia, sizeof(Inscripciones), 1, inscripcionesDia);
        }
    }

    //  Por fin de archivo del maestro mientras no sea fin de archivo de finales del día
    // o Grabar registro archivo finales del día en archivo de finales actualizado
    // o Leer registro archivo finales del día con control de EOF
    while (!feof(maestroFinales))
    {
        fwrite(&registroMaestro, sizeof(Inscripciones), 1, finalesAct);
        fread(&registroMaestro, sizeof(Inscripciones), 1, maestroFinales);
    }

    //  Por fin de archivo finales del día mientras no sea fin de archivo maestro
    // o Grabar registro archivo maestro en archivo de finales actualizado
    // o Leer registro archivo maestro con control de EOF
    while (!feof(inscripcionesDia))
    {
        fwrite(&registroDia, sizeof(Inscripciones), 1, finalesAct);
        fread(&registroDia, sizeof(Inscripciones), 1, inscripcionesDia);
    }

    //  Cerrar archivos
    fclose(maestroFinales);
    fclose(inscripcionesDia);
    fclose(finalesAct);

    // Imprimir archivos
    finalesAct = fopen("FINALESACT.DAT", "rb");
    fread(&registroMaestro, sizeof(Inscripciones), 1, finalesAct);
    while (!feof(finalesAct))
    {
        printf("Legajo: %i\t Codigo Materia: %i\t Nombre: %s\n",
               registroMaestro.legajo,
               registroMaestro.codMateria,
               registroMaestro.ApellidoNombre);
        fread(&registroMaestro, sizeof(Inscripciones), 1, finalesAct);
    }

    return 0;
}

void crearArchivos()
{
    FILE *maestroFinales = fopen("MAESTROFINALES.DAT", "wb");
    FILE *diafinales = fopen("DIAFINALES.DAT", "wb");

    Inscripciones contenidoMaestro[3] = {
        {12, 123, "Juan Angel"},
        {14, 123, "Jorge Alberto"},
        {25, 234, "Matias Enrique"}};

    Inscripciones contenidoDia[3] = {
        {5, 123, "Carlos Segundo"},
        {13, 222, "Ernesto Raul"},
        {26, 244, "Pablo Joaquin"}};

    for (int i = 0; i < 3; i++)
    {
        fwrite((contenidoMaestro + i), sizeof(Inscripciones), 1, maestroFinales);
        fwrite((contenidoDia + i), sizeof(Inscripciones), 1, diafinales);
    }

    fclose(maestroFinales);
    fclose(diafinales);
}
