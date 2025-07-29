//Nombre: Jonatan Varela
//Fecha: 25/06/2025
#include <iostream>
#include "cabecera.h"
using namespace std;

int main() {
    int matriz[10][10];
    int filas, columnas;
    char continuar_programa;

    cout << "=== ORDENAR FILA DE MATRIZ ===\n";

    obtenerDimensiones(filas, columnas);

    ingresarElementosMatriz(matriz, filas, columnas);

    cout << "\nMatriz ingresada:\n";
    mostrarMatriz(matriz, filas, columnas);

    do {
        int fila_a_ordenar;
        char orden;

        fila_a_ordenar = obtenerFilaAOrdenar(filas);

        orden = obtenerTipoOrden();

        ordenarFila(matriz, columnas, fila_a_ordenar, orden);

        cout << "\nMatriz ordenada:\n";
        mostrarMatriz(matriz, filas, columnas);

        cout << "\n¿Desea ordenar otra fila? (s/n): ";
        cin >> continuar_programa;

    } while (continuar_programa == 'S' || continuar_programa == 's');

    cout << "Gracias por usar el programa. Adios! \n ";
    return 0;
}