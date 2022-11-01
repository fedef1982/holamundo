
#include <iostream>
#include "string.h"
#define MAX_VUELOS 500
using namespace std;

struct Vuelo
{
    char codigo[7];
    short int disponibles;
};

struct Comprador
{
    char codigoVuelo[7];
    short int solicitados;
    int dni;
    char apellidoNombre[26];
};

FILE *abrir(const char *fileName, const char *modo);
void cerrar(FILE *file);
int leerVuelo(Vuelo *registro, FILE *file);
int leerComprador(Comprador *registro, FILE *file);

int buscarVuelo(char *codVuelo, FILE *file);
Vuelo obtenerVuelo(int pos, FILE *file);
void actualizarVuelo(int pos, Vuelo vuelo, FILE *file);
void imprimirComprador(Comprador comprador);

int main()
{

    FILE *vuelos = abrir("vuelos.dat", "rb");
    FILE *compradores = abrir("compradores.dat", "rb");

    short int noVendidos[MAX_VUELOS] = {0};

    Comprador comprador;
    leerComprador(&comprador, compradores);
    while (!feof(compradores))
    {
        int posVuelo = buscarVuelo(comprador.codigoVuelo, vuelos);
        Vuelo vuelo = obtenerVuelo(posVuelo, vuelos);
        if (vuelo.disponibles >= comprador.solicitados)
        {
            imprimirComprador(comprador);
            vuelo.disponibles -= comprador.solicitados;
            actualizarVuelo(posVuelo, vuelo, vuelos);
        }
        else
        {
            noVendidos[posVuelo] += comprador.solicitados;
        }
        leerComprador(&comprador, compradores);
    }
    fclose(compradores);

    // Posiciono el archivo al inicio
    fseek(vuelos, 0, SEEK_SET);
    Vuelo vuelo;
    leerVuelo(&vuelo, vuelos);
    int pos = 0;
    while (!feof(vuelos))
    {
        printf("%s\t%d\t%d\n", vuelo.codigo, vuelo.disponibles, noVendidos[pos]);
        pos++;
        leerVuelo(&vuelo, vuelos);
    }
    fclose(vuelos);

    system("pause");
    return 0;
}

FILE *abrir(const char *fileName, const char *modo)
{
    FILE *file = fopen(fileName, modo);
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }

    return file;
}

void cerrar(FILE *file)
{
    fclose(file);
    file = NULL;
}

int leerVuelo(Vuelo *registro, FILE *file)
{
    return fread(registro, sizeof(Vuelo), 1, file);
}

int leerComprador(Comprador *registro, FILE *file)
{
    return fread(registro, sizeof(Comprador), 1, file);
}

void imprimirComprador(Comprador comprador)
{
    printf("%d", comprador.dni); // Faltan datos
    return;
}

Vuelo obtenerVuelo(int pos, FILE *file)
{
    Vuelo vuelo;
    fseek(file, pos * sizeof(Vuelo), SEEK_SET);
    fread(&vuelo, sizeof(Vuelo), 1, file);
    return vuelo;
}

void actualizarVuelo(int pos, Vuelo vuelo, FILE *file)
{
    fseek(file, pos * sizeof(Vuelo), SEEK_SET);
    fwrite(&vuelo, sizeof(Vuelo), 1, file);
    return;
}

int contarRegistros(FILE *file)
{
    int posActual = ftell(file);

    fseek(file, 0, SEEK_END);
    int cant = ftell(file) / sizeof(Vuelo);

    fseek(file, posActual, SEEK_SET);
    return cant;
}

int buscarVuelo(char *codVuelo, FILE *file)
{
    int inicio = 0;
    int fin = contarRegistros(file) - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        // Si el elemento es el del medio, devolvemos la posicion
        Vuelo vuelo = obtenerVuelo(mitad, file);
        if (strcmp(vuelo.codigo, codVuelo) == 0)
        {
            return mitad;
        }
        // Si el elemento es menor entonces solo puede estar en la primer mitad
        if (strcmp(vuelo.codigo, codVuelo) < 0)
        {
            fin = mitad - 1; // Cambio el limite superior
        }
        else
        {
            inicio = mitad + 1; // Cambio el limite inferior
        }
    }
    // Si llegamos hasta aca es que el elemento no estaba
    return -1;
}