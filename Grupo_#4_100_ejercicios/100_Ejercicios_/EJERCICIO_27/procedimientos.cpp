// Autor: Jorge Mendoza.
// Fecha: 21/07/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Función para sumar los elementos de una columna específica en una matriz.
int sumarColumnaMatriz(int matriz[][MAX_COLS], int numFilas, int numColumnas, int columnaIndice) {
    if (columnaIndice < 0 || columnaIndice >= numColumnas) {
        return -1;
    }

    int suma = 0; // Inicializa la suma acumulada.
    // Itera a través de cada fila para sumar el elemento de la columna especificada.
    for (int i = 0; i < numFilas; i++) {
        suma += matriz[i][columnaIndice];
    }
    return suma; // Retorna la suma total de la columna.
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