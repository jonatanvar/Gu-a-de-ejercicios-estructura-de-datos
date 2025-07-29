//
// Created by klain on 14/7/2025.
//
#include <iostream>
#include "Funciones.h"
using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA MULTIPLICAR MATRICES" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea realizar otra multiplicacion de matrices? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidarDimension(int &x, int &y) {
    bool entradaValida;
    do {
        entradaValida = true;
        if (!(cin >> x >> y)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros enteros. Intente nuevamente: ";
            entradaValida = false;
        } else if (x <= 0 || y <= 0) {
            cout << "Error. Las dimensiones deben ser mayores que cero. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

void funcionvalidarElemento(int &x) {
    bool entradaValida;
    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros enteros. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}


int** crearMatriz(int filas, int columnas) {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }
    return matriz;
}


void eliminarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}


void pedirElementosMatriz(int** matriz, int filas, int columnas) {
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            funcionvalidarElemento(matriz[i][j]);
        }
    }
}


void imprimirMatriz(int** matriz, int filas, int columnas) {
    cout << "La matriz es:" << endl;
    for (int i = 0; i < filas; ++i) {
        cout << "[ ";
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << "]" << endl;
    }
}


int** multiplicarMatrices(int** matrizA, int** matrizB,
                          int filasA, int columnasA, int filasB, int columnasB) {


    int** matrizResultado = crearMatriz(filasA, columnasB);


    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            matrizResultado[i][j] = 0;
        }
    }


    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                matrizResultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    return matrizResultado;
}