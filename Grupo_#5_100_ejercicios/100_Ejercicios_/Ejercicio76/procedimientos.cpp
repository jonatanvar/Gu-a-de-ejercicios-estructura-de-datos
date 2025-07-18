//
// Created by klain on 17/7/2025.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

void saludo() {
    cout << "BIENVENIDO AL PROGRAMA DE ARBOLES BINARIOS" << endl;
}

bool funcionSeguir() {
    char opcion;
    cout << endl;
    cout << "Desea realizar otra operacion con el arbol? S o N: ";
    cin >> opcion;
    cout << endl;
    return (opcion == 's' || opcion == 'S');
}

void funcionvalidar(int &x) {
    bool entradaValida;

    do {
        entradaValida = true;
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error. Solo se permiten numeros. Intente nuevamente: ";
            entradaValida = false;
        }
    } while (!entradaValida);
}

NodoArbol* crearNodo(int dato) {
    NodoArbol *nuevo_nodo = new NodoArbol();
    nuevo_nodo->dato = dato;
    nuevo_nodo->izquierda = nullptr;
    nuevo_nodo->derecha = nullptr;
    return nuevo_nodo;
}

void insertar(NodoArbol *&arbol, int dato) {
    if (arbol == nullptr) {
        arbol = crearNodo(dato);
    } else if (dato < arbol->dato) {
        insertar(arbol->izquierda, dato);
    } else {
        insertar(arbol->derecha, dato);
    }
}

void preOrden(NodoArbol *arbol) {
    if (arbol == nullptr) {
        return;
    }
    cout << arbol->dato << " ";
    preOrden(arbol->izquierda);
    preOrden(arbol->derecha);
}

void inOrden(NodoArbol *arbol) {
    if (arbol == nullptr) {
        return;
    }
    inOrden(arbol->izquierda);
    cout << arbol->dato << " ";
    inOrden(arbol->derecha);
}

void postOrden(NodoArbol *arbol) {
    if (arbol == nullptr) {
        return;
    }
    postOrden(arbol->izquierda);
    postOrden(arbol->derecha);
    cout << arbol->dato << " ";
}