// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#ifndef FUNCIONES_H
#define FUNCIONES_H

// Definición de la estructura (struct) para representar un punto en un plano 2D.
// Contiene dos miembros públicos: 'x' e 'y', para sus coordenadas.
struct Punto {
    double x; // Coordenada en el eje X
    double y; // Coordenada en el eje Y
};

// Declaración de la función para validar y leer una entrada numérica (double).
double validarEntradaNumerica(const char* mensaje);

// Declaración de la función para preguntar al usuario si desea repetir el programa.
int preguntarRepetir();

#endif // FUNCIONES_H