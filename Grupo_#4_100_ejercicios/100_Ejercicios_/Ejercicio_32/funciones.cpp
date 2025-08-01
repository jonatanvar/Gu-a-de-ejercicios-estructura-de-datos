//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación del algoritmo de ordenamiento de burbuja en orden descendente para un arreglo.

#include <iostream>  // Para operaciones de entrada/salida (cout, cin).
#include <limits>    // Para numeric_limits (validación de entrada).
#include <string>    // Para std::string.
#include <algorithm> // Para std::swap (intercambio de elementos).

// Se asume el uso de namespace std en funciones.cpp para simplificar.
using namespace std;

// --- Constante para el tamaño máximo del arreglo ---
const int MAX_TAMANO_ARREGLO = 10;

// --- Funciones Auxiliares Generales ---

// Función para obtener y validar un entero.
int obtenerEnteroValido(const char* prompt) {
    int valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, ingresa un numero entero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer después de una lectura exitosa.
            break;
        }
    }
    return valor;
}

// --- Funciones de Arreglo ---

// Función para inicializar el arreglo con valores ingresados por el usuario.
void inicializarArreglo(int arr[], int tamano) {
    cout << "Ingresa los " << tamano << " elementos del arreglo:\n";
    for (int i = 0; i < tamano; ++i) {
        arr[i] = obtenerEnteroValido(std::string("Elemento [" + to_string(i) + "]: ").c_str());
    }
    cout << "Arreglo inicializado.\n";
}

// Función para mostrar el arreglo.
void mostrarArreglo(const int arr[], int tamano) {
    cout << "\n--- Arreglo ---\n[";
    for (int i = 0; i < tamano; ++i) {
        cout << arr[i];
        if (i < tamano - 1) {
            cout << ", ";
        }
    }
    cout << "]\n---------------\n";
}

// Función que ordena un arreglo en orden descendente utilizando el algoritmo de burbuja.
void ordenarBurbujaDescendente(int arr[], int tamano) {
    bool intercambio_hecho; // Bandera para optimización: si no hay intercambios, ya está ordenado.
    for (int i = 0; i < tamano - 1; ++i) {
        intercambio_hecho = false;
        for (int j = 0; j < tamano - 1 - i; ++j) {
            // Para orden descendente: si el elemento actual es menor que el siguiente, se intercambian.
            if (arr[j] < arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                intercambio_hecho = true;
            }
        }
        // Si no se hizo ningún intercambio en esta pasada, el arreglo ya está ordenado.
        if (!intercambio_hecho) {
            break;
        }
    }
    cout << "Arreglo ordenado en forma descendente usando Burbuja.\n";
}

// --- Función Principal del Ejercicio ---

void resolverEjercicio32() {
    int arr[MAX_TAMANO_ARREGLO];
    int tamano_real;

    // Limpiar el buffer de entrada antes del primer menú.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "\n--- Ejercicio 32: Ordenar Arreglo Descendente (Burbuja) ---\n";

    // Pedir el tamaño real del arreglo.
    tamano_real = obtenerEnteroValido(std::string("Ingrese el numero de elementos para el arreglo (1 a " + to_string(MAX_TAMANO_ARREGLO) + "): ").c_str());
    while (tamano_real <= 0 || tamano_real > MAX_TAMANO_ARREGLO) {
        cout << "Numero de elementos invalido. ";
        tamano_real = obtenerEnteroValido(std::string("Ingrese el numero de elementos para el arreglo (1 a " + to_string(MAX_TAMANO_ARREGLO) + "): ").c_str());
    }

    // Inicializar y mostrar el arreglo original.
    inicializarArreglo(arr, tamano_real);
    cout << "\nArreglo Original:";
    mostrarArreglo(arr, tamano_real);

    // Ordenar el arreglo.
    ordenarBurbujaDescendente(arr, tamano_real);

    // Mostrar el arreglo ordenado.
    cout << "\nArreglo Ordenado Descendente:";
    mostrarArreglo(arr, tamano_real);

    cout << "--------------------------------------------------------\n";
}