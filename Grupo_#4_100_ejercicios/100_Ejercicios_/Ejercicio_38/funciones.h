//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones y constantes para el ejercicio Concatenar Dos Cadenas.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define la longitud máxima para las cadenas (incluyendo el carácter nulo '\0').
// Esta constante debe estar disponible en el encabezado para que los prototipos de función
// que utilizan arreglos de caracteres de tamaño fijo puedan compilar correctamente.
const int MAX_STRING_LENGTH = 100;

// Prototipo de la función para obtener la longitud de una cadena de caracteres manualmente.
int obtenerLongitudCadena(const char* str);

// Prototipo de la función para obtener una cadena de caracteres del usuario.
// str: Arreglo de caracteres donde se almacenará la cadena.
// max_len: Longitud máxima del buffer del arreglo.
// prompt: Mensaje a mostrar al usuario.
void obtenerCadena(char* str, int max_len, const char* prompt);

// Prototipo de la función para concatenar dos cadenas manualmente en una tercera cadena.
// str1: Primera cadena de origen (const para no modificarla).
// str2: Segunda cadena de origen (const para no modificarla).
// resultado: Arreglo de caracteres donde se almacenará la cadena concatenada.
// max_len_resultado: Longitud máxima del buffer del arreglo resultado.
void concatenarCadenas(const char* str1, const char* str2, char* resultado, int max_len_resultado);

// Prototipo de la función principal para resolver el Ejercicio 38.
// Orquesta las llamadas a las demás funciones para completar la tarea.
void resolverEjercicio38();

#endif // FUNCIONES_H