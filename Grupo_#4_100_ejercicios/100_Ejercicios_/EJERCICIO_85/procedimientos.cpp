//
// Created by Admin on 7/17/2025.
//
#include "funciones.h"
#include <iostream>

using namespace std;


Nodo* insertarNodo(Nodo* raiz, int valor) {

    if (raiz == nullptr) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->valor = valor;
        nuevoNodo->izquierda = nullptr;
        nuevoNodo->derecha = nullptr;
        return nuevoNodo; // Retorna el puntero al nuevo nodo.
    }

    // Si el valor a insertar es menor que el valor del nodo actual, se inserta en el subárbol izquierdo.
    if (valor < raiz->valor) {
        raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    }
    // Si el valor a insertar es mayor que el valor del nodo actual, se inserta en el subárbol derecho.
    else if (valor > raiz->valor) { // 'else if' para manejar valores únicos; si se permiten duplicados, se manejaría diferente.
        raiz->derecha = insertarNodo(raiz->derecha, valor);
    }

    return raiz; // Retorna la raíz del subárbol actual.
}


bool buscarNodo(Nodo* raiz, int valorBuscado) {

    if (raiz == nullptr) {
        return false;
    }


    if (raiz->valor == valorBuscado) {
        return true;
    }


    if (valorBuscado < raiz->valor) {
        return buscarNodo(raiz->izquierda, valorBuscado);
    }

    else {
        return buscarNodo(raiz->derecha, valorBuscado);
    }
}


int validarEntradaNumericaInt(const char* mensaje) {
    int numero;

    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero valido." << endl; // Mensaje de error.
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return numero;
}


int preguntarRepetir() {
    int repetir;

    while (true) {
        cout << "\nQuieres repetir el programa?";
        cout << "\n1. Si";
        cout << "\n2. No";
        cout << "\nSelecciona una opcion (1-2): ";
        cin >> repetir;


        if (cin.fail()) {
            cout << "Error: Por favor, ingresa un valor numerico valido.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (repetir < 1 || repetir > 2) {
            cout << "Error: Ingresa 1 o 2\n";
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    return repetir;
}