//
// Created by Admin on 7/22/2025.
//
#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define el tamaño máximo de la pila.
constexpr int MAX_TAMANIO_PILA = 10;

// Estructura para la Pila
struct Pila {
    int elementos[MAX_TAMANIO_PILA]; // Arreglo para almacenar los elementos de la pila.
    int cima; // Índice del elemento superior de la pila. -1 si está vacía.
};

// Declaración de la función para comprobar si la pila está vacía.
bool estaVacia(const Pila& pila);

// Declaración de la función para comprobar si la pila está llena.
// Recibe una referencia constante a la pila.
// Retorna 'true' si la pila está llena, 'false' en caso contrario.
bool estaLlena(const Pila& pila);

// Declaración de la función para validar y leer una entrada numérica (long long).
// Recibe un mensaje a mostrar al usuario.
// Retorna un valor long long válido.
long long validarEntradaNumerica(const char* mensaje);

#endif // FUNCIONES_H