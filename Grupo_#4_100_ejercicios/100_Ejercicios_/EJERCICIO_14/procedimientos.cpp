// Autor: Jorge Mendoza.
// Fecha: 7/21/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Implementación de la función para verificar si un número es par.
// Utiliza el operador módulo (%) para determinar si el residuo al dividir por 2 es 0.
bool esPar(int numero) {
    return (numero % 2 == 0);
}

// Función para preguntar si el usuario desea repetir el programa.
int preguntarRepetir() {
    int repetir;

    while (true) {
        cout << "\nQuieres repetir el programa?";
        cout << "\n1. Si";
        cout << "\n2. No";
        cout << "\nSelecciona una opcion (1-2): ";
        cin >> repetir;

        if (cin.fail() || repetir < 1 || repetir > 2) {
            cout << "Error: Ingresa 1 o 2\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return repetir;
}