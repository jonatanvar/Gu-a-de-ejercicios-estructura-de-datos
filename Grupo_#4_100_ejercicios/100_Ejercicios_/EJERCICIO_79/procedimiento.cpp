#include <iostream>
#include "funciones.h"
using namespace std;

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->valor = valor;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return crearNodo(valor);
    }
    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else {
        raiz->derecha = insertar(raiz->derecha, valor);
    }
    return raiz;
}

void recorridoInorden(Nodo* raiz) {
    if (raiz != nullptr) {
        recorridoInorden(raiz->izquierda);
        cout << raiz->valor << " ";
        recorridoInorden(raiz->derecha);
    }
}
