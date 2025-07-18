//
// Created by klain on 17/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

int main() {
    int numLanzamientos;
    int frecuencias[6] = {0}; // Inicializamos todas las frecuencias en 0

    saludo();

    do {
        // Reiniciar frecuencias para cada nueva simulación
        for (int i = 0; i < 6; ++i) {
            frecuencias[i] = 0;
        }

        cout << "Ingrese el numero de lanzamientos de dado a simular: ";
        funcionvalidar(numLanzamientos);

        simularLanzamientos(numLanzamientos, frecuencias);
        mostrarFrecuencias(frecuencias);

    } while (funcionSeguir());

    return 0;
}