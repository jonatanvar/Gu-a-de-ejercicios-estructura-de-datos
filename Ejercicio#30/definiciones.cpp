#include "cabecera.h"
#include <iostream>
using namespace std;

void obtenerDimensiones(int& filas, int& columnas) {
    do {
        cout << "Ingrese el numero de filas (1-10): ";
        cin >> filas;
    } while (filas < 1 || filas > 10);

    do {
        cout << "Ingrese el numero de columnas (1-10): ";
        cin >> columnas;
    } while (columnas < 1 || columnas > 10);
}

void ingresarElementosMatriz(int matriz[10][10], int filas, int columnas) {
    cout << "\nIngrese los elementos:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarMatriz(int matriz[10][10], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void ordenarFila(int matriz[10][10], int columnas, int fila_a_ordenar, char orden) {
    for (int i = 0; i < columnas - 1; i++) {
    for (int j = 0; j < columnas - i - 1; j++) {
    if ((orden == 'a' && matriz[fila_a_ordenar][j] > matriz[fila_a_ordenar][j+1]) ||
                (orden == 'd' && matriz[fila_a_ordenar][j] < matriz[fila_a_ordenar][j+1])) {
                int temp = matriz[fila_a_ordenar][j];
                matriz[fila_a_ordenar][j] = matriz[fila_a_ordenar][j+1];
                matriz[fila_a_ordenar][j+1] = temp;
            }
        }
    }
}

int obtenerFilaAOrdenar(int max_filas) {
    int fila;
    do {
        cout << "\nIngrese el numero de la fila a ordenar (0-" << max_filas - 1 << "): ";
        cin >> fila;
    } while (fila < 0 || fila >= max_filas);
    return fila;
}

char obtenerTipoOrden() {
    char orden_char;
    do {
        cout << "¿Como desea ordenar la fila? (a: ascendente, d: descendente): ";
        cin >> orden_char;
    } while (orden_char != 'a' && orden_char != 'd');
    return orden_char;
}