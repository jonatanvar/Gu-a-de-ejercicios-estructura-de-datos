#include <iostream>
#include "funciones.h"

using namespace std;

void leerMatriz(int matriz[MAX][MAX], int filas, int columnas) {
    cout << "Ingrese los elementos de la matriz:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void imprimirMatriz(int matriz[MAX][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void transponerMatriz(int original[MAX][MAX], int transpuesta[MAX][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            transpuesta[j][i] = original[i][j];
        }
    }
}
