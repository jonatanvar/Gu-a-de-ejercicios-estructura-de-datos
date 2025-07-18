//
// Created by klain on 14/7/2025.
//
#include "Funciones.h"
#include <iostream>

using namespace std;

int main() {
    saludo();

    bool continuar = true;
    while (continuar) {
        int numElementos;
        cout << "Ingrese el numero de elementos del arreglo: ";
        funcionvalidar(numElementos);

        int *arr = new int[numElementos];

        cout << "Ingrese los " << numElementos << " elementos del arreglo:" << endl;
        for (int i = 0; i < numElementos; ++i) {
            cout << "Elemento " << i + 1 << ": ";
                        cin >> arr[i];
        }

        cout << "Arreglo original: ";
        imprimirArreglo(arr, numElementos);

        invertirArreglo(arr, numElementos);

        cout << "Arreglo invertido: ";
        imprimirArreglo(arr, numElementos);

        delete[] arr;

        continuar = funcionSeguir();
    }

    cout << "Gracias por usar el programa. Hasta luego" << endl;
    return 0;
}
