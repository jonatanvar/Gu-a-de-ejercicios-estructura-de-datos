#include <iostream>
#include <string>
#include "funciones.h"

using namespace std;

int main() {
    const int MAX = 5;
    string libros[MAX] = {
        "Cien Anios de Soledad",
        "Don Quijote de la Mancha",
        "La Odisea",
        "El Principito",
        "Orgullo y Prejuicio"
    };

    string titulo;
    cout << "Ingrese el titulo del libro que desea buscar: ";
    getline(cin, titulo);

    int posicion = buscarLibro(libros, MAX, titulo);

    if (posicion != -1) {
        cout << "El libro '" << libros[posicion] << "' fue encontrado en la posicion " << posicion << "." << endl;
    } else {
        cout << "El libro no se encuentra en la lista." << endl;
    }

    return 0;
}
