// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Define un tamaño máximo para el arreglo de datos, por si el usuario ingresa muchos.
constexpr int MAX_DATOS = 100;

// Declaración de la función para calcular la media (promedio) de un conjunto de datos.
// Recibe un arreglo de números de punto flotante y la cantidad de elementos válidos.
// Retorna el promedio calculado. Si el tamaño es 0, retorna 0.0 para evitar división por cero.
double calcularMedia(const double datos[], int cantidad);

// Declaración de la función para validar y leer una entrada numérica (int o double).
// Se sobrecarga para manejar ambos tipos de datos si es necesario, o se usa una más genérica.
// Para este ejercicio, necesitaremos una para el tamaño (int) y otra para los datos (double).

// Declaración de la función para validar y leer una entrada numérica entera.
// Recibe un mensaje a mostrar al usuario.
// Retorna un valor int válido.
int validarEntradaNumericaInt(const char* mensaje);

// Declaración de la función para validar y leer una entrada numérica de punto flotante.
// Recibe un mensaje a mostrar al usuario.
// Retorna un valor double válido.
double validarEntradaNumericaDouble(const char* mensaje);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
// Retorna 1 para 'Sí', 2 para 'No'. Incluye validación de entrada.
int preguntarRepetir();

#endif // FUNCIONES_H