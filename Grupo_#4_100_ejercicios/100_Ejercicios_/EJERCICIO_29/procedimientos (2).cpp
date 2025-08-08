#include "funciones.h"

void saludo() {
    cout << "Hola! Bienvenido al programa para encontrar el menor elemento por columna." << endl;
    cout << "Vamos a pedirte una matriz y te dire cual es el numero mas pequeno en cada columna." << endl;
}

bool funcionseguir() {
    char opcion;
    cout << "\nQuieres encontrar el menor elemento en otra matriz? (s/n): ";
    cin >> opcion;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int& num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Eso no es un numero! Por favor, ingresa un numero entero valido: ";
        cin >> num;
    }
}

void funcionvalidarDimension(int& dim) {
    while (cin.fail() || dim <= 0 || dim > MAX_DIM) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Dimension invalida! Debe ser un numero entre 1 y " << MAX_DIM << ": ";
        cin >> dim;
    }
}

void pedirDatosMatriz(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas) {
    cout << "\nAhora ingresa los numeros para tu matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
            funcionvalidar(matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas) {
    cout << "\nTu matriz es:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void encontrarMenorPorColumna(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas) {
    cout << "\nLos valores minimos por columna son:" << endl;

    for (int j = 0; j < columnas; ++j) {
        int menorColumna = matriz[0][j];

        for (int i = 1; i < filas; ++i) {
            if (matriz[i][j] < menorColumna) {
                menorColumna = matriz[i][j];
            }
        }
        cout << "Columna " << j + 1 << ": " << menorColumna << endl;
    }
}