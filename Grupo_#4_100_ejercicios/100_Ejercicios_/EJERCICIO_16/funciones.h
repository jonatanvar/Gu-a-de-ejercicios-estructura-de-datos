#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

void saludo();
bool funcionseguir();
void funcionvalidar(int& x); // Para validar cualquier numero entero
void funcionvalidarPositivo(int& x); // Para validar un numero entero positivo
int obtenerTamanoArreglo(const char* mensaje);
void leerElementosArreglo(int arreglo[], int tamano);
int sumarElementosArreglo(int arreglo[], int tamano);
void mostrarResultadoSuma(int suma);

#endif