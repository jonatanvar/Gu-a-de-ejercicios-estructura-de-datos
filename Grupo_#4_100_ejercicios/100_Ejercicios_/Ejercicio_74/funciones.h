//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones, estructuras y constantes para el ejercicio Imprimir Cola en Orden Inverso.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string, usado en prompts.

// --- Constantes ---
const int MAX_TAMANO_COLA = 5;
const int MAX_TAMANO_PILA = 5;

// --- Estructuras ---

// Definición de la estructura para la Cola (reutilizada del Ejercicio 68).
struct Cola {
    int elementos[MAX_TAMANO_COLA];
    int frente;
    int final;
};

// Definición de la estructura para la Pila (reutilizada del Ejercicio 62).
struct Pila {
    int elementos[MAX_TAMANO_PILA];
    int cima;
};

// --- Prototipos de Funciones Auxiliares Generales ---

// Prototipo de la función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt);

// --- Prototipos de Funciones de Cola (adaptadas del Ejercicio 68) ---

// Prototipo para inicializar la cola.
void inicializarCola(Cola& cola);

// Prototipo para verificar si la cola está vacía.
bool estaVaciaCola(const Cola& cola);

// Prototipo para verificar si la cola está llena.
bool estaLlenaCola(const Cola& cola);

// Prototipo para encolar un elemento.
void enqueue(Cola& cola, int elemento);

// Prototipo para desencolar un elemento.
bool dequeue(Cola& cola, int& elemento);

// Prototipo para mostrar los elementos de la cola.
void mostrarCola(const Cola& cola);

// --- Prototipos de Funciones de Pila (adaptadas del Ejercicio 62) ---

// Prototipo para inicializar la pila.
void inicializarPila(Pila& pila);

// Prototipo para verificar si la pila está vacía.
bool estaVaciaPila(const Pila& pila);

// Prototipo para verificar si la pila está llena.
bool estaLlenaPila(const Pila& pila);

// Prototipo para empujar un elemento a la pila.
void push(Pila& pila, int elemento);

// Prototipo para sacar un elemento de la pila (nueva para este ejercicio).
bool pop(Pila& pila, int& elemento);

// Prototipo para mostrar los elementos de la pila (útil para depuración).
void mostrarPila(const Pila& pila);

// --- Prototipos de Funciones Específicas del Ejercicio 74 ---

// Prototipo para imprimir los elementos de una cola en orden inverso usando una pila auxiliar.
void imprimirColaInversa(Cola& cola_original);

// --- Prototipo de la Función Principal del Ejercicio ---

// Prototipo de la función principal para resolver el Ejercicio 74.
void resolverEjercicio74();

#endif // FUNCIONES_H