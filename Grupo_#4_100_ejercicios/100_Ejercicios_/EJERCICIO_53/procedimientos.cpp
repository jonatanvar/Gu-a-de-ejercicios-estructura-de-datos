#include "funciones.h"

void saludo() {
    cout << "Hola! Bienvenido al programa de gestion de libros." << endl;
    cout << "Podras ingresar datos de un libro y luego verlos." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nDeseas ingresar otro libro? (s/n): ";
    cin >> opcion;
    cin.ignore(100, '\n');
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Entrada invalida. Ingresa un numero entero valido: ";
        cin >> num;
    }
}

void leerLibro(Libro& lib) {
    cout << "  Titulo: ";
    cin.getline(lib.titulo, MAX_CADENA);

    cout << "  Autor: ";
    cin.getline(lib.autor, MAX_CADENA);

    cout << "  Editorial: ";
    cin.getline(lib.editorial, MAX_CADENA);

    cout << "  Ano de Publicacion: ";
    cin >> lib.anoPublicacion;
    funcionvalidar(lib.anoPublicacion);
    cin.ignore(100, '\n');
}

void mostrarLibro(const Libro& lib) {
    cout << "\n--- Datos del Libro ---" << endl;
    cout << "  Titulo: " << lib.titulo << endl;
    cout << "  Autor: " << lib.autor << endl;
    cout << "  Editorial: " << lib.editorial << endl;
    cout << "  Ano de Publicacion: " << lib.anoPublicacion << endl;
}