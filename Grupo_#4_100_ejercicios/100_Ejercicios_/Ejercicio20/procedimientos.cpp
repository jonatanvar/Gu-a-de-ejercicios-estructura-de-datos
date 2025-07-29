//
// Created by klain on 14/7/2025.
//
#include "Funciones.h" // Incluimos nuestro archivo de encabezado
#include <iostream>    // ¡IMPORTANTE! Aseguramos que iostream esté disponible para cout, cin, endl.

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA PARA INVERTIR UN ARREGLO" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "¿Desea invertir otro arreglo? (S/N): ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int &x) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(10000, '\n'); // Ignorar el resto de la línea incorrecta
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        } else if (x <= 0) {
            cout << "Error. El numero debe ser mayor que cero. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

void invertirArreglo(int arr[], int tamaño) {
    int inicio = 0;
    int fin = tamaño - 1;

    // Recorremos el arreglo intercambiando elementos desde los extremos hacia el centro
    while (inicio < fin) {
        // Intercambio de valores
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;
        inicio++;
        fin--;
    }
}

void imprimirArreglo(int arr[], int tamaño) {
    cout << "[";
    for (int i = 0; i < tamaño; ++i) {
        cout << arr[i];
        if (i < tamaño - 1) { // Para no poner coma después del último elemento
            cout << ", ";
        }
    }
    cout << "]" << endl;
}