#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de notas: ";
    cin >> cantidad;

    float notas[100];
    leerNotas(notas, cantidad);

    float promedio = calcularPromedio(notas, cantidad);
    cout << "El promedio del estudiante es: " << promedio << endl;

    return 0;
}
