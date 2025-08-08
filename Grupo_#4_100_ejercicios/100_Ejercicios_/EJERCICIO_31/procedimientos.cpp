#include <iostream>
#include "funciones.h"
using namespace std;

void leerArreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento [" << i << "]: ";
        cin >> arreglo[i];
    }
}

void mostrarArreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void ordenarBurbuja(int arreglo[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}
