// Autor: Jorge Mendoza.
// Fecha: 21/07/2025.
#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define el número máximo de columnas para las matrices
const int MAX_COLS = 4;

// Declaración de la función para sumar los elementos de una columna específica en una matriz.
int sumarColumnaMatriz(int matriz[][MAX_COLS], int numFilas, int numColumnas, int columnaIndice);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
int preguntarRepetir();

#endif // FUNCIONES_H