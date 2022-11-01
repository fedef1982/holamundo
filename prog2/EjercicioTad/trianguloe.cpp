#include "trianguloe.h"

Trianguloe cargarTriangulo(int lado) {
    Trianguloe triangulo;
    triangulo.lado = lado;
    return triangulo;
}

float area(Trianguloe triangulo) {
    return triangulo.lado * triangulo.lado/2;
}

float perimetro(Trianguloe triangulo) {
    return triangulo.lado * 3;
}

