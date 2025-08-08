#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int matriz[MAX][MAX], transpuesta[MAX][MAX];
    int filas, columnas;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    leerMatriz(matriz, filas, columnas);

    cout << "\nMatriz original:\n";
    imprimirMatriz(matriz, filas, columnas);

    transponerMatriz(matriz, transpuesta, filas, columnas);

    cout << "\nMatriz transpuesta:\n";
    imprimirMatriz(transpuesta, columnas, filas);

    return 0;
}
