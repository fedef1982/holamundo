#include "cilindro.h"

Cilindro cargarCilindro(int radio, int altura) {
    Cilindro cilindro;
    cilindro.radio = radio;
    cilindro.altura = altura;
    return cilindro;
}

float area(Cilindro cilindro) {
    return 2*(3.14 * cilindro.radio * cilindro.radio) + cilindro.altura * 2 * 3.14 * cilindro.radio;
}

float volumen(Cilindro cilindro) {
    return 3.14 * cilindro.radio * cilindro.radio * cilindro.altura;
}

