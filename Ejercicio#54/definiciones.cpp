#include "cabecera.h"
#include <iostream>
using namespace std;

void mostrarLibro(Libro l) {
    cout << "Titulo: " << l.titulo << endl;
    cout << "Autor: " << l.autor << endl;
    cout << "Anio de publicacion: " << l.año_publicacion << endl;
    cout << "ISBN: " << l.isbn << endl;
    cout << "-------------------------" << endl;
}

void agregarLibro(Libro Biblioteca[], int &cantidad) {
    // Este mensaje se mantuvo aqui, como en tu codigo original
    cout << "\nLibro agregado exitosamente.\n";

    cout << "\n=== AGREGAR LIBRO ===\n";
    cout << "Ingrese el titulo del libro: ";
    cin >> Biblioteca[cantidad].titulo; // Se mantiene cin >> para cadenas

    cout << "Ingrese el autor del libro: ";
    cin >> Biblioteca[cantidad].autor; // Se mantiene cin >> para cadenas

    cout << "Ingrese el anio de publicacion del libro: ";
    cin >> Biblioteca[cantidad].año_publicacion; // Se mantiene cin >> para cadenas

    cout << "Ingrese el genero del libro: ";
    cin >> Biblioteca[cantidad].genero; // Se mantiene cin >> para cadenas

    cout << "Ingrese el ISBN del libro: ";
    cin >> Biblioteca[cantidad].isbn; // Se mantiene cin >> para cadenas

    Biblioteca[cantidad].disponible = true;
}

// Las funciones mostrarLibros, buscarporTitulo y cambiarDisponibilidad
// no tienen definicion aqui, al no estar presentes en tu codigo original.