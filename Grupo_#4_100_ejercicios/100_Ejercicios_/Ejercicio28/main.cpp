//
// Created by klain on 11/7/2025.
//

#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    int filas, columnas;
    int matriz[100][100];

    saludo();

    do {
        solicitarDimension(filas, columnas);
        leerMatriz(matriz, filas, columnas);
        encontrarMayorPorFila(matriz, filas, columnas);
    } while (funcionSeguir());

    return 0;
}