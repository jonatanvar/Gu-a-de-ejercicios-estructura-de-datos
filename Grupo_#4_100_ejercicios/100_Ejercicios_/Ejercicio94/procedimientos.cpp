//
// Created by klain on 17/7/2025.
//
#include <iostream>
#include <cmath> // Necesario para redondear en la funcion de cuartiles (floor)
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA CALCULAR CUARTILES" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea calcular los cuartiles de otro conjunto de numeros? S o N: ";
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
    // Asumimos que el arreglo ya esta ordenado al llamar esta funcion desde calcularCuartil
    // Si no, se llamaria bubbleSort(arr, n) aqui.
    if (n % 2 == 0) {
        return (static_cast<double>(arr[n/2 - 1]) + arr[n/2]) / 2.0;
    } else {
        return static_cast<double>(arr[n/2]);
    }
}

double calcularCuartil(int arr[], int n, int cuartil) {
    bubbleSort(arr, n); // Aseguramos que el arreglo este ordenado

    if (cuartil == 2) {
        return calcularMediana(arr, n); // Q2 es la mediana
    }

    double pos = static_cast<double>(cuartil * (n + 1)) / 4.0;
    int k = static_cast<int>(floor(pos));
    double d = pos - k;

    if (k < 1) { // Para Q1 si n es muy pequeño
        return static_cast<double>(arr[0]);
    } else if (k >= n) { // Para Q3 si n es muy pequeño
        return static_cast<double>(arr[n-1]);
    } else {
        return arr[k-1] + d * (arr[k] - arr[k-1]);
    }
}