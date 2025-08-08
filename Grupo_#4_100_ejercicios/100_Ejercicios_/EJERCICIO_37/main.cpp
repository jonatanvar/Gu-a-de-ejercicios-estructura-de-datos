#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int arreglo[MAX];
    int n, objetivo;

    cout << "Ingrese el tamanio del arreglo: ";
    cin >> n;

    leerArreglo(arreglo, n);

    cout << "Ingrese el numero que desea buscar: ";
    cin >> objetivo;

    int resultado = busquedaBinaria(arreglo, n, objetivo);

    if (resultado != -1) {
        cout << "El numero " << objetivo << " se encuentra en la posicion " << resultado << "." << endl;
    } else {
        cout << "El numero " << objetivo << " no se encuentra en el arreglo." << endl;
    }

    return 0;
}
