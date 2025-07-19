#include "cabecera.h"
#include <iostream>

float encontrarMayor(float num1, float num2, float num3) {
    float mayor = num1;
    if (num2 > mayor) {
        mayor = num2;
    }
    if (num3 > mayor) {
        mayor = num3;
    }
    return mayor;
}