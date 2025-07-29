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

        cout << "Ingrese los " << n << " numeros: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Numero " << i + 1 << ": ";
            funcionvalidar(numeros[i]);
        }

        cout << "La mediana es: " << calcularMediana(numeros, n) << endl;

    } while (funcionSeguir());

    return 0;
}