// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define la longitud máxima permitida para la cadena de texto.
constexpr int MAX_LONGITUD_CADENA = 256;

// Declaración de la función para verificar si una cadena es un palíndromo.
bool esPalindromo(const char* cadena);

// Declaración de la función para obtener la longitud de una C-string manualmente.
int obtenerLongitud(const char* str);

// Declaración de la función para validar y leer una entrada de tipo char array (C-string).
void leerCadena(const char* mensaje, char buffer[], int max_tamano);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
int preguntarRepetir();

#endif