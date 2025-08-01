// Autor: Jorge Mendoza.
// Fecha: 21/07/2025.
#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int repetirPrograma;

    do {
        int miMatriz[3][MAX_COLS] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };

        constexpr  int NUM_FILAS = 3;
        constexpr int NUM_COLS_REAL = MAX_COLS;

        int columnaUsuario;

        cout << "Matriz disponible:\n";
        for (int i = 0; i < NUM_FILAS; i++) {
            for (int j = 0; j < NUM_COLS_REAL; j++) {
                cout << miMatriz[i][j] << "\t";
            }
            cout << "\n";
        }

        while (true) {
            cout << "Ingrese el numero de columna a sumar (1 a " << NUM_COLS_REAL << "): ";
            cin >> columnaUsuario;

            if (cin.fail()) {
                cout << "Error: Por favor, ingresa un valor numerico valido.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                cin.ignore(1000, '\n');
                if (columnaUsuario >= 1 && columnaUsuario <= NUM_COLS_REAL) {
                    break;
                } else {
                    cout << "Error: La columna " << columnaUsuario << " esta fuera del rango. Debe ser entre 1 y " << NUM_COLS_REAL << ".\n";
                }
            }
        }

        int columnaIndice = columnaUsuario - 1;
        int sumaColumna = sumarColumnaMatriz(miMatriz, NUM_FILAS, NUM_COLS_REAL, columnaIndice);
        if (sumaColumna != -1) {
            cout << "La suma de los elementos de la columna " << columnaUsuario << " es: " << sumaColumna << "\n";
        } else {
            cout << "Error: El indice de columna fue invalido (problema interno o logico).\n";
        }

        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}