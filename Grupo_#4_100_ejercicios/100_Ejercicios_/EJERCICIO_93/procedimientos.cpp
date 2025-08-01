// Autor: Jorge Mendoza
// Fecha: 22/07/2025.

#include "funciones.h"
#include <iostream>

using namespace std;

// Implementación de la función para obtener un número entero validado del usuario.
// Solicita al usuario un número y lo valida. Si la entrada es inválida, muestra un error y pide de nuevo.
long long validarEntradaNumerica(const char* mensaje) {
    long long numero; // Variable para almacenar el número ingresado.

    while (true) { // Bucle infinito hasta que se ingrese un número válido.
        cout << mensaje; // Muestra el mensaje proporcionado.
        cin >> numero;   // Intenta leer el número.

        // Verifica si la lectura falló (ej. se ingresó texto en lugar de números).
        if (cin.fail()) {
            cout << "Error: Por favor, ingresa un valor numerico valido.\n"; // Mensaje de error.
            cin.clear(); // Limpia el estado de error de 'cin'.
            cin.ignore(1000, '\n'); // Descarta caracteres restantes en el búfer de entrada.
        } else {
            cin.ignore(1000, '\n'); // Limpia el búfer después de una lectura exitosa.
            break; // Sale del bucle si la entrada es válida.
        }
    }
    return numero; // Retorna el número válido.
}

// Implementación de la función para encontrar el valor máximo en un arreglo.
// Recorre el arreglo para encontrar el elemento de mayor valor.
int encontrarMaximo(const int arr[], int tamano) {
    // Manejo de caso de arreglo vacío o tamaño inválido.
    if (tamano <= 0) {
        cout << "Error: El arreglo esta vacio o tiene un tamano invalido. No se puede encontrar el maximo.\n";
        return 0; // Se retorna 0 como valor indicativo de error (o se podría lanzar una excepción en un diseño más robusto).
    }

    int maximo = arr[0]; // Inicializa el máximo con el primer elemento del arreglo.

    // Itera desde el segundo elemento para comparar con el máximo actual.
    for (int i = 1; i < tamano; ++i) {
        if (arr[i] > maximo) {
            maximo = arr[i]; // Si encuentra un valor mayor, lo actualiza como el nuevo máximo.
        }
    }
    return maximo; // Retorna el valor máximo encontrado.
}

// Implementación de la función para encontrar el valor mínimo en un arreglo.
// Recorre el arreglo para encontrar el elemento de menor valor.
int encontrarMinimo(const int arr[], int tamano) {
    // Manejo de caso de arreglo vacío o tamaño inválido.
    if (tamano <= 0) {
        cout << "Error: El arreglo esta vacio o tiene un tamano invalido. No se puede encontrar el minimo.\n";
        return 0; // Se retorna 0 como valor indicativo de error.
    }

    int minimo = arr[0]; // Inicializa el mínimo con el primer elemento del arreglo.

    // Itera desde el segundo elemento para comparar con el mínimo actual.
    for (int i = 1; i < tamano; ++i) {
        if (arr[i] < minimo) {
            minimo = arr[i]; // Si encuentra un valor menor, lo actualiza como el nuevo mínimo.
        }
    }
    return minimo; // Retorna el valor mínimo encontrado.
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