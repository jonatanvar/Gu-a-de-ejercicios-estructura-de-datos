// Autor: Jorge Mendoza.
// Fecha: 22/07/2025.

#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int repetirPrograma;

    cout << "Bienvenido al programa de gestion de fracciones. :)\n";

    do {
        Fraccion miFraccion;

        cout << "\n--- Ingrese los valores para la fraccion ---\n";

        miFraccion.numerador = validarEntradaNumerica("Ingrese el numerador: ");

        while (true) {
            miFraccion.denominador = validarEntradaNumerica("Ingrese el denominador (no puede ser cero): ");
            if (miFraccion.denominador == 0) {
                cout << "Error: El denominador no puede ser cero. Por favor, ingresa un valor diferente." << endl;
            } else {
                break;
            }
        }

        cout << "\nLa fraccion ingresada es: " << miFraccion.numerador << "/" << miFraccion.denominador << "\n";

        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}