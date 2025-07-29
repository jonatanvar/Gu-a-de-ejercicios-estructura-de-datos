//
// Created by klain on 17/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

const int MAX_ELEMENTOS = 50;

int main() {
    int numeros[MAX_ELEMENTOS];
    int n;

    saludo();

    do {
        cout << "Ingrese la cantidad de numeros (maximo " << MAX_ELEMENTOS << "): ";
        funcionvalidar(n);

        if (n > MAX_ELEMENTOS) {
            cout << "La cantidad de numeros excede el maximo permitido. Intente de nuevo. 😅" << endl;
            continue;
        }

        if (n < 1) {
            cout << "Debe ingresar al menos un numero. Intente de nuevo. 🤔" << endl;
            continue;
        }

        cout << "Ingrese los " << n << " numeros: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Numero " << i + 1 << ": ";
            funcionvalidar(numeros[i]);
        }

        cout << "\nCalculando cuartiles:" << endl;
        cout << "Q1 (Primer Cuartil): " << calcularCuartil(numeros, n, 1) << endl;
        cout << "Q2 (Segundo Cuartil / Mediana): " << calcularCuartil(numeros, n, 2) << endl;
        cout << "Q3 (Tercer Cuartil): " << calcularCuartil(numeros, n, 3) << endl;

    } while (funcionSeguir());

    return 0;
}