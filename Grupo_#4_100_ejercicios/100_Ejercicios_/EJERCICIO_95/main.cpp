#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    char repetir;

    cout << "--- Calculadora de Rango Intercuartilico (RI) ---" << endl;
    cout << "¡Bienvenido! Este programa calculara el RI de un conjunto de numeros." << endl;

    do {
        int cantidad = leerCantidadNumeros();
        int* numeros = leerNumeros(cantidad);

        if (cantidad >= 4) {
            double ri = calcularRangoIntercuartilico(numeros, cantidad);
            cout << "\nEl Rango Intercuartilico (RI) es: " << ri << endl;
        } else {
            cout << "\nSe necesitan al menos 4 numeros para calcular el Rango Intercuartilico." << endl;
        }

        liberarMemoria(numeros);

        repetir = preguntarSiRepetir();
    } while (repetir == 's' || repetir == 'S');

    cout << "\n--- Fin del programa. ¡Hasta la proxima! ---" << endl;

    return 0;
}