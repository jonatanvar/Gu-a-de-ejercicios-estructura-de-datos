//
// Created by klain on 16/7/2025.
//

// Pila.h
#ifndef PILA_H // <-- Asegúrate que NO haya '##' aquí
#define PILA_H

const int MAX_ELEMENTOS = 10; // Definimos un tamaño máximo para la pila

struct Pila {
    int elementos[MAX_ELEMENTOS];
    int cima; // Índice del último elemento o -1 si está vacía
};

void inicializarPila(Pila &p);
bool estaVacia(Pila &p);
bool estaLlena(Pila &p);
void meter(Pila &p, int valor); // PUSH
int sacar(Pila &p);             // POP
int verCima(Pila &p);           // PEEK

#endif // PILA_H