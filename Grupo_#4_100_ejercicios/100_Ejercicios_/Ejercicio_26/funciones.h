//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones y constantes para el ejercicio Sumar Fila Específica de Matriz.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string, usado en prompts.

// --- Constantes para las dimensiones máximas de la matriz ---
const int MAX_FILAS = 5;
const int MAX_COLUMNAS = 5;

// --- Prototipos de Funciones Auxiliares Generales ---

// Prototipo de la función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt);

// --- Prototipos de Funciones de Matriz ---

// Prototipo de la función para inicializar la matriz con valores.
void inicializarMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas);

// Prototipo de la función para mostrar la matriz.
void mostrarMatriz(const int matriz[][MAX_COLUMNAS], int filas, int columnas);

// Prototipo de la función que suma los elementos de una fila específica de la matriz.
int sumarFilaEspecifica(const int matriz[][MAX_COLUMNAS], int filas, int columnas, int fila_a_sumar);

// --- Prototipo de la Función Principal del Ejercicio ---

// Prototipo de la función principal para resolver el Ejercicio 26.
void resolverEjercicio26();

#endif // FUNCIONES_H