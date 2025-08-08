#include <iostream>
#include "funciones.h"

using namespace std;

void leerArreglo(int arreglo[], int n) {
    cout << "Ingrese " << n << " numeros ordenados:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemento [" << i << "]: ";
        cin >> arreglo[i];
    }
}

int busquedaBinaria(int arreglo[], int n, int objetivo) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;

        if (arreglo[medio] == objetivo) {
            return medio;
        } else if (arreglo[medio] < objetivo) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1;
}
