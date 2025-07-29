//Nombre: Jonatan Varela
//Fecha: 1/07/2025
#include <iostream> 
#include "cabecera.h"
using namespace std;

int main() {
 cout << "=== Bienvenido al programa de inversion de cadenas ===";
 char continuar;

 do {
  char entrada[MAX_CADENA] = {0}; 

  if (!obtenerCadena(entrada, MAX_CADENA)) {
   continue;
  }

  cout << "Cadena original: " << entrada << endl;
  invertirCadena(entrada);
  cout << "Cadena invertida: " << entrada << endl;

  cout << "¿Deseas ingresar una nueva cadena de texto? (s/n): ";
  cin >> continuar;

 } while (continuar == 's' || continuar == 'S');

 cout << "Gracias por usar el programa. Adios!\n";
 return 0;
 
}