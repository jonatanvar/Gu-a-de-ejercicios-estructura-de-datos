//
// Created by klain on 14/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA ORDENAR UN ARREGLO DE FORMA DESCENDENTE (SELECCION)" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea ordenar otro arreglo? S o N: ";
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
        } else if (x <= 0 || x > 100) {
            cout << "Error. El numero debe ser mayor que cero y menor o igual a 100. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

void leerArreglo(int arr[], int n) {
    cout << "Ingrese los elementos del arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i + 1 << ": ";
        funcionvalidar(arr[i]);
    }
}

void ordenarDescendenteSeleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        int temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

void imprimirArreglo(int arr[], int n) {
    cout << "Arreglo ordenado descendente: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}