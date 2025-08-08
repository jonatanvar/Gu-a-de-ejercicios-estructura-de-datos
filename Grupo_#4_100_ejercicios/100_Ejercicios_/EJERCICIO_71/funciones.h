#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

struct Cola {
    int* elementos;
    int capacidad;
    int cantidad;
};

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void inicializarCola(Cola& c, int cap);
void liberarCola(Cola& c);
void encolar(Cola& c, int valor);
void desencolar(Cola& c);
bool estaColaVacia(const Cola& c);

#endif