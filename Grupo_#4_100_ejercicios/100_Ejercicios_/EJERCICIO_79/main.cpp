#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    Nodo* raiz = nullptr;
    int cantidad, valor;

    cout << "Ingrese la cantidad de nodos: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese valor del nodo [" << i << "]: ";
        cin >> valor;
        raiz = insertar(raiz, valor);
    }

    cout << "Recorrido inorden del Arbol:" << endl;
    recorridoInorden(raiz);
    cout << endl;

    return 0;
}
