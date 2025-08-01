// Autor: Jorge Mendoza
// Fecha: 22/07/2025.
#include "funciones.h"
#include <iostream>

using namespace std;

// Función para comprobar si la pila está vacía.
bool estaVacia(const Pila& pila) {
    return pila.cima == -1;
}

// Función para comprobar si la pila está llena.
bool estaLlena(const Pila& pila) {
    return pila.cima == MAX_TAMANIO_PILA - 1;
}

// Función para validar y leer una entrada numérica (long long).
long long validarEntradaNumerica(const char* mensaje) {
    long long numero;

    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Error: Por favor, ingresa un valor numerico valido.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return numero;
}