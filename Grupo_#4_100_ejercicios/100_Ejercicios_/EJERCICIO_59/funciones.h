#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

struct Fraccion {
    int numerador;
    int denominador;
};

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void funcionvalidarDenominador(int& den);
void leerFraccion(Fraccion& f, const char* nombre);
Fraccion multiplicarFracciones(const Fraccion& f1, const Fraccion& f2);
void mostrarFraccion(const Fraccion& f);

#endif