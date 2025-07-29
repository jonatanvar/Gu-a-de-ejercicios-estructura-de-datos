//
// Created by klain on 14/7/2025.
//
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>

// Declaraciones de funciones
void saludo(); // Muestra un mensaje de bienvenida
bool funcionSeguir(); // Pregunta si el usuario desea continuar
void funcionvalidarDimension(int &x, int &y); // Valida la entrada de las dimensiones de la matriz
void funcionvalidarElemento(int &x); // Valida la entrada de los elementos de la matriz

// Funciones para manejar matrices dinámicas
int** crearMatriz(int filas, int columnas); // Crea una matriz dinámicamente
void eliminarMatriz(int** matriz, int filas); // Libera la memoria de una matriz

// Función para pedir los elementos de una matriz
void pedirElementosMatriz(int** matriz, int filas, int columnas);

// Función para imprimir una matriz
void imprimirMatriz(int** matriz, int filas, int columnas);

// Función para multiplicar dos matrices
int** multiplicarMatrices(int** matrizA, int** matrizB,
                          int filasA, int columnasA, int filasB, int columnasB);

#endif // FUNCIONES_H