//Nombre: [Erinson Alvarez]
//Fecha: 19/07/2024
//Descripción: Implementación de funciones para sumar los elementos de una fila específica en una matriz.

#include <iostream> // Para operaciones de entrada/salida (cout, cin).
#include <limits>   // Para numeric_limits (validación de entrada).
#include <string>   // Para std::string.
#include <iomanip>  // Para setw (formato de salida de matriz).

// Se asume el uso de namespace std en funciones.cpp para simplificar.
using namespace std;

// --- Constantes para las dimensiones máximas de la matriz ---
const int MAX_FILAS = 5;
const int MAX_COLUMNAS = 5;

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

// --- Funciones de Matriz ---

// Función para inicializar la matriz con valores secuenciales.
void inicializarMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas) {
    int contador = 1;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = contador++;
        }
    }
    cout << "Matriz inicializada con valores secuenciales.\n";
}

// Función para mostrar la matriz.
void mostrarMatriz(const int matriz[][MAX_COLUMNAS], int filas, int columnas) {
    cout << "\n--- Matriz Actual ---\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << setw(4) << matriz[i][j]; // setw para formatear la salida y alinear.
        }
        cout << "\n";
    }
    cout << "---------------------\n";
}

// Función que suma los elementos de una fila específica de la matriz.
int sumarFilaEspecifica(const int matriz[][MAX_COLUMNAS], int filas, int columnas, int fila_a_sumar) {
    // Validar que el índice de la fila esté dentro de los límites.
    if (fila_a_sumar < 0 || fila_a_sumar >= filas) {
        cout << "Error: La fila " << fila_a_sumar << " esta fuera de los limites validos (0 a " << filas - 1 << ").\n";
        return -1; // Retorna -1 para indicar un error.
    }

    int suma = 0;
    for (int j = 0; j < columnas; ++j) {
        suma += matriz[fila_a_sumar][j];
    }
    return suma;
}

// --- Función Principal del Ejercicio ---

void resolverEjercicio26() {
    int matriz[MAX_FILAS][MAX_COLUMNAS];
    int filas_reales, columnas_reales;
    int fila_a_sumar;
    int suma_resultante;

    // Limpiar el buffer de entrada antes del primer menú.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "\n--- Ejercicio 26: Sumar Fila Especifica de Matriz ---\n";

    // Pedir dimensiones reales de la matriz.
    filas_reales = obtenerEnteroValido(std::string("Ingrese el numero de filas (1 a " + to_string(MAX_FILAS) + "): ").c_str());
    while (filas_reales <= 0 || filas_reales > MAX_FILAS) {
        cout << "Numero de filas invalido. ";
        filas_reales = obtenerEnteroValido(std::string("Ingrese el numero de filas (1 a " + to_string(MAX_FILAS) + "): ").c_str());
    }

    columnas_reales = obtenerEnteroValido(std::string("Ingrese el numero de columnas (1 a " + to_string(MAX_COLUMNAS) + "): ").c_str());
    while (columnas_reales <= 0 || columnas_reales > MAX_COLUMNAS) {
        cout << "Numero de columnas invalido. ";
        columnas_reales = obtenerEnteroValido(std::string("Ingrese el numero de columnas (1 a " + to_string(MAX_COLUMNAS) + "): ").c_str());
    }

    // Inicializar y mostrar la matriz.
    inicializarMatriz(matriz, filas_reales, columnas_reales);
    mostrarMatriz(matriz, filas_reales, columnas_reales);

    // Pedir la fila a sumar.
    fila_a_sumar = obtenerEnteroValido(std::string("Ingrese el indice de la fila a sumar (0 a " + to_string(filas_reales - 1) + "): ").c_str());

    // Calcular y mostrar la suma.
    suma_resultante = sumarFilaEspecifica(matriz, filas_reales, columnas_reales, fila_a_sumar);

    if (suma_resultante != -1) { // Si no hubo error en el índice.
        cout << "\nLa suma de los elementos de la fila " << fila_a_sumar << " es: " << suma_resultante << ".\n";
    }
    cout << "------------------------------------------------\n";
}