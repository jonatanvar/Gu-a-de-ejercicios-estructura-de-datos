#include "cabecera.h"
#include <iostream> // Solo se incluye iostream
using namespace std;

int calcularLongitud(const char cadena[]) {
 int longitud = 0;
 while(cadena[longitud] != '\0') {
  longitud++;
 }
 return longitud;
}

void invertirCadena(char cadena[]) {
 int longitud = calcularLongitud(cadena);
 int inicio = 0;
 int fin = longitud - 1;
  while (inicio < fin) {
   char temp = cadena[inicio];
   cadena[inicio] = cadena[fin];
   cadena[fin] = temp;
   inicio++;
   fin--;
  }
}

bool obtenerCadena(char cadena[], int max_longitud) {
 cin.ignore(256, '\n');
 cout << "\nIngrese una cadena de texto (max " << max_longitud - 1 << " caracteres): ";
 cin.getline(cadena, max_longitud);

 if(cadena[0] == '\0') {
  cout << "Error: No ingreso ninguna cadena. Por favor, intente de nuevo.\n";
  return false;
 }
 return true;
}