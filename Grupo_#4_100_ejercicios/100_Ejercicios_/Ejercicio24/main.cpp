//
// Created by klain on 14/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    int filasA, columnasA;
    int filasB, columnasB;
    int** matrizA = nullptr;
    int** matrizB = nullptr;
    int** matrizResultado = nullptr;

    saludo();

    do {
        cout << "Ingrese el numero de filas y columnas de la primera matriz (ej: 3 4): ";
        funcionvalidarDimension(filasA, columnasA);

        cout << "Ingrese el numero de filas y columnas de la segunda matriz (ej: 4 2): ";
        funcionvalidarDimension(filasB, columnasB);

        if (columnasA != filasB) {
            cout << "Error: Para multiplicar matrices, el numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda matriz." << endl;
            cout << "Por favor, intente de nuevo con dimensiones compatibles." << endl;
            continue;
        }

        matrizA = crearMatriz(filasA, columnasA);
        matrizB = crearMatriz(filasB, columnasB);

        cout << "\n--- Matriz A ---" << endl;
        pedirElementosMatriz(matrizA, filasA, columnasA);
        imprimirMatriz(matrizA, filasA, columnasA); // Mostrar la matriz A ingresada

        cout << "\n--- Matriz B ---" << endl;
        pedirElementosMatriz(matrizB, filasB, columnasB);
        imprimirMatriz(matrizB, filasB, columnasB); // Mostrar la matriz B ingresada

        cout << "\n--- Multiplicando matrices... ---" << endl;
        matrizResultado = multiplicarMatrices(matrizA, matrizB, filasA, columnasA, filasB, columnasB);

        cout << "\n--- Matriz Resultado (A * B) ---" << endl;
        imprimirMatriz(matrizResultado, filasA, columnasB);

        eliminarMatriz(matrizA, filasA);
        eliminarMatriz(matrizB, filasB);
        eliminarMatriz(matrizResultado, filasA); // La matriz resultado tiene 'filasA' filas

    } while (funcionSeguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}