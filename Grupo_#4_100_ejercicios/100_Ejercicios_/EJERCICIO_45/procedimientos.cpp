// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>
using namespace std;

// Función para obtener la longitud de una C-string manualmente.
int obtenerLongitud(const char* str) {
    int longitud = 0;
    while (str[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

// Función para verificar si una cadena es un palíndromo.
// Compara caracteres desde los extremos hacia el centro de la cadena.
bool esPalindromo(const char* cadena) {
    int longitud = obtenerLongitud(cadena); // Obtiene la longitud de la cadena.

    // Una cadena vacía o de un solo carácter se considera un palíndromo.
    if (longitud <= 1) {
        return true;
    }

    int inicio = 0;         // Índice para el principio de la cadena.
    int fin = longitud - 1; // Índice para el final de la cadena.

    // Recorre la cadena comparando caracteres de los extremos.
    while (inicio < fin) {
        // Si los caracteres no coinciden, no es un palíndromo.
        if (cadena[inicio] != cadena[fin]) {
            return false;
        }
        inicio++; // Mueve el índice inicial hacia adelante.
        fin--;    // Mueve el índice final hacia atrás.
    }
    return true;
}

// Función para validar y leer una entrada de tipo C-string.

void leerCadena(const char* mensaje, char buffer[], int max_tamano) {
    cout << mensaje;
    cin.getline(buffer, max_tamano);
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

        if (cin.fail()) {
            cout << "Error: Por favor, ingresa un valor numerico valido.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (repetir < 1 || repetir > 2) {
            cout << "Error: Ingresa 1 o 2\n";
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return repetir;
}