//Nombre: Cristina Cruz
//Fecha: 5 jul 2025
//Descripción : Este programa encontrara el numero mas pequeño de caca calumna de la matriz.

#include <iostream>
using namespace std;
const int MAX_DIM = 3;

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
int main() {
    saludo();
    do {
        int filas, columnas;
        int miMatriz[MAX_DIM][MAX_DIM];

        cout << "Dime cuantas filas tendra tu matriz (max " << MAX_DIM << "): ";
        cin >> filas;
        funcionvalidarDimension(filas);

        cout << "Ahora, cuantas columnas tendra (max " << MAX_DIM << "): ";
        cin >> columnas;
        funcionvalidarDimension(columnas);

        pedirDatosMatriz(miMatriz, filas, columnas);

        mostrarMatriz(miMatriz, filas, columnas);

        encontrarMenorPorColumna(miMatriz, filas, columnas);

    } while (funcionseguir());

    cout << "Gracias por usar el programa." << endl;

    return 0;
}
