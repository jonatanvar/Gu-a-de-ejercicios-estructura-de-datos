//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones y constantes para el ejercicio Reemplazar Subcadena.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define la longitud máxima para las cadenas de entrada y la cadena resultante.
// Estas constantes deben estar disponibles en el encabezado para que los prototipos de función
// que utilizan arreglos de caracteres de tamaño fijo puedan compilar correctamente.
const int MAX_INPUT_LENGTH = 100;
const int MAX_RESULT_LENGTH = MAX_INPUT_LENGTH * 3; // Tamaño generoso para la cadena resultante.

// Prototipo de la función para obtener la longitud de una cadena de caracteres manualmente.
int obtenerLongitudCadena(const char* str);

// Prototipo de la función para obtener una cadena de caracteres del usuario con validación.
void obtenerCadena(char* str, int max_len, const char* prompt);

// Prototipo de la función para buscar la primera ocurrencia de una subcadena (manual).
const char* buscarSubcadena(const char* principal, const char* buscar);

// Prototipo de la función para copiar una porción de una cadena a otra (manual).
void copiarCadenas(char* destino, const char* origen, int longitud);

// Prototipo de la función para reemplazar todas las ocurrencias de una subcadena por otra.
void reemplazarSubcadena(const char* principal, const char* buscar, const char* reemplazar, char* resultado, int max_len_resultado);

// Prototipo de la función principal para resolver el Ejercicio 44.
void resolverEjercicio44();

#endif // FUNCIONES_H