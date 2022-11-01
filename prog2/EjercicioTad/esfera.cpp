#include "esfera.h"

Esfera cargarEsfera(int radio) {
    Esfera esfera;
    esfera.radio = radio;
    return esfera;
}

float area(Esfera esfera) {
    return esfera.radio;
}

float volumen(Esfera esfera) {
    return esfera.radio * 4;
}

