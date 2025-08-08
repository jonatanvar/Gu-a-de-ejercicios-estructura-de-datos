#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

using namespace std;

// Definimos un tamano fijo para las matrices
const int MAX_DIM = 3;

void saludo();
bool funcionseguir();
void funcionvalidar(int& num);
void funcionvalidarDimension(int& dim);
void pedirDatosMatriz(int matriz[MAX_DIM][MAX_DIM], int filas, int columnas, int numeroMatriz);
void sumarYMostrarMatrices(int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int filas, int columnas);

#endif