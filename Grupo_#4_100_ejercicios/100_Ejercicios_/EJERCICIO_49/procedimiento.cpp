#include <iostream>
#include "funciones.h"
using namespace std;

void leerNotas(float notas[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese la nota [" << i << "]: ";
        cin >> notas[i];
    }
}

float calcularPromedio(float notas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return suma / cantidad;
}
