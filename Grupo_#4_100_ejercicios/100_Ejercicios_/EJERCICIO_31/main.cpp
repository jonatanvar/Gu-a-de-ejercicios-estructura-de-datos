#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    int arreglo[100];
    leerArreglo(arreglo, n);

    ordenarBurbuja(arreglo, n);

    cout << "Arreglo ordenado ascendentemente:" << endl;
    mostrarArreglo(arreglo, n);

    return 0;
}
