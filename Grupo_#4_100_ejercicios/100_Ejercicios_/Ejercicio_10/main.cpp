//
// Created by Kevin Alejandro Lainez Salinas on 28/6/2025.
//

#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int x;

    saludo();

    do {
        cout << "Ingrese su numero natural: ";
        funcionvalidar(x);  // Validamos antes de usar
        cout << "La suma de los numeros naturales es: " << sumaNatural(x) << endl;
    } while (funcionSeguir());

    return 0;
}
