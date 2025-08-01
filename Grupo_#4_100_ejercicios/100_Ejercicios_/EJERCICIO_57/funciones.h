// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Definición de la estructura (struct) para representar una fracción.
// Contiene dos miembros enteros: 'numerador' y 'denominador'.
struct Fraccion {
    int numerador;   // Parte superior de la fracción.
    int denominador; // Parte inferior de la fracción.
};

// Declaración de la función para validar y leer una entrada numérica (int).
int validarEntradaNumerica(const char* mensaje);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
int preguntarRepetir();

#endif // FUNCIONES_H