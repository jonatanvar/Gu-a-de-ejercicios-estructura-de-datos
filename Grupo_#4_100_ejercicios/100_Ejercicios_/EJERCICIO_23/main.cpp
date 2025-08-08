#include <iostream>
#include "funciones.h" // Incluimos nuestro archivo de encabezado

using namespace std;

int main() {
    saludo();

    do {
        int filas, columnas;
        int matrizA[MAX_DIM][MAX_DIM];
        int matrizB[MAX_DIM][MAX_DIM];

        cout << "Primero, dime cuantas filas tendran tus matrices (max " << MAX_DIM << "): ";
        cin >> filas;
        funcionvalidarDimension(filas);

        cout << "Ahora, cuantas columnas tendran (max " << MAX_DIM << "): ";
        cin >> columnas;
        funcionvalidarDimension(columnas);

        pedirDatosMatriz(matrizA, filas, columnas, 1);
        pedirDatosMatriz(matrizB, filas, columnas, 2);

        sumarYMostrarMatrices(matrizA, matrizB, filas, columnas);

    } while (funcionseguir());

    cout << "Adios! Gracias por usar el programa." << endl;

    return 0;
}