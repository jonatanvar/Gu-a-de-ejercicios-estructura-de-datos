#ifndef CABECERA_H
#define CABECERA_H

// Solo se incluye iostream, no <limits> ni <ios>
// Definicion de la estructura del estudiante
struct estudiante {
 char nombre[50];
 char carnet[10];
 char carrera[50];
 float promedio;
};

// Constante para el tamano maximo del arreglo de estudiantes
const int MAX_ESTUDIANTES = 100;

// Prototipos de funciones
void mostrarDatos(estudiante e);
void agregarEstudiante(estudiante &e);
void mostrarMenu();
char obtenerOpcion();

#endif // CABECERA_H