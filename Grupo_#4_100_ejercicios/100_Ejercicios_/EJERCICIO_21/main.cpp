// Autor: Jorge Mendoza
// Fecha: 7/21/2025.

#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int repetirPrograma;

    do {
        int miArreglo[] = {10, 25, 30, 45, 50, 65, 70, 85, 90, 100};
        int tamanoArreglo = sizeof(miArreglo) / sizeof(miArreglo[0]);

        int valorABuscar;

        cout << "Arreglo disponible: [";
        for (int i = 0; i < tamanoArreglo; i++) {
            cout << miArreglo[i];
            if (i < tamanoArreglo - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";

        while (true) {
            cout << "Ingrese el valor que desea buscar en el arreglo: ";
            cin >> valorABuscar;

            if (cin.fail()) {
                cout << "Error: Por favor, ingresa un valor numerico valido.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        int posicionEncontrada = buscarElemento(miArreglo, tamanoArreglo, valorABuscar);
        if (posicionEncontrada != -1) {
            cout << "El valor " << valorABuscar << " se ha encontrado en la posicion (indice) " << posicionEncontrada << ".\n";
        } else {
            cout << "El valor " << valorABuscar << " no se ha encontrado en el arreglo.\n";
        }

        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);

    cout << "\nGracias por usar el programa. :)\n";

    return 0;
}