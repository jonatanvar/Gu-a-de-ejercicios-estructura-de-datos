//
// Created by klain on 16/7/2025.
//
// PilaProcedimientos.cpp
#include <iostream>
#include "Pila.h" // Asegúrate de que Pila.h sea correcto
using namespace std;

void inicializarPila(Pila &p) {
    p.cima = -1; // Una pila vacía tiene la cima en -1
}

bool estaVacia(Pila &p) {
    return p.cima == -1;
}

bool estaLlena(Pila &p) {
    return p.cima == MAX_ELEMENTOS - 1; // MAX_ELEMENTOS es visible por la inclusión de Pila.h
}

void meter(Pila &p, int valor) {
    if (estaLlena(p)) {
        cout << "Error: La pila esta llena. No se puede meter mas elementos." << endl;
    } else {
        p.cima++;
        p.elementos[p.cima] = valor;
        cout << "Elemento " << valor << " metido en la pila." << endl;
    }
}

int sacar(Pila &p) {
    if (estaVacia(p)) {
        cout << "Error: La pila esta vacia. No se puede sacar elementos." << endl;
        return -1; // Retornamos un valor sentinel, -1 o un valor que indique error
    } else {
        int valorSacado = p.elementos[p.cima];
        p.cima--;
        cout << "Elemento " << valorSacado << " sacado de la pila." << endl;
        return valorSacado;
    }
}

int verCima(Pila &p) {
    if (estaVacia(p)) {
        cout << "Error: La pila esta vacia. No hay elemento en la cima." << endl;
        return -1; // Valor sentinel
    } else {
        return p.elementos[p.cima];
    }
}