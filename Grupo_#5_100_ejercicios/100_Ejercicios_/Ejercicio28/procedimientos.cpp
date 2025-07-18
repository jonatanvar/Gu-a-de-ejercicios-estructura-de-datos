//
// Created by klain on 11/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA ENCONTRAR EL MAYOR ELEMENTO POR FILA EN UNA MATRIZ" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea procesar otra matriz? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int &x) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        } else if (x <= 0 || x > 100) {
            cout << "Error. El numero debe ser mayor que cero y menor o igual a 100. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

void solicitarDimension(int &filas, int &columnas) {
    cout << "Ingrese el numero de filas de la matriz (max 100): ";
    funcionvalidar(filas);
    cout << "Ingrese el numero de columnas de la matriz (max 100): ";
    funcionvalidar(columnas);
}

void leerMatriz(int matriz[][100], int filas, int columnas) {
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            funcionvalidar(matriz[i][j]);
        }
    }
}

void encontrarMayorPorFila(int matriz[][100], int filas, int columnas) {
    cout << "\nMayor elemento por fila:" << endl;
    for (int i = 0; i < filas; i++) {
        int mayor = matriz[i][0];
        for (int j = 1; j < columnas; j++) {
            if (matriz[i][j] > mayor) {
                mayor = matriz[i][j];
            }
        }
        cout << "Fila " << i + 1 << ": " << mayor << endl;
    }
}