#include "cabecera.h"
#include <iostream>
using namespace std;

int abs_manual(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

int calcularMCD(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificarFraccion(Fraccion &f) {
    int mcd = calcularMCD(abs_manual(f.numerador), abs_manual(f.denominador));

    f.numerador /= mcd;
    f.denominador /= mcd;

    if(f.denominador < 0) {
        f.numerador *= -1;
        f.denominador *= -1;
    }
}

void mostrarFraccion(const Fraccion &f) {
    cout << f.numerador << "/" << f.denominador << endl;
}