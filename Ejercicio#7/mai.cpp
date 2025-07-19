#include <iostream>
#include "cabecera.h"

using namespace std;

int main() {
    cout << "Bienvenido al programa de celsius a fahrenheit \n";
    char continuar;
    do {
        double celsius, fahrenheit;
        cout << "Ingrese la cantidad de grados Celsius: ";
        cin >> celsius;
        fahrenheit = celsius_a_fahrenheit(celsius);
        cout << celsius << "°C es igual a: " << fahrenheit << "°F\n";
        cout << "¿Deseas continuar? (s/n): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');
    cout << "Gracias por usar el programa. Adiós! \n";
    return 0;
}