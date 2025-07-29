//
// Created by klain on 14/7/2025.
//

#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    int n;
    int arr[100];

    saludo();

    do {
        cout << "Ingrese el tamaño del arreglo (max 100): ";
        funcionvalidar(n);
        leerArreglo(arr, n);
        ordenarDescendenteSeleccion(arr, n);
        imprimirArreglo(arr, n);
    } while (funcionSeguir());

    return 0;
}