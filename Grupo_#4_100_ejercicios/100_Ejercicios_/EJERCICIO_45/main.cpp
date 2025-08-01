// Autor: Jorge Mendoza.
// Fecha: 22/07/2025.

#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    char cadena[MAX_LONGITUD_CADENA];
    int repetirPrograma;

    cout << "Bienvenido al programa para verificar si una cadena es un palindromo. :)\n";

    do {

        leerCadena("Ingrese una cadena de texto: ", cadena, MAX_LONGITUD_CADENA);

        if (esPalindromo(cadena)) {
            cout << "La cadena '" << cadena << "' ES un palindromo.\n";
        } else {
            cout << "La cadena '" << cadena << "' NO es un palindromo.\n";
        }

        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}