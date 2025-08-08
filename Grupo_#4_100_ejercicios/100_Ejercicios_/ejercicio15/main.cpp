//
// Created by klain on 7/8/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    int numero;

    saludo();

    do {
        cout << "Ingrese un numero para clasificar: ";
        funcionvalidar(numero);
        clasificarNumero(numero);
    } while (funcionSeguir());

    return 0;
}