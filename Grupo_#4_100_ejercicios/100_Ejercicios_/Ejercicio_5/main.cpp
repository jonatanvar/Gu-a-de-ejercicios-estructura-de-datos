//Nombre: Erinson Alvarez
//Fecha: 15/07/2025
//Descripción: Programa que calcula el área de un triángulo usando base y altura

#include <iostream>
using namespace std;

int main() {
    cout << "Bienvenido al programa Ejercicio 5 - Área de un triángulo\n";
    char continuar;
    
    do {
        float base, altura;
        
        cout << "Ingrese la base del triángulo: ";
        while (!(cin >> base) || base <= 0) {
            cout << "Error: Ingrese un valor numérico positivo para la base: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
        cout << "Ingrese la altura del triángulo: ";
        while (!(cin >> altura) || altura <= 0) {
            cout << "Error: Ingrese un valor numérico positivo para la altura: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
        float area = (base * altura) / 2;
        
        cout << "Base: " << base << "\n";
        cout << "Altura: " << altura << "\n";
        cout << "El área del triángulo es: " << area << "\n";
        
        cout << "¿Deseas continuar? (s/n): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');
    
    cout << "Gracias por usar el programa. Adiós! \n";
    return 0;
}