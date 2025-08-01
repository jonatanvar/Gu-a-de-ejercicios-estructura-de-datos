//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones, estructuras y constantes para el ejercicio Implementar Cola con Arreglo.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string, usado en prompts.

// Constante para el tamaño máximo de la cola.
const int MAX_TAMANO_COLA = 5;

// Definición de la estructura para la Cola.
struct Cola {
    int elementos[MAX_TAMANO_COLA]; // Arreglo estático para almacenar los elementos.
    int frente;                     // Índice del elemento frontal de la cola.
    int final;                      // Índice del elemento final de la cola.
};

// Prototipo de la función para inicializar la cola.
void inicializarCola(Cola& cola);

// Prototipo de la función auxiliar para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt);

// Prototipo de la función para verificar si la cola está vacía.
bool estaVacia(const Cola& cola);

// Prototipo de la función para verificar si la cola está llena.
bool estaLlena(const Cola& cola);

// Prototipo de la función enqueue: agrega un elemento al final de la cola.
void enqueue(Cola& cola, int elemento);

// Prototipo de la función dequeue: elimina y retorna el elemento del frente de la cola.
bool dequeue(Cola& cola, int& elemento);

// Prototipo de la función verFrente: permite ver el elemento del frente sin eliminarlo.
bool verFrente(const Cola& cola, int& elemento);

// Prototipo de la función para mostrar los elementos de la cola.
void mostrarCola(const Cola& cola);

// Prototipo de la función principal para resolver el Ejercicio 68.
void resolverEjercicio68();

#endif // FUNCIONES_H