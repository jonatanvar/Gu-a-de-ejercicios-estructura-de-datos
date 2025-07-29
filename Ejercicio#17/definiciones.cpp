#include "cabecera.h"
#include <iostream>

void obtenerElementos(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Ingrese el valor " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

float calcularSuma(int arr[], int size) {
    float suma = 0.0f;
    for (int i = 0; i < size; i++) {
        suma += arr[i];
    }
    return suma;
}

float calcularPromedio(int arr[], int size) {
    if (size <= 0) return 0.0f;
    float suma = calcularSuma(arr, size);
    return suma / size;
}