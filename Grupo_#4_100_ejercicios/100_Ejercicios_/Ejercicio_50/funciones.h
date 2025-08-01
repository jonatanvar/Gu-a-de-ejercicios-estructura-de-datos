//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones, estructuras y constantes para el ejercicio Estudiante con Promedio Más Alto.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string.
#include <iomanip> // Para std::fixed y std::setprecision.

// Constantes para los límites de estudiantes y notas.
const int MAX_ESTUDIANTES = 10;
const int MAX_NOTAS = 5;

// Definición de la estructura para un Estudiante.
struct Estudiante {
    std::string nombre; // Usamos std::string para el nombre.
    float notas[MAX_NOTAS]; // Arreglo estático para las notas.
    int num_notas;         // Cantidad real de notas ingresadas.
    float promedio;        // Promedio calculado.
};

// Prototipo de la función auxiliar para obtener y validar un entero positivo.
int obtenerEnteroPositivoValido(const char* prompt);

// Prototipo de la función auxiliar para obtener y validar un número flotante.
float obtenerFlotanteValido(const char* prompt);

// Prototipo de la función para pedir los datos de un estudiante (nombre y notas).
void pedirDatosEstudiante(Estudiante& estudiante, int max_notas_permitidas);

// Prototipo de la función para calcular el promedio de un estudiante.
void calcularPromedio(Estudiante& estudiante);

// Prototipo de la función para mostrar la información de un estudiante.
void mostrarEstudiante(const Estudiante& estudiante);

// Prototipo de la función para encontrar al estudiante con el promedio más alto.
void encontrarMejorEstudiante(const Estudiante estudiantes[], int num_estudiantes, Estudiante& mejor_estudiante);

// Prototipo de la función principal para resolver el Ejercicio 50.
void resolverEjercicio50();

#endif // FUNCIONES_H