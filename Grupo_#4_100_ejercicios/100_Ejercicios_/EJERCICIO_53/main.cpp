#include <iostream>
#include "funciones.h"

using namespace std;

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