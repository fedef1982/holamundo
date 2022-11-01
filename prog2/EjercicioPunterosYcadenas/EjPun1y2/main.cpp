#include <iostream>
//
using namespace std;

int main()
{

    //Ejercicio 1
    int ent;
    //char vec[10]={'a','b','c','d','e','f','g','h','i','j'};
    char vec[10]="abcdefghi";
    float dec;

    ent = 14;

    printf ("\n");

    dec = 3.14;

    printf("\nValor entero = %d - Posicion en memoria %p\n", ent, &ent);
    for (int i=0; i<10; i++)
    {
        printf("\nValor vector [%d] = %c - Posicion en memoria %p", i, vec[i], &vec[i]);
    }
    printf("\nValor vector char = %s - Posicion en memoria %p", vec, &vec);

    printf("\n\nValor decimal = %f - Posicion en memoria %p\n", dec, &dec);
    

    // Ejercicio2

    int *ptrEnt=NULL;
    printf("\n\nPosision de Memoria del puntero %p valor actual %p\n", &ptrEnt, ptrEnt);

    //en C
    // pido memoria

    ptrEnt= (int*) malloc(sizeof(int));
    *ptrEnt=20;

    printf("\nValer actual del puntero %p valor actual %d", ptrEnt, *ptrEnt);

    // libero memoria
    free(ptrEnt);

    *ptrEnt=10;

    printf("\nValer actual del puntero %p valor actual %d", ptrEnt, *ptrEnt);

    /*
    //en C++
    // pido memoria
    ptrEnt= new(int);
    //libero memoria
    delete(ptrEnt);
    */
    getchar();
    getchar();
    return 0;
}

