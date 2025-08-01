// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define el tamaño máximo de la cola.
constexpr int MAX_TAMANIO_COLA = 5; // Un tamaño pequeño para facilitar las pruebas.

// Estructura para la Cola.
// 'elementos' almacenará los datos.
// 'frente' es el índice del primer elemento (para eliminar).
// 'final' es el índice del último elemento (para agregar).
// 'contador' lleva la cuenta de cuántos elementos hay en la cola.
struct Cola {
    int elementos[MAX_TAMANIO_COLA];
    int frente;
    int final;
    int contador; // Para saber cuántos elementos hay y validar si está llena.
};

// Declaración de la función para comprobar si la cola está llena.
bool estaLlena(const Cola& cola);

// Declaración de la función para agregar un elemento al final de la cola (enqueue).
bool enqueue(Cola& cola, int valor);

// Declaración de la función para validar y leer una entrada numérica (int).
int validarEntradaNumerica(const char* mensaje);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
int preguntarRepetir();

#endif // FUNCIONES_H