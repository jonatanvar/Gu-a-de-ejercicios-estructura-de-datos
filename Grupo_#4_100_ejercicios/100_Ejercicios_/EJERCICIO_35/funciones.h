#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream> // Necesario para usar cout, cin
#include <cstddef>  // Para asegurar que NULL este definido

using namespace std;

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void funcionvalidarTamano(int& tam);
void leerArreglo(int* arr, int tamano);
void mostrarArreglo(int* arr, int tamano);
void ordenarPorInsercion(int* arr, int tamano);

#endif