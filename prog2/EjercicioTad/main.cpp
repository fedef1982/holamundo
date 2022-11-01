#include <iostream>
#include "cuadrado.h"
#include "circulo.h"
#include "trianguloe.h"
#include "pentagono.h"
#include "esfera.h"
#include "cilindro.h"

using namespace std;

int main()
{

    char tipoFigura;
    printf("Ingrese el tipo de figura (c, t, i,):\n");
    printf("1 - Cuadrado\n");
    printf("2 - Circulo\n");
    printf("3 - Triangulo (eequilatero)\n");
    printf("4 - Pentagono\n");
    printf("5 - Esfera\n");
    printf("6 - Cilindro\n");
    scanf("%c", &tipoFigura);

    switch (tipoFigura)
    {
    case '1':
    {
        int lado = 0;
        printf("Ingrese un lado del cuadrado: ");
        scanf("%d", &lado);
        Cuadrado cuadrado = cargarCuadrado(lado);
        printf("El area es: %f y el perimetro es %f\n\n", area(cuadrado), perimetro(cuadrado));
        break;
    }
    case '2':
    {
        int radio = 0;
        printf("Ingrese un lado del rado del Circulo: ");
        scanf("%d", &radio);
        Circulo circulo = cargarCirculo(radio);
        printf("El area es: %f y el perimetro es %f\n\n", area(circulo), perimetro(circulo));
        break;
    }
    case '3':
    {
        int lado = 0;
        printf("Ingrese un lado del triangulo (equilatero): ");
        scanf("%d", &lado);
        Trianguloe triangulo = cargarTriangulo(lado);
        printf("El area es: %f y el perimetro es %f\n\n", area(triangulo), perimetro(triangulo));
        break;
    }
    case '4':
    {
        int lado = 0;
        printf("Ingrese un lado del pentagono: ");
        scanf("%d", &lado);
        Pentagono pentagono = cargarPentagono(lado);
        printf("El area es: %f y el perimetro es %f\n\n", area(pentagono), perimetro(pentagono));
        break;
    }
    case '5':
    {
        int radio = 0;
        printf("Ingrese un lado del Esfera: ");
        scanf("%d", &radio);
        Esfera esfera = cargarEsfera(radio);
        printf("El volumen es: %f y el area es %f\n\n", volumen(esfera), area(esfera));
        break;
    }
    case '6':
    {
        int radio = 0, altura = 0;
        printf("Ingrese un radio-altura del cilindro: ");
        scanf("%d-%d", &radio, &altura);
        Cilindro cilindro = cargarCilindro(radio,altura);
        printf("El volumen es: %f y el area es %f\n\n", volumen(cilindro), area(cilindro));
        break;
    }
    default:
        break;
    }

    system("pause");
    return 0;
}