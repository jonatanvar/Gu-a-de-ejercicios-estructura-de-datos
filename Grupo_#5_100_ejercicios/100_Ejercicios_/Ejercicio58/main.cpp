//
// Created by klain on 16/7/2025.
//
#include <iostream>
#include "Funciones.h"
using namespace std;

int main() {
    int num1, den1, num2, den2;
    Fraccion f1, f2, suma;

    saludo();

    do {
        funcionvalidar(num1, den1, num2, den2);

        f1.numerador = num1;
        f1.denominador = den1;
        f2.numerador = num2;
        f2.denominador = den2;

        suma = sumarFracciones(f1, f2);

        cout << "La suma de ";
        imprimirFraccion(f1);
        cout << " + ";
        imprimirFraccion(f2);
        cout << " es = ";
        imprimirFraccion(suma);
        cout << endl;

    } while (funcionSeguir());

    return 0;
}