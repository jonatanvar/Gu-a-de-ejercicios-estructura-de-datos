//Nombre: Jonatan Varela
//Fecha: 22/06/2025
#include <iostream>
#include "cabecera.h"
using namespace std;

int main() {
    cout << "Bienvenido al programa de contar cuantas veces aparece el valor en el arreglo\n";
    char continuar;
    do {
        int n;
        int arreglo[5];
        int valor;
        int contador;

        cout << "Ingrese el tamano del arreglo (maximo 5): ";
        cin >> n;

        if (n <= 0 || n > 5) {
            cout << "Tamano de arreglo invalido. Debe ser entre 1 y 5.\n";
            continue;
        }

        obtenerElementos(arreglo, n);

        valor = obtenerValorABuscar();

        contador = contarOcurrencias(arreglo, n, valor);

        cout << "El valor: " << valor << " aparece: " << contador
             << " veces en el arreglo.\n";

        cout << "¿Deseas continuar? (s/n): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    cout << "Gracias por usar el programa. Adios! \n ";
    return 0;
}