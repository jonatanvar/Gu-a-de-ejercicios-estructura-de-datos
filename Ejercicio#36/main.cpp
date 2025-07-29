//Nombre: Jonatan Varela
//Fecha: 30/06/2025
#include <iostream>
#include "cabecera.h"
using namespace std;

int main() {
 cout << "=== Bienvenido al programa de ordenamiento por insercion ===";
 char continuar;

 do {
  int n = obtenerCantidadNumeros();

  int* arr = new int[n]; // Asignacion dinamica de memoria

  ingresarNumeros(arr, n);

  cout << "\nArreglo original: ";
  mostrarArreglo(arr, n);

  ordenarInsercionDescendente(arr, n);

  cout << "Arreglo ordenado descendente: ";
  mostrarArreglo(arr, n);

  cout << "¿Desea continuar? (s/n): ";
  cin >> continuar;

  delete[] arr; // Liberar memoria asignada dinamicamente

 } while (continuar == 'S' || continuar == 's');

 cout << "Gracias por usar el programa. Adios!\n";
 return 0;
}