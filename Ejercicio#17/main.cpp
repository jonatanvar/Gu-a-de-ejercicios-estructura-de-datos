//Nombre: Jonatan Varela
//Fecha: 20/06/2025
#include <iostream>
#include "cabecera.h"
using namespace std;

int main() {
    cout << "Bienvenido al programa para determinar el valor promedio de un arreglo\n";
    char continuar;
    do {
        int n;
        int arreglo[5];

        cout << "Ingrese el tamano del arreglo (maximo 5): ";
        cin >> n;

        if (n <= 0 || n > 5) {
            cout << "Tamano de arreglo invalido. Debe ser entre 1 y 5.\n";
            continue;
        }

        obtenerElementos(arreglo, n);

        float promedio = calcularPromedio(arreglo, n);

        cout << "El promedio de los valores en el arreglo es: " << promedio << endl;

        cout << "¿Deseas continuar? (s/n): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    cout << "Gracias por usar el programa. Adios! \n ";
    return 0;
}