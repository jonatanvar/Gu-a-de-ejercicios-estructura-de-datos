//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones, estructuras y constantes para el ejercicio Función push para Pila.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string, usado en prompts.

// Constante para el tamaño máximo de la pila.
const int MAX_TAMANO_PILA = 5;

// Definición de la estructura para la Pila.
struct Pila {
    int elementos[MAX_TAMANO_PILA]; // Arreglo estático para almacenar los elementos.
    int cima;                       // Índice de la cima de la pila (-1 para pila vacía).
};

// Prototipo de la función para inicializar la pila.
void inicializarPila(Pila& pila);

// Prototipo de la función auxiliar para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt);

// Prototipo de la función para verificar si la pila está llena.
bool estaLlena(const Pila& pila);

// Prototipo de la función push: agrega un elemento a la pila.
void push(Pila& pila, int elemento);

// Prototipo de la función para mostrar los elementos de la pila.
void mostrarPila(const Pila& pila);

// Prototipo de la función principal para resolver el Ejercicio 62.
void resolverEjercicio62();

#endif // FUNCIONES_H