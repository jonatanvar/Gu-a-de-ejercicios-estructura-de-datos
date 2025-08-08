#include <iostream>
#include "Funciones.h"

using namespace std;

Nodo* insertarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return new Nodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izq = insertarNodo(raiz->izq, valor);
    }
    else {
        raiz->der = insertarNodo(raiz->der, valor);
    }

    return raiz;
}

void mostrarInOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarInOrden(raiz->izq);
        cout << raiz->dato << " ";
        mostrarInOrden(raiz->der);
    }
}

int leerNumeroParaInsertar() {
    int num;
    cout << "Ingresa un numero entero para insertar (0 para terminar): ";
    cin >> num;
    return num;
}