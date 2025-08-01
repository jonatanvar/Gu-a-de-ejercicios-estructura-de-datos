// Autor: Jorge Mendoza.
// Fecha: 22/07/2025.
#include <iostream>
#include "funciones.h"
using namespace std;

constexpr int MAX_LONGITUD_CADENA = 100;

int main() {
    int repetirPrograma;

    cout << "Bienvenido al programa de comparacion de cadenas. :)\n";

    do {
        char cadena1[MAX_LONGITUD_CADENA];
        char cadena2[MAX_LONGITUD_CADENA];

        cout << "Ingrese la primera cadena: ";
        cin.getline(cadena1, MAX_LONGITUD_CADENA);

        cout << "Ingrese la segunda cadena: ";
        cin.getline(cadena2, MAX_LONGITUD_CADENA);

        if (compararCadenas(cadena1, cadena2)) {
            cout << "Las cadenas son IGUALES.\n";
        } else {
            cout << "Las cadenas son DIFERENTES.\n";
        }
        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}