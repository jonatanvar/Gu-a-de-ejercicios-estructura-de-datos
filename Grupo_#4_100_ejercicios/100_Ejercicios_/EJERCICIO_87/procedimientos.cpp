// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Implementación de la función para calcular la media (promedio) de un conjunto de datos.
// Suma todos los elementos del arreglo y divide por la cantidad total de elementos.
double calcularMedia(const double datos[], int cantidad) {
    if (cantidad <= 0) { // Si no hay datos o la cantidad es inválida, la media es 0.
        return 0.0;
    }

    double suma = 0.0; // Inicializa la suma de los elementos.
    for (int i = 0; i < cantidad; ++i) {
        suma += datos[i]; // Acumula cada elemento en la suma.
    }

    return suma / cantidad; // Retorna la suma dividida por la cantidad de elementos.
}

// Implementación de la función para validar y leer una entrada numérica entera.
// Solicita al usuario un número entero y lo valida.
int validarEntradaNumericaInt(const char* mensaje) {
    int numero; // Variable para almacenar el número ingresado.

    while (true) { // Bucle infinito hasta que se ingrese un número válido.
        cout << mensaje; // Muestra el mensaje proporcionado.
        cin >> numero;   // Intenta leer el número entero.

        // Verifica si la lectura falló (ej. se ingresó texto en lugar de números).
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero valido." << endl; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de 'cin'.
            cin.ignore(1000, '\n'); // Descarta caracteres restantes en el búfer de entrada.
        } else {
            cin.ignore(1000, '\n'); // Limpia el búfer después de una lectura exitosa.
            break; // Sale del bucle si la entrada es válida.
        }
    }
    return numero; // Retorna el número válido.
}

// Implementación de la función para validar y leer una entrada numérica de punto flotante.
// Solicita al usuario un número decimal y lo valida.
double validarEntradaNumericaDouble(const char* mensaje) {
    double numero; // Variable para almacenar el número ingresado.

    while (true) { // Bucle infinito hasta que se ingrese un número válido.
        cout << mensaje; // Muestra el mensaje proporcionado.
        cin >> numero;   // Intenta leer el número decimal.

        // Verifica si la lectura falló (ej. se ingresó texto en lugar de números).
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero decimal valido." << endl; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de 'cin'.
            cin.ignore(1000, '\n'); // Descarta caracteres restantes en el búfer de entrada.
        } else {
            cin.ignore(1000, '\n'); // Limpia el búfer después de una lectura exitosa.
            break; // Sale del bucle si la entrada es válida.
        }
    }
    return numero; // Retorna el número válido.
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

        // Valida si la entrada es un número y está en el rango [1, 2].
        if (cin.fail()) {
            cout << "Error: Por favor, ingresa un valor numerico valido.\n"; // Mensaje de error.
            cin.clear(); // Limpia el estado de error del flujo de entrada.
            cin.ignore(1000, '\n'); // Descarta caracteres restantes en el búfer.
        } else if (repetir < 1 || repetir > 2) { // Validación de rango después de la validación numérica.
            cout << "Error: Ingresa 1 o 2\n";
        } else {
            cin.ignore(1000, '\n'); // Limpia el búfer después de una lectura válida.
            break; // Sale del bucle de validación.
        }
    }
    return repetir; // Retorna la opción válida.
}