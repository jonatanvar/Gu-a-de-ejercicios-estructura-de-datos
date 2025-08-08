//
// Created by Admin on 7/17/2025.
//
#ifndef FUNCIONES_H
#define FUNCIONES_H


struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
};

Nodo* insertarNodo(Nodo* raiz, int valor);

bool buscarNodo(Nodo* raiz, int valorBuscado);

int validarEntradaNumericaInt(const char* mensaje);

int preguntarRepetir();

#endif // FUNCIONES_H