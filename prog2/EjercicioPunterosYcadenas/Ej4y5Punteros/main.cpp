/*4) Declarar un struct que defina una variable del tipo vector de caracteres, llamada nombre, y otra
que sea del tipo entero, llamada edad y ...
a) En la función main, asigne el valor “Kokumo” y “30” para nombre y edad respectivamente.
b) Luego, invoque una función que reciba el struct por parámetro y que imprima el valor de
ambas variables del struct.
c) Dentro de esa misma función, cambie los valores de las variables en cuestión y muestre
nuevamente sendos valores.
d) De regreso en el main, e inmediatamente después de la llamada a la función, imprima los
valores del struct; analice qué valores se imprimieron en pantalla.*/
#include <iostream>
#include <string.h>
using namespace std;

struct Persona 
{
    char nombre[30];
    int edad;
};


void imprimirPersona (Persona persona)
{
    printf ("Nombre persona %s \n", persona.nombre);
    printf ("Nombre edad %d \n", persona.edad);

    strcpy (persona.nombre,"Federico");

    persona.edad = 40;

    printf ("Nombre persona %s \n", persona.nombre);
    printf ("Nombre edad %d \n", persona.edad);
    return;
}

void imprimirPersonaPorRef (Persona  &persona)
{
    printf ("Nombre persona %s \n", persona.nombre);
    printf ("Nombre edad %d \n", persona.edad);

    strcpy (persona.nombre,"Federico");
    persona.edad=40;

    printf ("Nombre persona %s \n", persona.nombre);
    printf ("Nombre edad %d \n", persona.edad);
    return;
}

void imprimirPersonaPtr (Persona* persona)
{
    printf ("Nombre persona %s \n", (*persona).nombre);
    printf ("Nombre edad %d \n", (*persona).edad);

    strcpy ((*persona).nombre,"Carlos");
    (*persona).edad=50;

    printf ("Nombre persona %s \n", (*persona).nombre);
    printf ("Nombre edad %d \n", (*persona).edad);
    return;
}

int main(int argc, char const *argv[])
{
    Persona persona;

    //a)
    strcpy (persona.nombre,"Kokumo");
    persona.edad=30;
    
    //b) y C)
    printf("\npor parametro: \n");
    imprimirPersona(persona);

    printf ("\nNombre persona %s \n", persona.nombre);
    printf ("Nombre edad %d \n", persona.edad);
    
    printf("\npor referencia: \n");
    imprimirPersonaPorRef(persona);

    printf ("\nNombre persona %s \n", persona.nombre);
    printf ("Nombre edad %d \n", persona.edad);


    Persona* ptrPersona = &persona;
    printf("\npor puntero: \n");
    imprimirPersonaPtr(ptrPersona);

    //d)
    printf ("\nNombre persona %s \n", persona.nombre);
    printf ("Nombre edad %d \n", persona.edad);

    getchar();

    return 0;
}
