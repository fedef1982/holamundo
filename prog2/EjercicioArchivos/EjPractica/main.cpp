#include <iostream>
#include <string.h>

using namespace std;

struct Alumno
{
    int legajo;
    char dia;
    char mes;
    char anio;
};


int main()
{
    FILE  *ptrArchivo = NULL;

    // Abrir archivo:
    // paso nombre del archivo
    // mode de apertura "r" lectura para texto y "rb" binarario
    // modo de apertura "w" escritura (pisa archico) para texto y "wb" binarario
    // modo de apertura "a" abre para modificar para texto y "ab" binarario
    
    // Archivo de texto
    ptrArchivo = fopen("datos.txt","w");

    for (int i = 0; i<3; i++)
    {
        fputc('F', ptrArchivo);
        fputc('e', ptrArchivo);
        fputc('d', ptrArchivo);
        fputc('e', ptrArchivo);
        fputc('\n', ptrArchivo);
    }
    for (int i = 0; i<3; i++)
    {
        fputs("Fresco\n", ptrArchivo);
    }

    for (int i= 0; i<3; i++)
    {
        fprintf(ptrArchivo,"Fede Fresco\n");
    }

    // Cerrar Archivo
    fclose (ptrArchivo);

    // Abro para leer
    ptrArchivo = fopen("datos.txt","r");
    
/*    char letra = fgetc(ptrArchivo);
    while (letra != EOF)
    {
        printf("Letra leida: %c\n", letra);
        letra = fgetc(ptrArchivo);
    }
 */   
    char palabra[50];
    fgets (palabra, 51, ptrArchivo);
    while (palabra != NULL)
    {
        fprintf (ptrArchivo,"Palabra leida: %s\n", palabra);
        fgets (palabra, 51, ptrArchivo);
    }

    
    
    
    // Cerrar Archivo
    fclose (ptrArchivo);



    /*Binario
    FILE *pFile=NULL;
    pFile = fopen ("myfile.dat","rb");
    if (pFile == NULL)
    {
        printf ("Error al abrir el archivo");
        exit (EXIT_FAILURE);
    }
    fflush (pFile);
    fclose (pFile);*/
    
    getchar();
    return 0;

}