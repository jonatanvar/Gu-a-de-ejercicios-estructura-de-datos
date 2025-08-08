#include <iostream>
#include "funciones.h"

using namespace std;

void push(int pila[], int& tope, int elemento) {
    if (tope >= MAX - 1) {
        cout << "La pila está llena." << endl;
        return;
    }
    pila[++tope] = elemento;
    cout << "Elemento " << elemento << " agregado a la pila." << endl;
}

void pop(int pila[], int& tope) {
    if (tope < 0) {
        cout << "La pila está vacía." << endl;
        return;
    }
    cout << "Elemento " << pila[tope--] << " eliminado de la pila." << endl;
}

void mostrarPila(int pila[], int tope) {
    if (tope < 0) {
        cout << "La pila está vacía." << endl;
        return;
    }
    cout << "Contenido de la pila (de arriba hacia abajo):" << endl;
    for (int i = tope; i >= 0; --i) {
        cout << pila[i] << endl;
    }
}
