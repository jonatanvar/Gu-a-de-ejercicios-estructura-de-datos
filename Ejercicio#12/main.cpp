#include <iostream>
#include "cabecera.h"
using namespace std;

int main() {
    float num1, num2, num3, mayor;
    cout << "Bienvenido al programa para determinar el numero mayor\n";
    char continuar;

    do {
        cout << "Ingrese el primer numero: ";
        cin >> num1;
        cout << "Ingrese el segundo numero: ";
        cin >> num2;
        cout << "Ingrese el tercer numero: ";
        cin >> num3;

        mayor = encontrarMayor(num1, num2, num3);

        cout << "El numero mayor es: " << mayor << endl;

        cout << "¿Deseas continuar? (s/n): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');

    cout << "Gracias por usar el programa. Adios! \n ";
    return 0;
}