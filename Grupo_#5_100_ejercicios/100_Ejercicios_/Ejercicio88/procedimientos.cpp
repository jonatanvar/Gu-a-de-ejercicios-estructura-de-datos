//
// Created by klain on 17/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA CALCULAR LA MEDIANA" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea calcular la mediana de otro conjunto de numeros? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int &x) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        } else if (x <= 0) {
            cout << "Error. El numero debe ser mayor que cero. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

double calcularMediana(int arr[], int n) {
    bubbleSort(arr, n);

    if (n % 2 == 0) {
        // Si el número de elementos es par
        return (static_cast<double>(arr[n/2 - 1]) + arr[n/2]) / 2.0;
    } else {
        // Si el número de elementos es impar
        return static_cast<double>(arr[n/2]);
    }
}