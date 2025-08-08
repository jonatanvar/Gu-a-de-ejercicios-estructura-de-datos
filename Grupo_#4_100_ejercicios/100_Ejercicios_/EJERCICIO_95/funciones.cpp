#include <iostream>
#include "Funciones.h"

using namespace std;

int leerCantidadNumeros() {
    int cantidad;
    cout << "Ingrese la cantidad de numeros a introducir: ";
    cin >> cantidad;
    while (cantidad <= 0) {
        cout << "La cantidad debe ser mayor a 0. Ingrese de nuevo: ";
        cin >> cantidad;
    }
    return cantidad;
}

int* leerNumeros(int cantidad) {
    int* arr = new int[cantidad];
    cout << "Ingrese los " << cantidad << " numeros:" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }
    return arr;
}

void ordenarArray(int* arr, int cantidad) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double calcularMediana(int* arr, int inicio, int fin) {
    int subCantidad = fin - inicio + 1;
    if (subCantidad <= 0) {
        return 0.0;
    }

    if (subCantidad % 2 == 1) {
        return static_cast<double>(arr[inicio + subCantidad / 2]);
    } else {
        int mid1 = arr[inicio + subCantidad / 2 - 1];
        int mid2 = arr[inicio + subCantidad / 2];
        return static_cast<double>(mid1 + mid2) / 2.0;
    }
}

double calcularQ1(int* arr, int cantidad) {
    if (cantidad == 0) return 0.0;
    int mitad = cantidad / 2;
    return calcularMediana(arr, 0, mitad - 1);
}

double calcularQ3(int* arr, int cantidad) {
    if (cantidad == 0) return 0.0;
    int mitad = cantidad / 2;
    int inicioQ3 = (cantidad % 2 == 0) ? mitad : mitad + 1;
    return calcularMediana(arr, inicioQ3, cantidad - 1);
}

double calcularRangoIntercuartilico(int* arr, int cantidad) {
    if (cantidad < 4) {
        return 0.0;
    }
    ordenarArray(arr, cantidad);
    double q1 = calcularQ1(arr, cantidad);
    double q3 = calcularQ3(arr, cantidad);
    return q3 - q1;
}

void liberarMemoria(int* arr) {
    delete[] arr;
    arr = NULL;
}

char preguntarSiRepetir() {
    char opcion;
    cout << "\nDesea calcular el Rango Intercuartilico de otro conjunto de datos? (s/n): ";
    cin >> opcion;
    return opcion;
}