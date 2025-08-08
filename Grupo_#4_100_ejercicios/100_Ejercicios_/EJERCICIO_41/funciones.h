#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

const int MAX_CADENA = 100;

void saludo();
bool funcionseguir();
char aMinuscula(char c);
bool esLetra(char c);
bool esVocal(char c);
int contarConsonantes(char cadena[]);
void mostrarResultadoConsonantes(char cadena[], int cantidadConsonantes);

#endif