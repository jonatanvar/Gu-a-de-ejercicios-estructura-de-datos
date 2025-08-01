// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>
#include <cstring>

using namespace std;

// Función para comparar dos cadenas de caracteres.
bool compararCadenas(const char cadena1[], const char cadena2[]) {
    int longitud1 = strlen(cadena1);
    int longitud2 = strlen(cadena2);

    if (longitud1 != longitud2) {
        return false;
    }

    for (int i = 0; i < longitud1; ++i) {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
    }
    return true;
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