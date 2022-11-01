#include <iostream>
#include <string.h>
#define buffer 255
using namespace std;

struct Registro
{
    int cod;
    char nombre[10];
}

int buscarPosB (FILE* file, int x);
void leerB(FILE* file);
void cargarReg(FILE* file, registro *reg);


int main()
{
    FILE* binaro = fopen ("binario.dat","rb");
    Registro reg;

    
    cargarReg()


    getchar();
    return 0;
}

h
int buscarPosB (FILE* file, int x)
{
    int inicio = 0;
    int fin = fseek(file, 0, SEEK_END);

}

void cargarReg(FILE* file, Registro *reg)
{
    fwrite
}