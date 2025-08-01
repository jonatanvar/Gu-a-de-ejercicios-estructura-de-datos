// Autor: Jorge Mendoza.
// Fecha: 7/21/2025.

#include "funciones.h"
#include <iostream>
using namespace std;

int main() {
    int repetirPrograma;
    do {
        int numeroIngresado;

        while (true) {
            cout << "Ingrese un numero entero para verificar si es par o impar: ";
            cin >> numeroIngresado;

            if (cin.fail()) {
                cout << "Error: Por favor, ingresa un valor numerico entero valido.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        if (esPar(numeroIngresado)) {
            cout << "El numero " << numeroIngresado << " es PAR.\n";
        } else {
            cout << "El numero " << numeroIngresado << " es IMPAR.\n";
        }
        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}