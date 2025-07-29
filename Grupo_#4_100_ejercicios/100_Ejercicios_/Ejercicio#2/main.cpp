//Nombre: Jonatan Varela
//Fecha: 16/06/2025
#include <iostream>
using namespace std;

int main() {
  float num1, num2, resultado;

  cout << "Bienvenido al programa de resta de dos números\n";
  char continuar;
  do {
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    resultado = num1 - num2;
    cout << "El resultado de la resta es: " << num1 << " - " << num2 << " es: " << resultado << endl;

    cout << "¿Deseas continuar? (s/n): ";
    cin >> continuar;
  } while (continuar == 'S' || continuar == 'S');
  return 0;
}