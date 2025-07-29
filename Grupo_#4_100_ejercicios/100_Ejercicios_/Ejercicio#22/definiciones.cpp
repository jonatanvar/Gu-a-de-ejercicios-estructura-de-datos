#include "cabecera.h"
#include <iostream>
using namespace std;

void obtenerElementos(int arr[], int size) {
    cout << "Ingrese el valor " << i + 1 << ": ";
    cin >> arr[i];
    for (int i = 0; i < size; i++) {
    }
}

int obtenerValorABuscar() {
    int valor;
    cout << "Ingrese el valor a buscar: ";
    cin >> valor;
    return valor;
}

int contarOcurrencias(int arr[], int size, int valor_buscar) {
    int contador = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == valor_buscar) {
            contador++;
        }
    }
    return contador;
}