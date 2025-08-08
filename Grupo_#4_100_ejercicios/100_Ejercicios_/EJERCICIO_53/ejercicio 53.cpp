//Nombre: Cristina Cruz
//Fecha: 7 jul 2025
//Descripción:  Este codigo contiene un struct con título, autor, editorial y año de publicación.

#include <iostream>
using namespace std;
const int MAX_CADENA = 100;

struct Libro {
    char titulo[MAX_CADENA];
    char autor[MAX_CADENA];
    char editorial[MAX_CADENA];
    int anoPublicacion;
};
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
int main() {
    saludo();

    do {
        Libro miLibro;

        cout << "\nIngresa los datos del libro:" << endl;
        leerLibro(miLibro);

        mostrarLibro(miLibro);

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}
