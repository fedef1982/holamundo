#include <iostream>
#include <string.h>
#include <math.h>
#define MAX_BUFFER 32
using namespace std;

FILE* abrir(const char* nombre, const char * modo);
void leerBinario(FILE* binarios, char binario[MAX_BUFFER]);
int convertirBaD(char binario[MAX_BUFFER]);
void escribirDecimal(FILE* decimales, int decimal);

int main()
{
    FILE* binarios = abrir("binarios.txt","r");
    FILE* decimales = abrir("decimales.dat","wb");

    char binario[MAX_BUFFER];
    int decimal;

    leerBinario(binarios,binario);
    decimal = convertirBaD(binario);

    printf("%s --> Genera %d",binario,decimal);
    escribirDecimal(decimales, decimal);

    fclose(binarios);
    fclose(decimales);
    getchar();
    return 0;
} 

FILE* abrir(const char* nombre, const char * modo)
{
    FILE* file = fopen(nombre,modo);
    if (file!=NULL)
    {
        fprintf(stderr,"No se pudo abrir el archivo %s", nombre);
        exit(EXIT_FAILURE);
    }
    return file;
}

void leerBinario(FILE* binarios, char binario[MAX_BUFFER])
{
    char buffer[MAX_BUFFER];
    if (fgets(buffer,MAX_BUFFER,binarios)!=NULL);
    {
        strcpy(binarios,buffer);
    }
    return;
}
int convertirBaD(char binario[MAX_BUFFER])
{
    int entero=0;
    for (int i=0; i< MAX_BUFFER; i++);
    {
        entero += entero + pow(2,31-i) * (atoi(binario[31-i])
    }
    return;
}

void escribirDecimal(FILE* decimales, int decimal);