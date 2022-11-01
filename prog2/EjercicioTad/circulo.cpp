#include "circulo.h"

Circulo cargarCirculo(int radio) {
    Circulo circulo;
    circulo.radio = radio;
    return circulo;
}

float area(Circulo circulo) {
    return 3.14 * circulo.radio * circulo.radio;
}

float perimetro(Circulo circulo) {
    return 2 * 3.14 *circulo.radio;
}

