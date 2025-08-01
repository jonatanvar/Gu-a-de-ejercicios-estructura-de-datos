//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones y constantes para el ejercicio Ordenar Arreglo Descendente (Burbuja).

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string, usado en prompts.

// --- Constante para el tamaño máximo del arreglo ---
const int MAX_TAMANO_ARREGLO = 10;

// --- Prototipos de Funciones Auxiliares Generales ---

// Prototipo de la función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt);

// --- Prototipos de Funciones de Arreglo ---

// Prototipo de la función para inicializar el arreglo con valores.
void inicializarArreglo(int arr[], int tamano);

// Prototipo de la función para mostrar el arreglo.
void mostrarArreglo(const int arr[], int tamano);

// Prototipo de la función que ordena un arreglo en orden descendente utilizando el algoritmo de burbuja.
void ordenarBurbujaDescendente(int arr[], int tamano);

// --- Prototipo de la Función Principal del Ejercicio ---

// Prototipo de la función principal para resolver el Ejercicio 32.
void resolverEjercicio32();

#endif // FUNCIONES_H