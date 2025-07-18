//
// Created by klain on 17/7/2025.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>

using namespace std;

void saludo();
bool funcionSeguir();
void funcionvalidar(int &x);
void bubbleSort(int arr[], int n);
double calcularMediana(int arr[], int n); // Reutilizamos esta para Q2
double calcularCuartil(int arr[], int n, int cuartil);

#endif //FUNCIONES_H
