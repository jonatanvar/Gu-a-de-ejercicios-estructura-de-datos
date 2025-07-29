#ifndef CABECERA_H
#define CABECERA_H

// Definicion de la estructura del Libro
struct Libro {
 char titulo[100];
 char autor[100];
 char año_publicacion[5]; // Se mantiene char[] segun original
 char genero [30];
 char isbn[20];
 bool disponible;
};

// Constante para el tamano maximo del arreglo de libros
const int MAX_LIBROS = 100;

// Prototipos de funciones
void mostrarLibro(Libro l);
void agregarLibro(Libro &l);
void mostrarLibros(Libro Biblioteca[], int cantidad);
void buscarporTitulo(Libro Biblioteca[], int cantidad);
void cambiarDisponibilidad(Libro Biblioteca[], int cantidad);

// Funciones de utilidad para el menu y la entrada
void mostrarMenu();
char obtenerOpcion();
bool compararCadenas(const char cadena1[], const char cadena2[]);

#endif // CABECERA_H