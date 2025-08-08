//Nombre: Cristina Cruz
//Fecha: 15 jul 2025

#include <iostream>

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

int calcularModa(int* arr, int cantidad) {
    if (cantidad == 0) {
        return 0;
    }

    int moda = arr[0];
    int maxFrecuencia = 0;

    for (int i = 0; i < cantidad; ++i) {
        int frecuenciaActual = 0;
        for (int j = 0; j < cantidad; ++j) {
            if (arr[j] == arr[i]) {
                frecuenciaActual++;
            }
        }
        if (frecuenciaActual > maxFrecuencia) {
            maxFrecuencia = frecuenciaActual;
            moda = arr[i];
        }
    }
    return moda;
}
void liberarMemoria(int* arr) {
    delete[] arr;
    arr = NULL;
}
char preguntarSiRepetir() {
    char opcion;
    cout << "\nDesea calcular la moda de otro conjunto de datos? (s/n): ";
    cin >> opcion;
    return opcion;
}
int main() {
    char repetir;
    cout << "--- Calculadora de Moda ---" << endl;
    cout << "¡Bienvenido! Este programa calculara la moda de un conjunto de numeros." << endl;

    do {
        int cantidad = leerCantidadNumeros();
        int* numeros = leerNumeros(cantidad);

        if (cantidad > 0) {
            int moda = calcularModa(numeros, cantidad);
            cout << "\nLa moda del conjunto de datos es: " << moda << endl;
        } else {
            cout << "\nNo se ingresaron numeros para calcular la moda." << endl;
        }
        liberarMemoria(numeros);

        repetir = preguntarSiRepetir();
    } while (repetir == 's' || repetir == 'S');

    cout << "\n--- Fin del programa. ¡Hasta la proxima! ---" << endl;

    return 0;
}
