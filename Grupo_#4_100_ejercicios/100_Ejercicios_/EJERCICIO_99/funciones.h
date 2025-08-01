// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Declaración de la función auxiliar para determinar si un año es bisiesto.
// Retorna 'true' si el año es bisiesto, 'false' en caso contrario.
bool esBisiesto(int anio);

// Declaración de la función para validar si una fecha (día, mes, año) es válida.
// Retorna 'true' si la fecha es válida, 'false' en caso contrario.
bool validarFecha(int dia, int mes, int anio);

// Declaración de la función para validar y leer una entrada numérica entera.
// Recibe un mensaje a mostrar al usuario.
// Retorna un valor int válido.
int validarEntradaNumericaInt(const char* mensaje);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
// Retorna 1 para 'Sí', 2 para 'No'. Incluye validación de entrada.
int preguntarRepetir();

#endif // FUNCIONES_H