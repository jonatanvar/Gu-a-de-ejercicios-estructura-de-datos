#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

struct Pila {
    int* elementos;
    int capacidad;
    int cantidad;
};

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void inicializarPila(Pila& p, int cap);
void liberarPila(Pila& p);
bool push(Pila& p, int valor);
bool estaPilaLlena(const Pila& p);

#endif