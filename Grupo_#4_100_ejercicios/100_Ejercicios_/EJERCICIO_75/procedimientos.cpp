// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Implementación de la función para comprobar si la cola está vacía.
// La cola está vacía si el número de elementos ('contador') es cero.
bool estaVacia(const Cola& cola) {
    return cola.contador == 0;
}

// Implementación de la función para comprobar si la cola está llena.
// La cola está llena si el número de elementos ('contador') es igual al tamaño máximo.
bool estaLlena(const Cola& cola) {
    return cola.contador == MAX_TAMANIO_COLA;
}

// Función para agregar un elemento al final de la cola (enqueue).
bool enqueue(Cola& cola, int valor) {
    if (estaLlena(cola)) { // Primero, verifica si la cola ya está llena.
        cout << "Error: La cola esta llena. No se puede agregar el elemento " << valor << ".\n";
        return false; // Retorna false indicando que no se pudo agregar.
    }

    // Calcula el nuevo índice 'final' de forma circular.
    cola.final = (cola.final + 1) % MAX_TAMANIO_COLA;
    cola.elementos[cola.final] = valor; // Agrega el elemento en la nueva posición 'final'.
    cola.contador++;                    // Incrementa el contador de elementos en la cola.

    // Si la cola estaba vacía antes de agregar el primer elemento,
    // el 'frente' también debe ser inicializado para apuntar al primer elemento.
    if (cola.contador == 1) {
        cola.frente = cola.final; // Frente y final apuntan al mismo (y único) elemento.
    }

    cout << "Elemento " << valor << " agregado a la cola.\n";
    return true; // Retorna true indicando que el elemento se agregó con éxito.
}

// Función para eliminar y retornar un elemento del frente de la cola (dequeue).
// Ajusta el índice 'frente' de forma circular y actualiza el 'contador'.
int dequeue(Cola& cola) {
    if (estaVacia(cola)) { // Primero, verifica si la cola está vacía (underflow).
        cout << "Error: La cola esta vacia. No se puede eliminar elementos.\n";
        return -1; // Retorna un valor centinela para indicar error.
    }

    int elementoEliminado = cola.elementos[cola.frente]; // Obtiene el elemento del frente.

    cola.contador--; // Decrementa el contador de elementos.

    // Si la cola se vuelve vacía después de esta eliminación, reinicia los índices.
    if (cola.contador == 0) {
        cola.frente = -1;
        cola.final = -1;
    } else {
        // Calcula el nuevo índice 'frente' de forma circular.
        // (cola.frente + 1) % MAX_TAMANIO_COLA asegura el movimiento circular.
        cola.frente = (cola.frente + 1) % MAX_TAMANIO_COLA;
    }

    cout << "Elemento " << elementoEliminado << " eliminado de la cola.\n";
    return elementoEliminado;
}

// Función para validar y leer una entrada numérica (int).
int validarEntradaNumerica(const char* mensaje) {
    int numero;

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