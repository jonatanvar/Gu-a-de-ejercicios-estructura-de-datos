//
// Created by Admin on 7/21/2025.
//
// procedimientos.cpp
#include "funciones.h" // Incluye las declaraciones de funciones

#include <iostream>
using namespace std;

// Constante para el valor de PI.
constexpr double PI = 3.1416;

// Implementación de la función para calcular el perímetro de un círculo.
// Recibe el radio y aplica la fórmula P = 2 * PI * radio.
double calcularPerimetroCirculo(double radio) {
    return 2 * PI * radio;
}

// Implementación de la función para preguntar si el usuario desea repetir el programa.
// Contiene un bucle de validación para asegurar una entrada correcta (1 o 2).
int preguntarRepetir() {
    int repetir; // Opción del usuario: 1 para sí, 2 para no.

    while (true) {
        cout << "\nQuieres repetir el programa?";
        cout << "\n1. Si";
        cout << "\n2. No";
        cout << "\nSelecciona una opcion (1-2): ";
        cin >> repetir; // Intenta leer la entrada del usuario.

        // Bloque de validación de entrada.
        if (cin.fail() || repetir < 1 || repetir > 2) {
            cout << "Error: Ingresa 1 o 2\n"; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de cin.
            cin.ignore(1000, '\n'); // Descarta caracteres restantes en el búfer.
        } else {
            cin.ignore(1000, '\n'); // Limpia el búfer después de una lectura válida.
            break; // Sale del bucle de validación.
        }
    }
    return repetir; // Retorna la opción válida.
}