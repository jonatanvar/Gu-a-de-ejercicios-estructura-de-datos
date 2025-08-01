// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define el tamaño fijo del arreglo.
constexpr int TamanioArreglo = 5;

// Declaración de la función para validar y leer una entrada numérica.
double validarEntradaNumerica(const char* mensaje);

// Declaración de la función para imprimir los elementos de un arreglo.
void imprimirArreglo(const double arr[], int tamanio);

// Declaración de la función para ordenar un arreglo de doubles usando el algoritmo de selección ascendente.
// Recibe el arreglo y su tamaño.
void ordenarAscendentePorSeleccion(double arr[], int tamanio);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
int preguntarRepetir();

#endif // FUNCIONES_H