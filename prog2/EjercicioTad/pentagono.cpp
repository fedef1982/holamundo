#include "pentagono.h"

Pentagono cargarPentagono(int lado) {
    Pentagono pentagono;
    pentagono.lado = lado;
    return pentagono;
}

float area(Pentagono pentagono) {
    return pentagono.lado * pentagono.lado;
}

float perimetro(Pentagono pentagono) {
    return pentagono.lado * 5;
}

