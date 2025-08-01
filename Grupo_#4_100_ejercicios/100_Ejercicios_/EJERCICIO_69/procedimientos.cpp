// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Función para comprobar si la cola está llena.
bool estaLlena(const Cola& cola) {
    return cola.contador == MAX_TAMANIO_COLA;
}

// Función para agregar un elemento al final de la cola (enqueue).
bool enqueue(Cola& cola, int valor) {
    if (estaLlena(cola)) {
        cout << "Error: La cola esta llena. No se puede agregar el elemento " << valor << ".\n";
        return false;
    }

    // Calcula el nuevo índice 'final' de forma circular.
    cola.final = (cola.final + 1) % MAX_TAMANIO_COLA;
    cola.elementos[cola.final] = valor; // Agrega el elemento en la nueva posición 'final'.
    cola.contador++;                    // Incrementa el contador de elementos en la cola.

    // Si la cola estaba vacía antes de agregar el primer elemento,
    // el 'frente' también debe ser actualizado para apuntar al primer elemento.
    if (cola.contador == 1) {
        cola.frente = cola.final;
    }

    cout << "Elemento " << valor << " agregado a la cola.\n";
    return true; // Retorna true indicando que el elemento se agregó con éxito.
}

// Función para validar y leer una entrada numérica (int).
int validarEntradaNumerica(const char* mensaje) {
    int numero; // Variable para almacenar el número ingresado.

    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero valido.";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return numero;
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