// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>
using namespace std;

int main() {
    double arreglo[TamanioArreglo];
    int repetirPrograma;

    cout << "Bienvenido al programa de Ordenamiento por Seleccion en forma Ascendente. :)\n";

    do {
        cout << "--- Ingrese los " << TamanioArreglo << " elementos del arreglo ---\n";

        for (int i = 0; i < TamanioArreglo; ++i) {
            cout << "Ingrese el elemento " << (i + 1) << ": ";
            arreglo[i] = validarEntradaNumerica("");
        }

        cout << "\n--- Arreglo Original ---\n";
        imprimirArreglo(arreglo, TamanioArreglo);

        ordenarAscendentePorSeleccion(arreglo, TamanioArreglo);

        cout << "\n--- Arreglo Ordenado (Ascendente por Seleccion) ---" << endl;
        imprimirArreglo(arreglo, TamanioArreglo);

        repetirPrograma = preguntarRepetir();

    } while (repetirPrograma == 1);
    cout << "\nGracias por usar el programa. :)\n";
    return 0;
}