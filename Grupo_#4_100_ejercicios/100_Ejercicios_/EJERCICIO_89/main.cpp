#include <iostream>
#include "Funciones.h"

using namespace std;

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