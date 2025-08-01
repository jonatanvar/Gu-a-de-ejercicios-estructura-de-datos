// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Declaración de la función para obtener un número entero validado del usuario.
// Recibe un mensaje a mostrar al usuario.
// Retorna un valor long long válido.
long long validarEntradaNumerica(const char* mensaje);

// Declaración de la función para encontrar el valor máximo en un arreglo de enteros.
// Recibe el arreglo y su tamaño.
// Retorna el valor máximo encontrado.
int encontrarMaximo(const int arr[], int tamano);

// Declaración de la función para encontrar el valor mínimo en un arreglo de enteros.
// Recibe el arreglo y su tamaño.
// Retorna el valor mínimo encontrado.
int encontrarMinimo(const int arr[], int tamano);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
// Retorna 1 para 'Sí', 2 para 'No'. Incluye validación de entrada.
int preguntarRepetir();

#endif // FUNCIONES_H