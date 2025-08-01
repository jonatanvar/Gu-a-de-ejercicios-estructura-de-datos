//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Declaración de prototipos de funciones, estructuras y constantes para el ejercicio Buscar Libro por Autor.

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string> // Para std::string.

// Constante para el número máximo de libros.
const int MAX_LIBROS = 10;

// Definición de la estructura para un Libro.
struct Libro {
    std::string titulo;
    std::string autor;
};

// Prototipo de la función auxiliar para obtener y validar un entero positivo.
int obtenerEnteroPositivoValido(const char* prompt);

// Prototipo de la función auxiliar para obtener una cadena (std::string) del usuario.
void obtenerCadena(std::string& str, const char* prompt);

// Prototipo de la función para convertir una cadena a minúsculas.
std::string aMinusculas(const std::string& str);

// Prototipo de la función para pedir los datos de un libro (título y autor).
void pedirDatosLibro(Libro& libro);

// Prototipo de la función para mostrar la información de un libro.
void mostrarLibro(const Libro& libro);

// Prototipo de la función para buscar y mostrar todos los libros de un autor dado.
void buscarLibrosPorAutor(const Libro lista_libros[], int num_libros, const std::string& autor_buscar);

// Prototipo de la función principal para resolver el Ejercicio 56.
void resolverEjercicio56();

#endif // FUNCIONES_H