//
// Created by Kevin Alejandro Lainez Salinas on 28/6/2025.
//
#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    double lps;

    saludo();

    do {
        cout << "Ingrese su la cantidad de dolares a convertir: ";
        funcionvalidar(lps);  // Validamos antes de usar
        cout << "La cantidad en lempiras es: " << funciondolar(lps) << endl;
    } while (funcionSeguir());

    return 0;
}