#include "cabecera.h"
#include <iostream>
using namespace std;

void mostrarArreglo(int arr[], int tamano) {
 for (int i = 0; i < tamano; i++) {
  cout << arr[i] << " ";
 }
 cout << endl;
}

void ordenarInsercionDescendente(int arr[], int n) {
 for (int i = 1; i < n; i++) {
  int clave = arr[i];
  int j = i - 1;
  while (j >= 0 && arr[j] < clave) {
   arr[j+1] = arr[j];
   j--;
  }
  arr[j+1] = clave;
 }
}

int obtenerCantidadNumeros() {
 int n;
 do {
  cout << "\nIngrese la cantidad de numeros a ordenar: ";
  cin >> n;
  if (n <= 0) {
   cout << "Error: Debe ingresar un numero positivo.\n";
  }
 } while (n <= 0);
 return n;
}

void ingresarNumeros(int arr[], int n) {
 cout << "\nIngrese los " << n << " numeros (uno por uno):\n";
 for (int i = 0; i < n; i++) {
  cout << "Numero " << (i + 1) << ": ";
  cin >> arr[i];
 }
}