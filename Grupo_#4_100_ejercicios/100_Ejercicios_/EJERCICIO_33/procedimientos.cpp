// Autor: Jorge Mendoza
// Fecha: 22/07/2025.
#include "funciones.h"
#include <iostream>

using namespace std;

// Implementación de la función para validar y leer una entrada numérica.
double validarEntradaNumerica(const char* mensaje) {
    double numero; // Variable para almacenar el número ingresado.

    while (true) {
        cout << mensaje;
        cin >> numero;

        // Verifica si la lectura falló (ej. se ingresó texto en lugar de números).
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero valido: ";
            cin.clear(); // Limpia el estado de error de 'cin'.
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return numero;
}

// Implementación de la función para imprimir los elementos de un arreglo.
void imprimirArreglo(const double arr[], int tamanio) {
    cout << "[";
    for (int i = 0; i < tamanio; ++i) {
        cout << arr[i];
        if (i < tamanio - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

// Función para ordenar un arreglo por selección ascendente.
// Este algoritmo encuentra el elemento más pequeño y lo intercambia con el elemento en la posición actual.
void ordenarAscendentePorSeleccion(double arr[], int tamanio) {
    for (int i = 0; i < tamanio - 1; ++i) {
        int indiceMinimo = i;

        for (int j = i + 1; j < tamanio; ++j) {
            if (arr[j] < arr[indiceMinimo]) {
                indiceMinimo = j;
            }
        }

        if (indiceMinimo != i) {
            double temp = arr[i];
            arr[i] = arr[indiceMinimo];
            arr[indiceMinimo] = temp;
        }
    }
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