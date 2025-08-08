#include <iostream>
#include "funciones.h"

using namespace std;

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