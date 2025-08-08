#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

const int MAX_DIM = 3;

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void funcionvalidarDimension(int& dim);
void pedirDatosMatriz(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas);
void mostrarMatriz(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas);
void encontrarMenorPorColumna(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas);

#endif